emacs_value Fgl_draw_arrays(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	GLint first = extract_integer(env, args[1]);
	GLsizei count = extract_integer(env, args[2]);
	glDrawArrays(mode, first, count);
	return Qnil;
}

emacs_value Fgl_polygon_offset(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat factor = extract_double(env, args[0]);
	GLfloat units = extract_double(env, args[1]);
	glPolygonOffset(factor, units);
	return Qnil;
}

emacs_value Fgl_copy_tex_image1_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLint x = extract_integer(env, args[3]);
	GLint y = extract_integer(env, args[4]);
	GLsizei width = extract_integer(env, args[5]);
	GLint border = extract_integer(env, args[6]);
	glCopyTexImage1D(target, level, internalformat, x, y, width, border);
	return Qnil;
}

emacs_value Fgl_copy_tex_image2_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLint x = extract_integer(env, args[3]);
	GLint y = extract_integer(env, args[4]);
	GLsizei width = extract_integer(env, args[5]);
	GLsizei height = extract_integer(env, args[6]);
	GLint border = extract_integer(env, args[7]);
	glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
	return Qnil;
}

emacs_value Fgl_copy_tex_sub_image1_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLint xoffset = extract_integer(env, args[2]);
	GLint x = extract_integer(env, args[3]);
	GLint y = extract_integer(env, args[4]);
	GLsizei width = extract_integer(env, args[5]);
	glCopyTexSubImage1D(target, level, xoffset, x, y, width);
	return Qnil;
}

emacs_value Fgl_copy_tex_sub_image2_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLint xoffset = extract_integer(env, args[2]);
	GLint yoffset = extract_integer(env, args[3]);
	GLint x = extract_integer(env, args[4]);
	GLint y = extract_integer(env, args[5]);
	GLsizei width = extract_integer(env, args[6]);
	GLsizei height = extract_integer(env, args[7]);
	glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	return Qnil;
}

emacs_value Fgl_bind_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint texture = extract_integer(env, args[1]);
	glBindTexture(target, texture);
	return Qnil;
}

emacs_value Fgl_is_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint texture = extract_integer(env, args[0]);
	glIsTexture(texture);
	return Qnil;
}

emacs_value Fgl_array_element(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint i = extract_integer(env, args[0]);
	glArrayElement(i);
	return Qnil;
}

emacs_value Fgl_disable_client_state(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum array = extract_integer(env, args[0]);
	glDisableClientState(array);
	return Qnil;
}

emacs_value Fgl_enable_client_state(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum array = extract_integer(env, args[0]);
	glEnableClientState(array);
	return Qnil;
}

emacs_value Fgl_indexub(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte c = extract_integer(env, args[0]);
	glIndexub(c);
	return Qnil;
}

emacs_value Fgl_pop_client_attrib(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glPopClientAttrib();
	return Qnil;
}

emacs_value Fgl_push_client_attrib(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbitfield mask = extract_integer(env, args[0]);
	glPushClientAttrib(mask);
	return Qnil;
}

