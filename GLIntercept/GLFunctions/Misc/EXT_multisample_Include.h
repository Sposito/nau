#define GLI_INCLUDE_GL_EXT_MULTISAMPLE

enum Main {

  //GL_MULTISAMPLE_EXT                = 0x809D,
  //GL_SAMPLE_ALPHA_TO_MASK_EXT       = 0x809E,
  //GL_SAMPLE_ALPHA_TO_ONE_EXT        = 0x809F,
  //GL_SAMPLE_MASK_EXT                = 0x80A0,
  GL_1PASS_EXT                      = 0x80A1,
  GL_2PASS_0_EXT                    = 0x80A2,
  GL_2PASS_1_EXT                    = 0x80A3,
  GL_4PASS_0_EXT                    = 0x80A4,
  GL_4PASS_1_EXT                    = 0x80A5,
  GL_4PASS_2_EXT                    = 0x80A6,
  GL_4PASS_3_EXT                    = 0x80A7,
  //GL_SAMPLE_BUFFERS_EXT             = 0x80A8,
  //GL_SAMPLES_EXT                    = 0x80A9,
  //GL_SAMPLE_MASK_VALUE_EXT          = 0x80AA,
  //GL_SAMPLE_MASK_INVERT_EXT         = 0x80AB,
  GL_SAMPLE_PATTERN_EXT             = 0x80AC,
  //GL_MULTISAMPLE_BIT_EXT            = 0x20000000,

};

void glSampleMaskEXT(GLfloat value, GLboolean invert);
void glSamplePatternEXT(GLenum[Main] pattern);
