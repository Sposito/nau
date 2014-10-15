#define GLI_INCLUDE_NV_TRANSFORM_FEEDBACK

enum Main {

  GL_BACK_PRIMARY_COLOR_NV                         = 0x8C77,
  GL_BACK_SECONDARY_COLOR_NV                       = 0x8C78,
  GL_TEXTURE_COORD_NV                              = 0x8C79,
  GL_CLIP_DISTANCE_NV                              = 0x8C7A,
  GL_VERTEX_ID_NV                                  = 0x8C7B,
  GL_PRIMITIVE_ID_NV                               = 0x8C7C,
  GL_GENERIC_ATTRIB_NV                             = 0x8C7D,
  GL_TRANSFORM_FEEDBACK_ATTRIBS_NV                 = 0x8C7E,
  //GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV             = 0x8C7F,
  //GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV = 0x8C80,
  GL_ACTIVE_VARYINGS_NV                            = 0x8C81,
  GL_ACTIVE_VARYING_MAX_LENGTH_NV                  = 0x8C82,
  //GL_TRANSFORM_FEEDBACK_VARYINGS_NV                = 0x8C83,
  //GL_TRANSFORM_FEEDBACK_BUFFER_START_NV            = 0x8C84,
  //GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV             = 0x8C85,
  GL_TRANSFORM_FEEDBACK_RECORD_NV                  = 0x8C86,
  //GL_PRIMITIVES_GENERATED_NV                       = 0x8C87,
  //GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV      = 0x8C88,
  //GL_RASTERIZER_DISCARD_NV                         = 0x8C89,
  //GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV  = 0x8C8A,
  //GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_ATTRIBS_NV = 0x8C8A,
  //GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV    = 0x8C8B,
  //GL_INTERLEAVED_ATTRIBS_NV                        = 0x8C8C,
  //GL_SEPARATE_ATTRIBS_NV                           = 0x8C8D,
  //GL_TRANSFORM_FEEDBACK_BUFFER_NV                  = 0x8C8E,
  //GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV          = 0x8C8F,
  GL_LAYER_NV                                        = 0x8DAA,

};

//void glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
//void glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
//void glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer);

void glTransformFeedbackAttribsNV(GLsizei count, const GLint *attribs, GLenum[Main] bufferMode);
void glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint *locations, GLenum[Main] bufferMode);
void glBeginTransformFeedbackNV(GLenum[Main] primitiveMode);
void glEndTransformFeedbackNV(void);

GLint glGetVaryingLocationNV(GLuint program,const GLchar *name);
void glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum[Main] *type, GLchar *name);
void glActiveVaryingNV(GLuint program, const GLchar *name);
void glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint *location);
void glTransformFeedbackStreamAttribsNV(GLsizei count, const GLint * attribs, GLsizei nbuffers, const GLint * bufstreams, GLenum[Main] bufferMode);
