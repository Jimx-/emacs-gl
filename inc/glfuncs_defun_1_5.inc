DEFUN("gl-is-query", Fgl_is_query, 1, 1, "(gl-is-query id)\nglIsQuery.", NULL);
DEFUN("gl-begin-query", Fgl_begin_query, 2, 2, "(gl-begin-query target id)\nglBeginQuery.", NULL);
DEFUN("gl-end-query", Fgl_end_query, 1, 1, "(gl-end-query target)\nglEndQuery.", NULL);
DEFUN("gl-bind-buffer", Fgl_bind_buffer, 2, 2, "(gl-bind-buffer target buffer)\nglBindBuffer.", NULL);
DEFUN("gl-is-buffer", Fgl_is_buffer, 1, 1, "(gl-is-buffer buffer)\nglIsBuffer.", NULL);
DEFUN("gl-map-buffer", Fgl_map_buffer, 2, 2, "(gl-map-buffer target access)\nglMapBuffer.", NULL);
DEFUN("gl-unmap-buffer", Fgl_unmap_buffer, 1, 1, "(gl-unmap-buffer target)\nglUnmapBuffer.", NULL);
