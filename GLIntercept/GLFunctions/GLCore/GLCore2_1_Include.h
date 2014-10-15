#define GLI_INCLUDE_GLCORE2_1


///////////////////////////////////////////////////////////////////////////////
// Masks
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Error enum
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Main enum
///////////////////////////////////////////////////////////////////////////////

// Main enum for all standard enums
//  (may want to break up for speed)
enum Main {

  GL_CURRENT_RASTER_SECONDARY_COLOR = 0x845F,
  GL_PIXEL_PACK_BUFFER              = 0x88EB,
  GL_PIXEL_UNPACK_BUFFER            = 0x88EC,
  GL_PIXEL_PACK_BUFFER_BINDING      = 0x88ED,
  GL_PIXEL_UNPACK_BUFFER_BINDING    = 0x88EF,
  GL_FLOAT_MAT2x3                   = 0x8B65,
  GL_FLOAT_MAT2x4                   = 0x8B66,
  GL_FLOAT_MAT3x2                   = 0x8B67,
  GL_FLOAT_MAT3x4                   = 0x8B68,
  GL_FLOAT_MAT4x2                   = 0x8B69,
  GL_FLOAT_MAT4x3                   = 0x8B6A,
  GL_SRGB                           = 0x8C40,
  GL_SRGB8                          = 0x8C41,
  GL_SRGB_ALPHA                     = 0x8C42,
  GL_SRGB8_ALPHA8                   = 0x8C43,
  GL_SLUMINANCE_ALPHA               = 0x8C44,
  GL_SLUMINANCE8_ALPHA8             = 0x8C45,
  GL_SLUMINANCE                     = 0x8C46,
  GL_SLUMINANCE8                    = 0x8C47,
  GL_COMPRESSED_SRGB                = 0x8C48,
  GL_COMPRESSED_SRGB_ALPHA          = 0x8C49,
  GL_COMPRESSED_SLUMINANCE          = 0x8C4A,
  GL_COMPRESSED_SLUMINANCE_ALPHA    = 0x8C4B,

};

///////////////////////////////////////////////////////////////////////////////
// OpenGL 2.1 functions
///////////////////////////////////////////////////////////////////////////////

void glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
