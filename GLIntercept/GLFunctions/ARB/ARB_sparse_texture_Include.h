#define GLI_INCLUDE_GL_ARB_SPARSE_TEXTURE

enum Main {

  GL_TEXTURE_SPARSE_ARB                               = 0x91A6,
  GL_VIRTUAL_PAGE_SIZE_INDEX_ARB                      = 0x91A7,
  GL_MIN_SPARSE_LEVEL_ARB                             = 0x919B,
  GL_NUM_VIRTUAL_PAGE_SIZES_ARB                       = 0x91A8,
  GL_VIRTUAL_PAGE_SIZE_X_ARB                          = 0x9195,
  GL_VIRTUAL_PAGE_SIZE_Y_ARB                          = 0x9196,
  GL_VIRTUAL_PAGE_SIZE_Z_ARB                          = 0x9197,
  GL_MAX_SPARSE_TEXTURE_SIZE_ARB                      = 0x9198,
  GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB                   = 0x9199,
  GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB              = 0x919A,
  GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB       = 0x91A9,

};

void glTexPageCommitmentARB(GLenum[Main] target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean resident);
