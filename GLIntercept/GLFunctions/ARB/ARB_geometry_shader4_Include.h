#define GLI_INCLUDE_ARB_GEOMETRY_SHADER4

enum Main {

  //GL_GEOMETRY_SHADER_ARB                          =   0x8DD9,

  GL_GEOMETRY_VERTICES_OUT_ARB                    =   0x8DDA,
  GL_GEOMETRY_INPUT_TYPE_ARB                      =   0x8DDB,
  GL_GEOMETRY_OUTPUT_TYPE_ARB                     =   0x8DDC,

  //GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB         =   0x8C29,
  GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB          =   0x8DDD,
  GL_MAX_VERTEX_VARYING_COMPONENTS_ARB            =   0x8DDE,
  //GL_MAX_VARYING_COMPONENTS,
  //GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB          =   0x8DDF,
  //GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB             =   0x8DE0,
  //GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB     =   0x8DE1,

  //GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB     =   0x8DA8,
  GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB       =   0x8DA9,

  //GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB           =   0x8DA7,
  //GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER         =   0x8CD4,

  //GL_PROGRAM_POINT_SIZE_ARB                       =   0x8642,

};


void glProgramParameteriARB(GLuint program, GLenum[Main] pname, GLint value);
void glFramebufferTextureARB(GLenum[Main] target, GLenum[Main] attachment, GLuint texture, GLint level);
void glFramebufferTextureLayerARB(GLenum[Main] target, GLenum[Main] attachment, GLuint texture, GLint level, GLint layer);
void glFramebufferTextureFaceARB(GLenum[Main] target, GLenum[Main] attachment, GLuint texture, GLint level, GLenum[Main] face);

