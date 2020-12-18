emacs_value Fgl_active_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	glActiveTexture(texture);
	return Qnil;
}

emacs_value Fgl_sample_coverage(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat value = extract_double(env, args[0]);
	GLboolean invert = extract_integer(env, args[1]);
	glSampleCoverage(value, invert);
	return Qnil;
}

emacs_value Fgl_client_active_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	glClientActiveTexture(texture);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	glMultiTexCoord1d(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	glMultiTexCoord1f(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	glMultiTexCoord1i(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	glMultiTexCoord1s(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	GLdouble t = extract_double(env, args[2]);
	glMultiTexCoord2d(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	GLfloat t = extract_double(env, args[2]);
	glMultiTexCoord2f(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	GLint t = extract_integer(env, args[2]);
	glMultiTexCoord2i(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	GLshort t = extract_integer(env, args[2]);
	glMultiTexCoord2s(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	GLdouble t = extract_double(env, args[2]);
	GLdouble r = extract_double(env, args[3]);
	glMultiTexCoord3d(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	GLfloat t = extract_double(env, args[2]);
	GLfloat r = extract_double(env, args[3]);
	glMultiTexCoord3f(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	GLint t = extract_integer(env, args[2]);
	GLint r = extract_integer(env, args[3]);
	glMultiTexCoord3i(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	GLshort t = extract_integer(env, args[2]);
	GLshort r = extract_integer(env, args[3]);
	glMultiTexCoord3s(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	GLdouble t = extract_double(env, args[2]);
	GLdouble r = extract_double(env, args[3]);
	GLdouble q = extract_double(env, args[4]);
	glMultiTexCoord4d(target, s, t, r, q);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	GLfloat t = extract_double(env, args[2]);
	GLfloat r = extract_double(env, args[3]);
	GLfloat q = extract_double(env, args[4]);
	glMultiTexCoord4f(target, s, t, r, q);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	GLint t = extract_integer(env, args[2]);
	GLint r = extract_integer(env, args[3]);
	GLint q = extract_integer(env, args[4]);
	glMultiTexCoord4i(target, s, t, r, q);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	GLshort t = extract_integer(env, args[2]);
	GLshort r = extract_integer(env, args[3]);
	GLshort q = extract_integer(env, args[4]);
	glMultiTexCoord4s(target, s, t, r, q);
	return Qnil;
}

