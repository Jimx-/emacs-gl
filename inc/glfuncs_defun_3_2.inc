DEFUN("gl-provoking-vertex", Fgl_provoking_vertex, 1, 1, "(gl-provoking-vertex mode)\nglProvokingVertex.", NULL);
DEFUN("gl-fence-sync", Fgl_fence_sync, 2, 2, "(gl-fence-sync condition flags)\nglFenceSync.", NULL);
DEFUN("gl-framebuffer-texture", Fgl_framebuffer_texture, 4, 4, "(gl-framebuffer-texture target attachment texture level)\nglFramebufferTexture.", NULL);
DEFUN("gl-tex-image2-d-multisample", Fgl_tex_image2_d_multisample, 6, 6, "(gl-tex-image2-d-multisample target samples internalformat width height fixedsamplelocations)\nglTexImage2DMultisample.", NULL);
DEFUN("gl-tex-image3-d-multisample", Fgl_tex_image3_d_multisample, 7, 7, "(gl-tex-image3-d-multisample target samples internalformat width height depth fixedsamplelocations)\nglTexImage3DMultisample.", NULL);
DEFUN("gl-sample-maski", Fgl_sample_maski, 2, 2, "(gl-sample-maski maskNumber mask)\nglSampleMaski.", NULL);
