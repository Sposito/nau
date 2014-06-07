/*=============================================================================
  GLIntercept - OpenGL intercept/debugging tool
  Copyright (C) 2004  Damian Trebilco

  Licensed under the MIT license - See Docs\license.txt for details.
=============================================================================*/
#include "ExtensionFunction.h"
#include "GLDriver.h"
#include <stdarg.h>

//The driver to log calls by
extern GLDriver glDriver;

USING_ERRORLOG

//NOTE: This implementation is OS/Platform specific 
#include "ExtensionFunctionStubs.cpp"

extern "C" {
  void * extFunctions[MAX_WRAPPER_FUNCTIONS] HIDDEN;
  uint   wrapperIndex[MAX_WRAPPER_FUNCTIONS] HIDDEN;
}

///////////////////////////////////////////////////////////////////////////////
//
ExtensionFunction::ExtensionFunction(FunctionTable * functionTable):
currExtensionIndex(0),
functionTable(functionTable),
manualFuncWrap(functionTable)
{
	overrideIndexList.clear();
	overrideCurrIndexList.clear();
	overrideMustDeleteList.clear();
}

///////////////////////////////////////////////////////////////////////////////
//
ExtensionFunction::~ExtensionFunction()
{
}

//Plugins often add Overrides which should be removed if
//the plugin is removed
void ExtensionFunction::removeOverrides(){
    int removedExtensionsCount = 0;
	for (int i=overrideIndexList.size()-1;i>=0; i--){
	    //Uses the list containing the plugin added overrides;
	    //these must be deleted
        if (overrideMustDeleteList[i]){
            removedExtensionsCount++;
            //Removes override from function table
            functionTable->RemoveFunction(overrideIndexList[i]);
            //Removes the override from the real list
            //reorganizes the list (inneficient) but
            //it's fine since this function isn't used often
			for (int j=overrideCurrIndexList[i]; j<currExtensionIndex-1; j++){
				wrapperIndex[j]=wrapperIndex[j+1]-1;
				extFunctions[j]=extFunctions[j+1];
			}
		}
		else{
            //Fixes the pointer for the overrided function
            //if not deleted
			const FunctionData *foundFunc = functionTable->GetFunctionData(overrideIndexList[i]);
            *foundFunc->internalFunctionDataPtr = (void**)overrideCurrIndexList[i];
		}
	}
	currExtensionIndex -= removedExtensionsCount;
	overrideIndexList.clear();
	overrideCurrIndexList.clear();
	overrideMustDeleteList.clear();
}
///////////////////////////////////////////////////////////////////////////////
//
void * ExtensionFunction::AddFunction(const string & funcName,void * functionPtr)
{

  //Check for an existing function of that name
  int funcIndex = functionTable->FindFunction(funcName);
  if(funcIndex != -1)
  {

#ifdef GLI_BUILD_WINDOWS

    //Sanity check for multiple different lookups 
    // (only built-in functions on Windows are valid on multiple contexts)
    if(!functionTable->GetFunctionData(funcIndex)->IsFlagSet(FDF_BUILT_IN) &&
       functionTable->GetFunctionData(funcIndex)->origionalInternalPtr != functionPtr)
    {
      //Log an error if there is a current context
      if(glDriver.GetCurrentContext() != NULL && functionPtr != NULL)
      {
        LOGERR(("ExtensionFunction::AddFunction - Function %s does not match previous lookup (multiple OpenGL devices?)",funcName.c_str()));
      }

      //Just return the "new" pointer
      return functionPtr;
    }

#endif //GLI_BUILD_WINDOWS

    //Get the function pointer to return
    return functionTable->GetFunctionData(funcIndex)->wrappedFunctionPtr;
  }

  //Catch bad function lookups 
  if(functionPtr == NULL)
  {
    return NULL;
  }

  // Attempt a manual wrap
  void *retPtr = manualFuncWrap.AddFunctionWrap(funcName, functionPtr);
  if(retPtr)
  {
    return retPtr;
  }

  //Check if we can add another extension function
  if(currExtensionIndex >= MAX_WRAPPER_FUNCTIONS)
  {
    //LOG an error
    LOGERR(("ExtensionFunction::AddFunction -Unable to log function %s exceeded %u num of wrapper functions",funcName.c_str(),(uint)MAX_WRAPPER_FUNCTIONS));

    //Else just return the pointer
    return functionPtr;
  }

  //Get the next available wrapper
  retPtr = (void*)wrapperFunctions[currExtensionIndex];
  
  //Add the data to the table and get the index
  funcIndex = functionTable->AddFunction(funcName,retPtr,functionPtr,&extFunctions[currExtensionIndex],false);

  //Assign the index to the lookup table
  wrapperIndex[currExtensionIndex] = funcIndex;
  extFunctions[currExtensionIndex] = functionPtr;

  //Increment the wrapper counter
  currExtensionIndex++;

  //Return the wrapper pointer
  return retPtr;
}


///////////////////////////////////////////////////////////////////////////////
//
bool ExtensionFunction::AddOverrideFunction(const string & funcName, void * overrideFunctionPtr, void *origFuncPtr)
{
  //Check in incomming pointer
  if(overrideFunctionPtr == NULL)
  {
    return false;
  }

  //Check for an existing function of that name
  int funcIndex = functionTable->FindFunction(funcName);
  if(funcIndex != -1)
  {
    const FunctionData *foundFunc = functionTable->GetFunctionData(funcIndex);

#ifdef GLI_BUILD_WINDOWS

    //Sanity check for multiple different lookups
    if(foundFunc->origionalInternalPtr != origFuncPtr)
    {
      LOGERR(("ExtensionFunction::AddOverrideFunction - Function %s does not have the same internal lookup value",funcName.c_str()));
      return false;
    }

#endif //GLI_BUILD_WINDOWS

    //Check if an override already exists
    if(foundFunc->origionalInternalPtr != *foundFunc->internalFunctionDataPtr)
    {
      LOGERR(("ExtensionFunction::AddOverrideFunction - Function %s already has an override",funcName.c_str()));
      return false;
    }
	
    overrideIndexList.push_back(funcIndex);
    overrideCurrIndexList.push_back((int)*foundFunc->internalFunctionDataPtr);
    overrideMustDeleteList.push_back(false);

    //Assign the override
    *foundFunc->internalFunctionDataPtr = overrideFunctionPtr;
    return true;
  }

  //If this is a new function, generate a wrapper around the override

  //Check if we can add another extension function
  if(currExtensionIndex >= MAX_WRAPPER_FUNCTIONS)
  {
    LOGERR(("ExtensionFunction::AddOverrideFunction -Unable to override function %s exceeded %u num of wrapper functions",funcName.c_str(),(uint)MAX_WRAPPER_FUNCTIONS));
    return false;
  }

  //Get the next available wrapper
  void *retPtr = (void*)wrapperFunctions[currExtensionIndex];
  
  //Add the data to the table and get the index
  funcIndex = functionTable->AddFunction(funcName,retPtr,origFuncPtr,&extFunctions[currExtensionIndex],false);

  //Assign the index to the lookup table
  wrapperIndex[currExtensionIndex] = funcIndex;
  extFunctions[currExtensionIndex] = overrideFunctionPtr; //NOTE: Assigning override function here
  
  overrideIndexList.push_back(funcIndex);
  overrideCurrIndexList.push_back(currExtensionIndex);
  overrideMustDeleteList.push_back(true);

  //Increment the wrapper counter
  currExtensionIndex++;

  return true;
}









