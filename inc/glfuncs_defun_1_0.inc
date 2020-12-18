DEFUN("gl-cull-face", Fgl_cull_face, 1, 1, "(gl-cull-face mode)\nglCullFace.", NULL);
DEFUN("gl-front-face", Fgl_front_face, 1, 1, "(gl-front-face mode)\nglFrontFace.", NULL);
DEFUN("gl-hint", Fgl_hint, 2, 2, "(gl-hint target mode)\nglHint.", NULL);
DEFUN("gl-line-width", Fgl_line_width, 1, 1, "(gl-line-width width)\nglLineWidth.", NULL);
DEFUN("gl-point-size", Fgl_point_size, 1, 1, "(gl-point-size size)\nglPointSize.", NULL);
DEFUN("gl-polygon-mode", Fgl_polygon_mode, 2, 2, "(gl-polygon-mode face mode)\nglPolygonMode.", NULL);
DEFUN("gl-scissor", Fgl_scissor, 4, 4, "(gl-scissor x y width height)\nglScissor.", NULL);
DEFUN("gl-tex-parameterf", Fgl_tex_parameterf, 3, 3, "(gl-tex-parameterf target pname param)\nglTexParameterf.", NULL);
DEFUN("gl-tex-parameteri", Fgl_tex_parameteri, 3, 3, "(gl-tex-parameteri target pname param)\nglTexParameteri.", NULL);
DEFUN("gl-draw-buffer", Fgl_draw_buffer, 1, 1, "(gl-draw-buffer buf)\nglDrawBuffer.", NULL);
DEFUN("gl-clear", Fgl_clear, 1, 1, "(gl-clear mask)\nglClear.", NULL);
DEFUN("gl-clear-color", Fgl_clear_color, 4, 4, "(gl-clear-color red green blue alpha)\nglClearColor.", NULL);
DEFUN("gl-clear-stencil", Fgl_clear_stencil, 1, 1, "(gl-clear-stencil s)\nglClearStencil.", NULL);
DEFUN("gl-clear-depth", Fgl_clear_depth, 1, 1, "(gl-clear-depth depth)\nglClearDepth.", NULL);
DEFUN("gl-stencil-mask", Fgl_stencil_mask, 1, 1, "(gl-stencil-mask mask)\nglStencilMask.", NULL);
DEFUN("gl-color-mask", Fgl_color_mask, 4, 4, "(gl-color-mask red green blue alpha)\nglColorMask.", NULL);
DEFUN("gl-depth-mask", Fgl_depth_mask, 1, 1, "(gl-depth-mask flag)\nglDepthMask.", NULL);
DEFUN("gl-disable", Fgl_disable, 1, 1, "(gl-disable cap)\nglDisable.", NULL);
DEFUN("gl-enable", Fgl_enable, 1, 1, "(gl-enable cap)\nglEnable.", NULL);
DEFUN("gl-finish", Fgl_finish, 0, 0, "(gl-finish )\nglFinish.", NULL);
DEFUN("gl-flush", Fgl_flush, 0, 0, "(gl-flush )\nglFlush.", NULL);
DEFUN("gl-blend-func", Fgl_blend_func, 2, 2, "(gl-blend-func sfactor dfactor)\nglBlendFunc.", NULL);
DEFUN("gl-logic-op", Fgl_logic_op, 1, 1, "(gl-logic-op opcode)\nglLogicOp.", NULL);
DEFUN("gl-stencil-func", Fgl_stencil_func, 3, 3, "(gl-stencil-func func ref mask)\nglStencilFunc.", NULL);
DEFUN("gl-stencil-op", Fgl_stencil_op, 3, 3, "(gl-stencil-op fail zfail zpass)\nglStencilOp.", NULL);
DEFUN("gl-depth-func", Fgl_depth_func, 1, 1, "(gl-depth-func func)\nglDepthFunc.", NULL);
DEFUN("gl-pixel-storef", Fgl_pixel_storef, 2, 2, "(gl-pixel-storef pname param)\nglPixelStoref.", NULL);
DEFUN("gl-pixel-storei", Fgl_pixel_storei, 2, 2, "(gl-pixel-storei pname param)\nglPixelStorei.", NULL);
DEFUN("gl-read-buffer", Fgl_read_buffer, 1, 1, "(gl-read-buffer src)\nglReadBuffer.", NULL);
DEFUN("gl-get-error", Fgl_get_error, 0, 0, "(gl-get-error )\nglGetError.", NULL);
DEFUN("gl-get-string", Fgl_get_string, 1, 1, "(gl-get-string name)\nglGetString.", NULL);
DEFUN("gl-is-enabled", Fgl_is_enabled, 1, 1, "(gl-is-enabled cap)\nglIsEnabled.", NULL);
DEFUN("gl-depth-range", Fgl_depth_range, 2, 2, "(gl-depth-range n f)\nglDepthRange.", NULL);
DEFUN("gl-viewport", Fgl_viewport, 4, 4, "(gl-viewport x y width height)\nglViewport.", NULL);
DEFUN("gl-new-list", Fgl_new_list, 2, 2, "(gl-new-list list mode)\nglNewList.", NULL);
DEFUN("gl-end-list", Fgl_end_list, 0, 0, "(gl-end-list )\nglEndList.", NULL);
DEFUN("gl-call-list", Fgl_call_list, 1, 1, "(gl-call-list list)\nglCallList.", NULL);
DEFUN("gl-delete-lists", Fgl_delete_lists, 2, 2, "(gl-delete-lists list range)\nglDeleteLists.", NULL);
DEFUN("gl-gen-lists", Fgl_gen_lists, 1, 1, "(gl-gen-lists range)\nglGenLists.", NULL);
DEFUN("gl-list-base", Fgl_list_base, 1, 1, "(gl-list-base base)\nglListBase.", NULL);
DEFUN("gl-begin", Fgl_begin, 1, 1, "(gl-begin mode)\nglBegin.", NULL);
DEFUN("gl-color3b", Fgl_color3b, 3, 3, "(gl-color3b red green blue)\nglColor3b.", NULL);
DEFUN("gl-color3d", Fgl_color3d, 3, 3, "(gl-color3d red green blue)\nglColor3d.", NULL);
DEFUN("gl-color3f", Fgl_color3f, 3, 3, "(gl-color3f red green blue)\nglColor3f.", NULL);
DEFUN("gl-color3i", Fgl_color3i, 3, 3, "(gl-color3i red green blue)\nglColor3i.", NULL);
DEFUN("gl-color3s", Fgl_color3s, 3, 3, "(gl-color3s red green blue)\nglColor3s.", NULL);
DEFUN("gl-color3ub", Fgl_color3ub, 3, 3, "(gl-color3ub red green blue)\nglColor3ub.", NULL);
DEFUN("gl-color3ui", Fgl_color3ui, 3, 3, "(gl-color3ui red green blue)\nglColor3ui.", NULL);
DEFUN("gl-color3us", Fgl_color3us, 3, 3, "(gl-color3us red green blue)\nglColor3us.", NULL);
DEFUN("gl-color4b", Fgl_color4b, 4, 4, "(gl-color4b red green blue alpha)\nglColor4b.", NULL);
DEFUN("gl-color4d", Fgl_color4d, 4, 4, "(gl-color4d red green blue alpha)\nglColor4d.", NULL);
DEFUN("gl-color4f", Fgl_color4f, 4, 4, "(gl-color4f red green blue alpha)\nglColor4f.", NULL);
DEFUN("gl-color4i", Fgl_color4i, 4, 4, "(gl-color4i red green blue alpha)\nglColor4i.", NULL);
DEFUN("gl-color4s", Fgl_color4s, 4, 4, "(gl-color4s red green blue alpha)\nglColor4s.", NULL);
DEFUN("gl-color4ub", Fgl_color4ub, 4, 4, "(gl-color4ub red green blue alpha)\nglColor4ub.", NULL);
DEFUN("gl-color4ui", Fgl_color4ui, 4, 4, "(gl-color4ui red green blue alpha)\nglColor4ui.", NULL);
DEFUN("gl-color4us", Fgl_color4us, 4, 4, "(gl-color4us red green blue alpha)\nglColor4us.", NULL);
DEFUN("gl-edge-flag", Fgl_edge_flag, 1, 1, "(gl-edge-flag flag)\nglEdgeFlag.", NULL);
DEFUN("gl-end", Fgl_end, 0, 0, "(gl-end )\nglEnd.", NULL);
DEFUN("gl-indexd", Fgl_indexd, 1, 1, "(gl-indexd c)\nglIndexd.", NULL);
DEFUN("gl-indexf", Fgl_indexf, 1, 1, "(gl-indexf c)\nglIndexf.", NULL);
DEFUN("gl-indexi", Fgl_indexi, 1, 1, "(gl-indexi c)\nglIndexi.", NULL);
DEFUN("gl-indexs", Fgl_indexs, 1, 1, "(gl-indexs c)\nglIndexs.", NULL);
DEFUN("gl-normal3b", Fgl_normal3b, 3, 3, "(gl-normal3b nx ny nz)\nglNormal3b.", NULL);
DEFUN("gl-normal3d", Fgl_normal3d, 3, 3, "(gl-normal3d nx ny nz)\nglNormal3d.", NULL);
DEFUN("gl-normal3f", Fgl_normal3f, 3, 3, "(gl-normal3f nx ny nz)\nglNormal3f.", NULL);
DEFUN("gl-normal3i", Fgl_normal3i, 3, 3, "(gl-normal3i nx ny nz)\nglNormal3i.", NULL);
DEFUN("gl-normal3s", Fgl_normal3s, 3, 3, "(gl-normal3s nx ny nz)\nglNormal3s.", NULL);
DEFUN("gl-raster-pos2d", Fgl_raster_pos2d, 2, 2, "(gl-raster-pos2d x y)\nglRasterPos2d.", NULL);
DEFUN("gl-raster-pos2f", Fgl_raster_pos2f, 2, 2, "(gl-raster-pos2f x y)\nglRasterPos2f.", NULL);
DEFUN("gl-raster-pos2i", Fgl_raster_pos2i, 2, 2, "(gl-raster-pos2i x y)\nglRasterPos2i.", NULL);
DEFUN("gl-raster-pos2s", Fgl_raster_pos2s, 2, 2, "(gl-raster-pos2s x y)\nglRasterPos2s.", NULL);
DEFUN("gl-raster-pos3d", Fgl_raster_pos3d, 3, 3, "(gl-raster-pos3d x y z)\nglRasterPos3d.", NULL);
DEFUN("gl-raster-pos3f", Fgl_raster_pos3f, 3, 3, "(gl-raster-pos3f x y z)\nglRasterPos3f.", NULL);
DEFUN("gl-raster-pos3i", Fgl_raster_pos3i, 3, 3, "(gl-raster-pos3i x y z)\nglRasterPos3i.", NULL);
DEFUN("gl-raster-pos3s", Fgl_raster_pos3s, 3, 3, "(gl-raster-pos3s x y z)\nglRasterPos3s.", NULL);
DEFUN("gl-raster-pos4d", Fgl_raster_pos4d, 4, 4, "(gl-raster-pos4d x y z w)\nglRasterPos4d.", NULL);
DEFUN("gl-raster-pos4f", Fgl_raster_pos4f, 4, 4, "(gl-raster-pos4f x y z w)\nglRasterPos4f.", NULL);
DEFUN("gl-raster-pos4i", Fgl_raster_pos4i, 4, 4, "(gl-raster-pos4i x y z w)\nglRasterPos4i.", NULL);
DEFUN("gl-raster-pos4s", Fgl_raster_pos4s, 4, 4, "(gl-raster-pos4s x y z w)\nglRasterPos4s.", NULL);
DEFUN("gl-rectd", Fgl_rectd, 4, 4, "(gl-rectd x1 y1 x2 y2)\nglRectd.", NULL);
DEFUN("gl-rectf", Fgl_rectf, 4, 4, "(gl-rectf x1 y1 x2 y2)\nglRectf.", NULL);
DEFUN("gl-recti", Fgl_recti, 4, 4, "(gl-recti x1 y1 x2 y2)\nglRecti.", NULL);
DEFUN("gl-rects", Fgl_rects, 4, 4, "(gl-rects x1 y1 x2 y2)\nglRects.", NULL);
DEFUN("gl-tex-coord1d", Fgl_tex_coord1d, 1, 1, "(gl-tex-coord1d s)\nglTexCoord1d.", NULL);
DEFUN("gl-tex-coord1f", Fgl_tex_coord1f, 1, 1, "(gl-tex-coord1f s)\nglTexCoord1f.", NULL);
DEFUN("gl-tex-coord1i", Fgl_tex_coord1i, 1, 1, "(gl-tex-coord1i s)\nglTexCoord1i.", NULL);
DEFUN("gl-tex-coord1s", Fgl_tex_coord1s, 1, 1, "(gl-tex-coord1s s)\nglTexCoord1s.", NULL);
DEFUN("gl-tex-coord2d", Fgl_tex_coord2d, 2, 2, "(gl-tex-coord2d s t)\nglTexCoord2d.", NULL);
DEFUN("gl-tex-coord2f", Fgl_tex_coord2f, 2, 2, "(gl-tex-coord2f s t)\nglTexCoord2f.", NULL);
DEFUN("gl-tex-coord2i", Fgl_tex_coord2i, 2, 2, "(gl-tex-coord2i s t)\nglTexCoord2i.", NULL);
DEFUN("gl-tex-coord2s", Fgl_tex_coord2s, 2, 2, "(gl-tex-coord2s s t)\nglTexCoord2s.", NULL);
DEFUN("gl-tex-coord3d", Fgl_tex_coord3d, 3, 3, "(gl-tex-coord3d s t r)\nglTexCoord3d.", NULL);
DEFUN("gl-tex-coord3f", Fgl_tex_coord3f, 3, 3, "(gl-tex-coord3f s t r)\nglTexCoord3f.", NULL);
DEFUN("gl-tex-coord3i", Fgl_tex_coord3i, 3, 3, "(gl-tex-coord3i s t r)\nglTexCoord3i.", NULL);
DEFUN("gl-tex-coord3s", Fgl_tex_coord3s, 3, 3, "(gl-tex-coord3s s t r)\nglTexCoord3s.", NULL);
DEFUN("gl-tex-coord4d", Fgl_tex_coord4d, 4, 4, "(gl-tex-coord4d s t r q)\nglTexCoord4d.", NULL);
DEFUN("gl-tex-coord4f", Fgl_tex_coord4f, 4, 4, "(gl-tex-coord4f s t r q)\nglTexCoord4f.", NULL);
DEFUN("gl-tex-coord4i", Fgl_tex_coord4i, 4, 4, "(gl-tex-coord4i s t r q)\nglTexCoord4i.", NULL);
DEFUN("gl-tex-coord4s", Fgl_tex_coord4s, 4, 4, "(gl-tex-coord4s s t r q)\nglTexCoord4s.", NULL);
DEFUN("gl-vertex2d", Fgl_vertex2d, 2, 2, "(gl-vertex2d x y)\nglVertex2d.", NULL);
DEFUN("gl-vertex2f", Fgl_vertex2f, 2, 2, "(gl-vertex2f x y)\nglVertex2f.", NULL);
DEFUN("gl-vertex2i", Fgl_vertex2i, 2, 2, "(gl-vertex2i x y)\nglVertex2i.", NULL);
DEFUN("gl-vertex2s", Fgl_vertex2s, 2, 2, "(gl-vertex2s x y)\nglVertex2s.", NULL);
DEFUN("gl-vertex3d", Fgl_vertex3d, 3, 3, "(gl-vertex3d x y z)\nglVertex3d.", NULL);
DEFUN("gl-vertex3f", Fgl_vertex3f, 3, 3, "(gl-vertex3f x y z)\nglVertex3f.", NULL);
DEFUN("gl-vertex3i", Fgl_vertex3i, 3, 3, "(gl-vertex3i x y z)\nglVertex3i.", NULL);
DEFUN("gl-vertex3s", Fgl_vertex3s, 3, 3, "(gl-vertex3s x y z)\nglVertex3s.", NULL);
DEFUN("gl-vertex4d", Fgl_vertex4d, 4, 4, "(gl-vertex4d x y z w)\nglVertex4d.", NULL);
DEFUN("gl-vertex4f", Fgl_vertex4f, 4, 4, "(gl-vertex4f x y z w)\nglVertex4f.", NULL);
DEFUN("gl-vertex4i", Fgl_vertex4i, 4, 4, "(gl-vertex4i x y z w)\nglVertex4i.", NULL);
DEFUN("gl-vertex4s", Fgl_vertex4s, 4, 4, "(gl-vertex4s x y z w)\nglVertex4s.", NULL);
DEFUN("gl-color-material", Fgl_color_material, 2, 2, "(gl-color-material face mode)\nglColorMaterial.", NULL);
DEFUN("gl-fogf", Fgl_fogf, 2, 2, "(gl-fogf pname param)\nglFogf.", NULL);
DEFUN("gl-fogi", Fgl_fogi, 2, 2, "(gl-fogi pname param)\nglFogi.", NULL);
DEFUN("gl-lightf", Fgl_lightf, 3, 3, "(gl-lightf light pname param)\nglLightf.", NULL);
DEFUN("gl-lighti", Fgl_lighti, 3, 3, "(gl-lighti light pname param)\nglLighti.", NULL);
DEFUN("gl-light-modelf", Fgl_light_modelf, 2, 2, "(gl-light-modelf pname param)\nglLightModelf.", NULL);
DEFUN("gl-light-modeli", Fgl_light_modeli, 2, 2, "(gl-light-modeli pname param)\nglLightModeli.", NULL);
DEFUN("gl-line-stipple", Fgl_line_stipple, 2, 2, "(gl-line-stipple factor pattern)\nglLineStipple.", NULL);
DEFUN("gl-materialf", Fgl_materialf, 3, 3, "(gl-materialf face pname param)\nglMaterialf.", NULL);
DEFUN("gl-materiali", Fgl_materiali, 3, 3, "(gl-materiali face pname param)\nglMateriali.", NULL);
DEFUN("gl-shade-model", Fgl_shade_model, 1, 1, "(gl-shade-model mode)\nglShadeModel.", NULL);
DEFUN("gl-tex-envf", Fgl_tex_envf, 3, 3, "(gl-tex-envf target pname param)\nglTexEnvf.", NULL);
DEFUN("gl-tex-envi", Fgl_tex_envi, 3, 3, "(gl-tex-envi target pname param)\nglTexEnvi.", NULL);
DEFUN("gl-tex-gend", Fgl_tex_gend, 3, 3, "(gl-tex-gend coord pname param)\nglTexGend.", NULL);
DEFUN("gl-tex-genf", Fgl_tex_genf, 3, 3, "(gl-tex-genf coord pname param)\nglTexGenf.", NULL);
DEFUN("gl-tex-geni", Fgl_tex_geni, 3, 3, "(gl-tex-geni coord pname param)\nglTexGeni.", NULL);
DEFUN("gl-render-mode", Fgl_render_mode, 1, 1, "(gl-render-mode mode)\nglRenderMode.", NULL);
DEFUN("gl-init-names", Fgl_init_names, 0, 0, "(gl-init-names )\nglInitNames.", NULL);
DEFUN("gl-load-name", Fgl_load_name, 1, 1, "(gl-load-name name)\nglLoadName.", NULL);
DEFUN("gl-pass-through", Fgl_pass_through, 1, 1, "(gl-pass-through token)\nglPassThrough.", NULL);
DEFUN("gl-pop-name", Fgl_pop_name, 0, 0, "(gl-pop-name )\nglPopName.", NULL);
DEFUN("gl-push-name", Fgl_push_name, 1, 1, "(gl-push-name name)\nglPushName.", NULL);
DEFUN("gl-clear-accum", Fgl_clear_accum, 4, 4, "(gl-clear-accum red green blue alpha)\nglClearAccum.", NULL);
DEFUN("gl-clear-index", Fgl_clear_index, 1, 1, "(gl-clear-index c)\nglClearIndex.", NULL);
DEFUN("gl-index-mask", Fgl_index_mask, 1, 1, "(gl-index-mask mask)\nglIndexMask.", NULL);
DEFUN("gl-accum", Fgl_accum, 2, 2, "(gl-accum op value)\nglAccum.", NULL);
DEFUN("gl-pop-attrib", Fgl_pop_attrib, 0, 0, "(gl-pop-attrib )\nglPopAttrib.", NULL);
DEFUN("gl-push-attrib", Fgl_push_attrib, 1, 1, "(gl-push-attrib mask)\nglPushAttrib.", NULL);
DEFUN("gl-map-grid1d", Fgl_map_grid1d, 3, 3, "(gl-map-grid1d un u1 u2)\nglMapGrid1d.", NULL);
DEFUN("gl-map-grid1f", Fgl_map_grid1f, 3, 3, "(gl-map-grid1f un u1 u2)\nglMapGrid1f.", NULL);
DEFUN("gl-map-grid2d", Fgl_map_grid2d, 6, 6, "(gl-map-grid2d un u1 u2 vn v1 v2)\nglMapGrid2d.", NULL);
DEFUN("gl-map-grid2f", Fgl_map_grid2f, 6, 6, "(gl-map-grid2f un u1 u2 vn v1 v2)\nglMapGrid2f.", NULL);
DEFUN("gl-eval-coord1d", Fgl_eval_coord1d, 1, 1, "(gl-eval-coord1d u)\nglEvalCoord1d.", NULL);
DEFUN("gl-eval-coord1f", Fgl_eval_coord1f, 1, 1, "(gl-eval-coord1f u)\nglEvalCoord1f.", NULL);
DEFUN("gl-eval-coord2d", Fgl_eval_coord2d, 2, 2, "(gl-eval-coord2d u v)\nglEvalCoord2d.", NULL);
DEFUN("gl-eval-coord2f", Fgl_eval_coord2f, 2, 2, "(gl-eval-coord2f u v)\nglEvalCoord2f.", NULL);
DEFUN("gl-eval-mesh1", Fgl_eval_mesh1, 3, 3, "(gl-eval-mesh1 mode i1 i2)\nglEvalMesh1.", NULL);
DEFUN("gl-eval-point1", Fgl_eval_point1, 1, 1, "(gl-eval-point1 i)\nglEvalPoint1.", NULL);
DEFUN("gl-eval-mesh2", Fgl_eval_mesh2, 5, 5, "(gl-eval-mesh2 mode i1 i2 j1 j2)\nglEvalMesh2.", NULL);
DEFUN("gl-eval-point2", Fgl_eval_point2, 2, 2, "(gl-eval-point2 i j)\nglEvalPoint2.", NULL);
DEFUN("gl-alpha-func", Fgl_alpha_func, 2, 2, "(gl-alpha-func func ref)\nglAlphaFunc.", NULL);
DEFUN("gl-pixel-zoom", Fgl_pixel_zoom, 2, 2, "(gl-pixel-zoom xfactor yfactor)\nglPixelZoom.", NULL);
DEFUN("gl-pixel-transferf", Fgl_pixel_transferf, 2, 2, "(gl-pixel-transferf pname param)\nglPixelTransferf.", NULL);
DEFUN("gl-pixel-transferi", Fgl_pixel_transferi, 2, 2, "(gl-pixel-transferi pname param)\nglPixelTransferi.", NULL);
DEFUN("gl-copy-pixels", Fgl_copy_pixels, 5, 5, "(gl-copy-pixels x y width height type)\nglCopyPixels.", NULL);
DEFUN("gl-is-list", Fgl_is_list, 1, 1, "(gl-is-list list)\nglIsList.", NULL);
DEFUN("gl-frustum", Fgl_frustum, 6, 6, "(gl-frustum left right bottom top zNear zFar)\nglFrustum.", NULL);
DEFUN("gl-load-identity", Fgl_load_identity, 0, 0, "(gl-load-identity )\nglLoadIdentity.", NULL);
DEFUN("gl-matrix-mode", Fgl_matrix_mode, 1, 1, "(gl-matrix-mode mode)\nglMatrixMode.", NULL);
DEFUN("gl-ortho", Fgl_ortho, 6, 6, "(gl-ortho left right bottom top zNear zFar)\nglOrtho.", NULL);
DEFUN("gl-pop-matrix", Fgl_pop_matrix, 0, 0, "(gl-pop-matrix )\nglPopMatrix.", NULL);
DEFUN("gl-push-matrix", Fgl_push_matrix, 0, 0, "(gl-push-matrix )\nglPushMatrix.", NULL);
DEFUN("gl-rotated", Fgl_rotated, 4, 4, "(gl-rotated angle x y z)\nglRotated.", NULL);
DEFUN("gl-rotatef", Fgl_rotatef, 4, 4, "(gl-rotatef angle x y z)\nglRotatef.", NULL);
DEFUN("gl-scaled", Fgl_scaled, 3, 3, "(gl-scaled x y z)\nglScaled.", NULL);
DEFUN("gl-scalef", Fgl_scalef, 3, 3, "(gl-scalef x y z)\nglScalef.", NULL);
DEFUN("gl-translated", Fgl_translated, 3, 3, "(gl-translated x y z)\nglTranslated.", NULL);
DEFUN("gl-translatef", Fgl_translatef, 3, 3, "(gl-translatef x y z)\nglTranslatef.", NULL);