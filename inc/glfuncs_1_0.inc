emacs_value Fgl_cull_face(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glCullFace(mode);
	return Qnil;
}

emacs_value Fgl_front_face(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glFrontFace(mode);
	return Qnil;
}

emacs_value Fgl_hint(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum mode = extract_integer(env, args[1]);
	glHint(target, mode);
	return Qnil;
}

emacs_value Fgl_line_width(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat width = extract_double(env, args[0]);
	glLineWidth(width);
	return Qnil;
}

emacs_value Fgl_point_size(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat size = extract_double(env, args[0]);
	glPointSize(size);
	return Qnil;
}

emacs_value Fgl_polygon_mode(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum face = extract_integer(env, args[0]);
	GLenum mode = extract_integer(env, args[1]);
	glPolygonMode(face, mode);
	return Qnil;
}

emacs_value Fgl_scissor(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLsizei width = extract_integer(env, args[2]);
	GLsizei height = extract_integer(env, args[3]);
	glScissor(x, y, width, height);
	return Qnil;
}

emacs_value Fgl_tex_parameterf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLfloat param = extract_double(env, args[2]);
	glTexParameterf(target, pname, param);
	return Qnil;
}

emacs_value Fgl_tex_parameteri(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint param = extract_integer(env, args[2]);
	glTexParameteri(target, pname, param);
	return Qnil;
}

emacs_value Fgl_draw_buffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum buf = extract_integer(env, args[0]);
	glDrawBuffer(buf);
	return Qnil;
}

emacs_value Fgl_clear(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbitfield mask = extract_integer(env, args[0]);
	glClear(mask);
	return Qnil;
}

emacs_value Fgl_clear_color(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	GLfloat alpha = extract_double(env, args[3]);
	glClearColor(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_clear_stencil(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint s = extract_integer(env, args[0]);
	glClearStencil(s);
	return Qnil;
}

emacs_value Fgl_clear_depth(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble depth = extract_double(env, args[0]);
	glClearDepth(depth);
	return Qnil;
}

emacs_value Fgl_stencil_mask(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint mask = extract_integer(env, args[0]);
	glStencilMask(mask);
	return Qnil;
}

emacs_value Fgl_color_mask(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLboolean red = extract_integer(env, args[0]);
	GLboolean green = extract_integer(env, args[1]);
	GLboolean blue = extract_integer(env, args[2]);
	GLboolean alpha = extract_integer(env, args[3]);
	glColorMask(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_depth_mask(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLboolean flag = extract_integer(env, args[0]);
	glDepthMask(flag);
	return Qnil;
}

emacs_value Fgl_disable(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum cap = extract_integer(env, args[0]);
	glDisable(cap);
	return Qnil;
}

emacs_value Fgl_enable(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum cap = extract_integer(env, args[0]);
	glEnable(cap);
	return Qnil;
}

emacs_value Fgl_finish(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glFinish();
	return Qnil;
}

emacs_value Fgl_flush(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glFlush();
	return Qnil;
}

emacs_value Fgl_blend_func(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum sfactor = extract_integer(env, args[0]);
	GLenum dfactor = extract_integer(env, args[1]);
	glBlendFunc(sfactor, dfactor);
	return Qnil;
}

emacs_value Fgl_logic_op(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum opcode = extract_integer(env, args[0]);
	glLogicOp(opcode);
	return Qnil;
}

emacs_value Fgl_stencil_func(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum func = extract_integer(env, args[0]);
	GLint ref = extract_integer(env, args[1]);
	GLuint mask = extract_integer(env, args[2]);
	glStencilFunc(func, ref, mask);
	return Qnil;
}

emacs_value Fgl_stencil_op(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum fail = extract_integer(env, args[0]);
	GLenum zfail = extract_integer(env, args[1]);
	GLenum zpass = extract_integer(env, args[2]);
	glStencilOp(fail, zfail, zpass);
	return Qnil;
}

emacs_value Fgl_depth_func(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum func = extract_integer(env, args[0]);
	glDepthFunc(func);
	return Qnil;
}

emacs_value Fgl_pixel_storef(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLfloat param = extract_double(env, args[1]);
	glPixelStoref(pname, param);
	return Qnil;
}

emacs_value Fgl_pixel_storei(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLint param = extract_integer(env, args[1]);
	glPixelStorei(pname, param);
	return Qnil;
}

emacs_value Fgl_read_buffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum src = extract_integer(env, args[0]);
	glReadBuffer(src);
	return Qnil;
}

emacs_value Fgl_get_error(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glGetError();
	return Qnil;
}

emacs_value Fgl_get_string(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum name = extract_integer(env, args[0]);
	glGetString(name);
	return Qnil;
}

emacs_value Fgl_is_enabled(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum cap = extract_integer(env, args[0]);
	glIsEnabled(cap);
	return Qnil;
}

emacs_value Fgl_depth_range(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble n = extract_double(env, args[0]);
	GLdouble f = extract_double(env, args[1]);
	glDepthRange(n, f);
	return Qnil;
}

emacs_value Fgl_viewport(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLsizei width = extract_integer(env, args[2]);
	GLsizei height = extract_integer(env, args[3]);
	glViewport(x, y, width, height);
	return Qnil;
}

emacs_value Fgl_new_list(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint list = extract_integer(env, args[0]);
	GLenum mode = extract_integer(env, args[1]);
	glNewList(list, mode);
	return Qnil;
}

emacs_value Fgl_end_list(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glEndList();
	return Qnil;
}

emacs_value Fgl_call_list(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint list = extract_integer(env, args[0]);
	glCallList(list);
	return Qnil;
}

emacs_value Fgl_delete_lists(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint list = extract_integer(env, args[0]);
	GLsizei range = extract_integer(env, args[1]);
	glDeleteLists(list, range);
	return Qnil;
}

emacs_value Fgl_gen_lists(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei range = extract_integer(env, args[0]);
	glGenLists(range);
	return Qnil;
}

emacs_value Fgl_list_base(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint base = extract_integer(env, args[0]);
	glListBase(base);
	return Qnil;
}

emacs_value Fgl_begin(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glBegin(mode);
	return Qnil;
}

emacs_value Fgl_color3b(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbyte red = extract_integer(env, args[0]);
	GLbyte green = extract_integer(env, args[1]);
	GLbyte blue = extract_integer(env, args[2]);
	glColor3b(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble red = extract_double(env, args[0]);
	GLdouble green = extract_double(env, args[1]);
	GLdouble blue = extract_double(env, args[2]);
	glColor3d(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	glColor3f(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint red = extract_integer(env, args[0]);
	GLint green = extract_integer(env, args[1]);
	GLint blue = extract_integer(env, args[2]);
	glColor3i(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort red = extract_integer(env, args[0]);
	GLshort green = extract_integer(env, args[1]);
	GLshort blue = extract_integer(env, args[2]);
	glColor3s(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color3ub(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte red = extract_integer(env, args[0]);
	GLubyte green = extract_integer(env, args[1]);
	GLubyte blue = extract_integer(env, args[2]);
	glColor3ub(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint red = extract_integer(env, args[0]);
	GLuint green = extract_integer(env, args[1]);
	GLuint blue = extract_integer(env, args[2]);
	glColor3ui(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color3us(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLushort red = extract_integer(env, args[0]);
	GLushort green = extract_integer(env, args[1]);
	GLushort blue = extract_integer(env, args[2]);
	glColor3us(red, green, blue);
	return Qnil;
}

emacs_value Fgl_color4b(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbyte red = extract_integer(env, args[0]);
	GLbyte green = extract_integer(env, args[1]);
	GLbyte blue = extract_integer(env, args[2]);
	GLbyte alpha = extract_integer(env, args[3]);
	glColor4b(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_color4d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble red = extract_double(env, args[0]);
	GLdouble green = extract_double(env, args[1]);
	GLdouble blue = extract_double(env, args[2]);
	GLdouble alpha = extract_double(env, args[3]);
	glColor4d(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_color4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	GLfloat alpha = extract_double(env, args[3]);
	glColor4f(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_color4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint red = extract_integer(env, args[0]);
	GLint green = extract_integer(env, args[1]);
	GLint blue = extract_integer(env, args[2]);
	GLint alpha = extract_integer(env, args[3]);
	glColor4i(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_color4s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort red = extract_integer(env, args[0]);
	GLshort green = extract_integer(env, args[1]);
	GLshort blue = extract_integer(env, args[2]);
	GLshort alpha = extract_integer(env, args[3]);
	glColor4s(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_color4ub(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte red = extract_integer(env, args[0]);
	GLubyte green = extract_integer(env, args[1]);
	GLubyte blue = extract_integer(env, args[2]);
	GLubyte alpha = extract_integer(env, args[3]);
	glColor4ub(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_color4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint red = extract_integer(env, args[0]);
	GLuint green = extract_integer(env, args[1]);
	GLuint blue = extract_integer(env, args[2]);
	GLuint alpha = extract_integer(env, args[3]);
	glColor4ui(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_color4us(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLushort red = extract_integer(env, args[0]);
	GLushort green = extract_integer(env, args[1]);
	GLushort blue = extract_integer(env, args[2]);
	GLushort alpha = extract_integer(env, args[3]);
	glColor4us(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_edge_flag(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLboolean flag = extract_integer(env, args[0]);
	glEdgeFlag(flag);
	return Qnil;
}

emacs_value Fgl_end(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glEnd();
	return Qnil;
}

emacs_value Fgl_indexd(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble c = extract_double(env, args[0]);
	glIndexd(c);
	return Qnil;
}

emacs_value Fgl_indexf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat c = extract_double(env, args[0]);
	glIndexf(c);
	return Qnil;
}

emacs_value Fgl_indexi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint c = extract_integer(env, args[0]);
	glIndexi(c);
	return Qnil;
}

emacs_value Fgl_indexs(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort c = extract_integer(env, args[0]);
	glIndexs(c);
	return Qnil;
}

emacs_value Fgl_normal3b(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbyte nx = extract_integer(env, args[0]);
	GLbyte ny = extract_integer(env, args[1]);
	GLbyte nz = extract_integer(env, args[2]);
	glNormal3b(nx, ny, nz);
	return Qnil;
}

emacs_value Fgl_normal3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble nx = extract_double(env, args[0]);
	GLdouble ny = extract_double(env, args[1]);
	GLdouble nz = extract_double(env, args[2]);
	glNormal3d(nx, ny, nz);
	return Qnil;
}

emacs_value Fgl_normal3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat nx = extract_double(env, args[0]);
	GLfloat ny = extract_double(env, args[1]);
	GLfloat nz = extract_double(env, args[2]);
	glNormal3f(nx, ny, nz);
	return Qnil;
}

emacs_value Fgl_normal3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint nx = extract_integer(env, args[0]);
	GLint ny = extract_integer(env, args[1]);
	GLint nz = extract_integer(env, args[2]);
	glNormal3i(nx, ny, nz);
	return Qnil;
}

emacs_value Fgl_normal3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort nx = extract_integer(env, args[0]);
	GLshort ny = extract_integer(env, args[1]);
	GLshort nz = extract_integer(env, args[2]);
	glNormal3s(nx, ny, nz);
	return Qnil;
}

emacs_value Fgl_raster_pos2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	glRasterPos2d(x, y);
	return Qnil;
}

emacs_value Fgl_raster_pos2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	glRasterPos2f(x, y);
	return Qnil;
}

emacs_value Fgl_raster_pos2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	glRasterPos2i(x, y);
	return Qnil;
}

emacs_value Fgl_raster_pos2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	glRasterPos2s(x, y);
	return Qnil;
}

emacs_value Fgl_raster_pos3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	glRasterPos3d(x, y, z);
	return Qnil;
}

emacs_value Fgl_raster_pos3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	glRasterPos3f(x, y, z);
	return Qnil;
}

emacs_value Fgl_raster_pos3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLint z = extract_integer(env, args[2]);
	glRasterPos3i(x, y, z);
	return Qnil;
}

emacs_value Fgl_raster_pos3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	GLshort z = extract_integer(env, args[2]);
	glRasterPos3s(x, y, z);
	return Qnil;
}

emacs_value Fgl_raster_pos4d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	GLdouble w = extract_double(env, args[3]);
	glRasterPos4d(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_raster_pos4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	GLfloat w = extract_double(env, args[3]);
	glRasterPos4f(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_raster_pos4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLint z = extract_integer(env, args[2]);
	GLint w = extract_integer(env, args[3]);
	glRasterPos4i(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_raster_pos4s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	GLshort z = extract_integer(env, args[2]);
	GLshort w = extract_integer(env, args[3]);
	glRasterPos4s(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_rectd(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x1 = extract_double(env, args[0]);
	GLdouble y1 = extract_double(env, args[1]);
	GLdouble x2 = extract_double(env, args[2]);
	GLdouble y2 = extract_double(env, args[3]);
	glRectd(x1, y1, x2, y2);
	return Qnil;
}

emacs_value Fgl_rectf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x1 = extract_double(env, args[0]);
	GLfloat y1 = extract_double(env, args[1]);
	GLfloat x2 = extract_double(env, args[2]);
	GLfloat y2 = extract_double(env, args[3]);
	glRectf(x1, y1, x2, y2);
	return Qnil;
}

emacs_value Fgl_recti(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x1 = extract_integer(env, args[0]);
	GLint y1 = extract_integer(env, args[1]);
	GLint x2 = extract_integer(env, args[2]);
	GLint y2 = extract_integer(env, args[3]);
	glRecti(x1, y1, x2, y2);
	return Qnil;
}

emacs_value Fgl_rects(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x1 = extract_integer(env, args[0]);
	GLshort y1 = extract_integer(env, args[1]);
	GLshort x2 = extract_integer(env, args[2]);
	GLshort y2 = extract_integer(env, args[3]);
	glRects(x1, y1, x2, y2);
	return Qnil;
}

emacs_value Fgl_tex_coord1d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble s = extract_double(env, args[0]);
	glTexCoord1d(s);
	return Qnil;
}

emacs_value Fgl_tex_coord1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat s = extract_double(env, args[0]);
	glTexCoord1f(s);
	return Qnil;
}

emacs_value Fgl_tex_coord1i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint s = extract_integer(env, args[0]);
	glTexCoord1i(s);
	return Qnil;
}

emacs_value Fgl_tex_coord1s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort s = extract_integer(env, args[0]);
	glTexCoord1s(s);
	return Qnil;
}

emacs_value Fgl_tex_coord2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble s = extract_double(env, args[0]);
	GLdouble t = extract_double(env, args[1]);
	glTexCoord2d(s, t);
	return Qnil;
}

emacs_value Fgl_tex_coord2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat s = extract_double(env, args[0]);
	GLfloat t = extract_double(env, args[1]);
	glTexCoord2f(s, t);
	return Qnil;
}

emacs_value Fgl_tex_coord2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint s = extract_integer(env, args[0]);
	GLint t = extract_integer(env, args[1]);
	glTexCoord2i(s, t);
	return Qnil;
}

emacs_value Fgl_tex_coord2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort s = extract_integer(env, args[0]);
	GLshort t = extract_integer(env, args[1]);
	glTexCoord2s(s, t);
	return Qnil;
}

emacs_value Fgl_tex_coord3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble s = extract_double(env, args[0]);
	GLdouble t = extract_double(env, args[1]);
	GLdouble r = extract_double(env, args[2]);
	glTexCoord3d(s, t, r);
	return Qnil;
}

emacs_value Fgl_tex_coord3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat s = extract_double(env, args[0]);
	GLfloat t = extract_double(env, args[1]);
	GLfloat r = extract_double(env, args[2]);
	glTexCoord3f(s, t, r);
	return Qnil;
}

emacs_value Fgl_tex_coord3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint s = extract_integer(env, args[0]);
	GLint t = extract_integer(env, args[1]);
	GLint r = extract_integer(env, args[2]);
	glTexCoord3i(s, t, r);
	return Qnil;
}

emacs_value Fgl_tex_coord3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort s = extract_integer(env, args[0]);
	GLshort t = extract_integer(env, args[1]);
	GLshort r = extract_integer(env, args[2]);
	glTexCoord3s(s, t, r);
	return Qnil;
}

emacs_value Fgl_tex_coord4d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble s = extract_double(env, args[0]);
	GLdouble t = extract_double(env, args[1]);
	GLdouble r = extract_double(env, args[2]);
	GLdouble q = extract_double(env, args[3]);
	glTexCoord4d(s, t, r, q);
	return Qnil;
}

emacs_value Fgl_tex_coord4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat s = extract_double(env, args[0]);
	GLfloat t = extract_double(env, args[1]);
	GLfloat r = extract_double(env, args[2]);
	GLfloat q = extract_double(env, args[3]);
	glTexCoord4f(s, t, r, q);
	return Qnil;
}

emacs_value Fgl_tex_coord4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint s = extract_integer(env, args[0]);
	GLint t = extract_integer(env, args[1]);
	GLint r = extract_integer(env, args[2]);
	GLint q = extract_integer(env, args[3]);
	glTexCoord4i(s, t, r, q);
	return Qnil;
}

emacs_value Fgl_tex_coord4s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort s = extract_integer(env, args[0]);
	GLshort t = extract_integer(env, args[1]);
	GLshort r = extract_integer(env, args[2]);
	GLshort q = extract_integer(env, args[3]);
	glTexCoord4s(s, t, r, q);
	return Qnil;
}

emacs_value Fgl_vertex2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	glVertex2d(x, y);
	return Qnil;
}

emacs_value Fgl_vertex2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	glVertex2f(x, y);
	return Qnil;
}

emacs_value Fgl_vertex2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	glVertex2i(x, y);
	return Qnil;
}

emacs_value Fgl_vertex2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	glVertex2s(x, y);
	return Qnil;
}

emacs_value Fgl_vertex3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	glVertex3d(x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	glVertex3f(x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLint z = extract_integer(env, args[2]);
	glVertex3i(x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	GLshort z = extract_integer(env, args[2]);
	glVertex3s(x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex4d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	GLdouble w = extract_double(env, args[3]);
	glVertex4d(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	GLfloat w = extract_double(env, args[3]);
	glVertex4f(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLint z = extract_integer(env, args[2]);
	GLint w = extract_integer(env, args[3]);
	glVertex4i(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex4s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	GLshort z = extract_integer(env, args[2]);
	GLshort w = extract_integer(env, args[3]);
	glVertex4s(x, y, z, w);
	return Qnil;
}

emacs_value Fgl_color_material(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum face = extract_integer(env, args[0]);
	GLenum mode = extract_integer(env, args[1]);
	glColorMaterial(face, mode);
	return Qnil;
}

emacs_value Fgl_fogf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLfloat param = extract_double(env, args[1]);
	glFogf(pname, param);
	return Qnil;
}

emacs_value Fgl_fogi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLint param = extract_integer(env, args[1]);
	glFogi(pname, param);
	return Qnil;
}

emacs_value Fgl_lightf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum light = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLfloat param = extract_double(env, args[2]);
	glLightf(light, pname, param);
	return Qnil;
}

emacs_value Fgl_lighti(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum light = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint param = extract_integer(env, args[2]);
	glLighti(light, pname, param);
	return Qnil;
}

emacs_value Fgl_light_modelf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLfloat param = extract_double(env, args[1]);
	glLightModelf(pname, param);
	return Qnil;
}

emacs_value Fgl_light_modeli(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLint param = extract_integer(env, args[1]);
	glLightModeli(pname, param);
	return Qnil;
}

emacs_value Fgl_line_stipple(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint factor = extract_integer(env, args[0]);
	GLushort pattern = extract_integer(env, args[1]);
	glLineStipple(factor, pattern);
	return Qnil;
}

emacs_value Fgl_materialf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum face = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLfloat param = extract_double(env, args[2]);
	glMaterialf(face, pname, param);
	return Qnil;
}

emacs_value Fgl_materiali(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum face = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint param = extract_integer(env, args[2]);
	glMateriali(face, pname, param);
	return Qnil;
}

emacs_value Fgl_shade_model(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glShadeModel(mode);
	return Qnil;
}

emacs_value Fgl_tex_envf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLfloat param = extract_double(env, args[2]);
	glTexEnvf(target, pname, param);
	return Qnil;
}

emacs_value Fgl_tex_envi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint param = extract_integer(env, args[2]);
	glTexEnvi(target, pname, param);
	return Qnil;
}

emacs_value Fgl_tex_gend(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum coord = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLdouble param = extract_double(env, args[2]);
	glTexGend(coord, pname, param);
	return Qnil;
}

emacs_value Fgl_tex_genf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum coord = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLfloat param = extract_double(env, args[2]);
	glTexGenf(coord, pname, param);
	return Qnil;
}

emacs_value Fgl_tex_geni(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum coord = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint param = extract_integer(env, args[2]);
	glTexGeni(coord, pname, param);
	return Qnil;
}

emacs_value Fgl_render_mode(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glRenderMode(mode);
	return Qnil;
}

emacs_value Fgl_init_names(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glInitNames();
	return Qnil;
}

emacs_value Fgl_load_name(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint name = extract_integer(env, args[0]);
	glLoadName(name);
	return Qnil;
}

emacs_value Fgl_pass_through(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat token = extract_double(env, args[0]);
	glPassThrough(token);
	return Qnil;
}

emacs_value Fgl_pop_name(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glPopName();
	return Qnil;
}

emacs_value Fgl_push_name(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint name = extract_integer(env, args[0]);
	glPushName(name);
	return Qnil;
}

emacs_value Fgl_clear_accum(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	GLfloat alpha = extract_double(env, args[3]);
	glClearAccum(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_clear_index(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat c = extract_double(env, args[0]);
	glClearIndex(c);
	return Qnil;
}

emacs_value Fgl_index_mask(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint mask = extract_integer(env, args[0]);
	glIndexMask(mask);
	return Qnil;
}

emacs_value Fgl_accum(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum op = extract_integer(env, args[0]);
	GLfloat value = extract_double(env, args[1]);
	glAccum(op, value);
	return Qnil;
}

emacs_value Fgl_pop_attrib(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glPopAttrib();
	return Qnil;
}

emacs_value Fgl_push_attrib(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbitfield mask = extract_integer(env, args[0]);
	glPushAttrib(mask);
	return Qnil;
}

emacs_value Fgl_map_grid1d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint un = extract_integer(env, args[0]);
	GLdouble u1 = extract_double(env, args[1]);
	GLdouble u2 = extract_double(env, args[2]);
	glMapGrid1d(un, u1, u2);
	return Qnil;
}

emacs_value Fgl_map_grid1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint un = extract_integer(env, args[0]);
	GLfloat u1 = extract_double(env, args[1]);
	GLfloat u2 = extract_double(env, args[2]);
	glMapGrid1f(un, u1, u2);
	return Qnil;
}

emacs_value Fgl_map_grid2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint un = extract_integer(env, args[0]);
	GLdouble u1 = extract_double(env, args[1]);
	GLdouble u2 = extract_double(env, args[2]);
	GLint vn = extract_integer(env, args[3]);
	GLdouble v1 = extract_double(env, args[4]);
	GLdouble v2 = extract_double(env, args[5]);
	glMapGrid2d(un, u1, u2, vn, v1, v2);
	return Qnil;
}

emacs_value Fgl_map_grid2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint un = extract_integer(env, args[0]);
	GLfloat u1 = extract_double(env, args[1]);
	GLfloat u2 = extract_double(env, args[2]);
	GLint vn = extract_integer(env, args[3]);
	GLfloat v1 = extract_double(env, args[4]);
	GLfloat v2 = extract_double(env, args[5]);
	glMapGrid2f(un, u1, u2, vn, v1, v2);
	return Qnil;
}

emacs_value Fgl_eval_coord1d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble u = extract_double(env, args[0]);
	glEvalCoord1d(u);
	return Qnil;
}

emacs_value Fgl_eval_coord1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat u = extract_double(env, args[0]);
	glEvalCoord1f(u);
	return Qnil;
}

emacs_value Fgl_eval_coord2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble u = extract_double(env, args[0]);
	GLdouble v = extract_double(env, args[1]);
	glEvalCoord2d(u, v);
	return Qnil;
}

emacs_value Fgl_eval_coord2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat u = extract_double(env, args[0]);
	GLfloat v = extract_double(env, args[1]);
	glEvalCoord2f(u, v);
	return Qnil;
}

emacs_value Fgl_eval_mesh1(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	GLint i1 = extract_integer(env, args[1]);
	GLint i2 = extract_integer(env, args[2]);
	glEvalMesh1(mode, i1, i2);
	return Qnil;
}

emacs_value Fgl_eval_point1(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint i = extract_integer(env, args[0]);
	glEvalPoint1(i);
	return Qnil;
}

emacs_value Fgl_eval_mesh2(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	GLint i1 = extract_integer(env, args[1]);
	GLint i2 = extract_integer(env, args[2]);
	GLint j1 = extract_integer(env, args[3]);
	GLint j2 = extract_integer(env, args[4]);
	glEvalMesh2(mode, i1, i2, j1, j2);
	return Qnil;
}

emacs_value Fgl_eval_point2(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint i = extract_integer(env, args[0]);
	GLint j = extract_integer(env, args[1]);
	glEvalPoint2(i, j);
	return Qnil;
}

emacs_value Fgl_alpha_func(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum func = extract_integer(env, args[0]);
	GLfloat ref = extract_double(env, args[1]);
	glAlphaFunc(func, ref);
	return Qnil;
}

emacs_value Fgl_pixel_zoom(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat xfactor = extract_double(env, args[0]);
	GLfloat yfactor = extract_double(env, args[1]);
	glPixelZoom(xfactor, yfactor);
	return Qnil;
}

emacs_value Fgl_pixel_transferf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLfloat param = extract_double(env, args[1]);
	glPixelTransferf(pname, param);
	return Qnil;
}

emacs_value Fgl_pixel_transferi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLint param = extract_integer(env, args[1]);
	glPixelTransferi(pname, param);
	return Qnil;
}

emacs_value Fgl_copy_pixels(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLsizei width = extract_integer(env, args[2]);
	GLsizei height = extract_integer(env, args[3]);
	GLenum type = extract_integer(env, args[4]);
	glCopyPixels(x, y, width, height, type);
	return Qnil;
}

emacs_value Fgl_is_list(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint list = extract_integer(env, args[0]);
	glIsList(list);
	return Qnil;
}

emacs_value Fgl_frustum(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble left = extract_double(env, args[0]);
	GLdouble right = extract_double(env, args[1]);
	GLdouble bottom = extract_double(env, args[2]);
	GLdouble top = extract_double(env, args[3]);
	GLdouble zNear = extract_double(env, args[4]);
	GLdouble zFar = extract_double(env, args[5]);
	glFrustum(left, right, bottom, top, zNear, zFar);
	return Qnil;
}

emacs_value Fgl_load_identity(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glLoadIdentity();
	return Qnil;
}

emacs_value Fgl_matrix_mode(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glMatrixMode(mode);
	return Qnil;
}

emacs_value Fgl_ortho(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble left = extract_double(env, args[0]);
	GLdouble right = extract_double(env, args[1]);
	GLdouble bottom = extract_double(env, args[2]);
	GLdouble top = extract_double(env, args[3]);
	GLdouble zNear = extract_double(env, args[4]);
	GLdouble zFar = extract_double(env, args[5]);
	glOrtho(left, right, bottom, top, zNear, zFar);
	return Qnil;
}

emacs_value Fgl_pop_matrix(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glPopMatrix();
	return Qnil;
}

emacs_value Fgl_push_matrix(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glPushMatrix();
	return Qnil;
}

emacs_value Fgl_rotated(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble angle = extract_double(env, args[0]);
	GLdouble x = extract_double(env, args[1]);
	GLdouble y = extract_double(env, args[2]);
	GLdouble z = extract_double(env, args[3]);
	glRotated(angle, x, y, z);
	return Qnil;
}

emacs_value Fgl_rotatef(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat angle = extract_double(env, args[0]);
	GLfloat x = extract_double(env, args[1]);
	GLfloat y = extract_double(env, args[2]);
	GLfloat z = extract_double(env, args[3]);
	glRotatef(angle, x, y, z);
	return Qnil;
}

emacs_value Fgl_scaled(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	glScaled(x, y, z);
	return Qnil;
}

emacs_value Fgl_scalef(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	glScalef(x, y, z);
	return Qnil;
}

emacs_value Fgl_translated(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	glTranslated(x, y, z);
	return Qnil;
}

emacs_value Fgl_translatef(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	glTranslatef(x, y, z);
	return Qnil;
}

