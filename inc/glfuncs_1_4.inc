emacs_value Fgl_blend_func_separate(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum sfactorRGB = extract_integer(env, args[0]);
	GLenum dfactorRGB = extract_integer(env, args[1]);
	GLenum sfactorAlpha = extract_integer(env, args[2]);
	GLenum dfactorAlpha = extract_integer(env, args[3]);
	glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	return Qnil;
}

emacs_value Fgl_point_parameterf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLfloat param = extract_double(env, args[1]);
	glPointParameterf(pname, param);
	return Qnil;
}

emacs_value Fgl_point_parameteri(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLint param = extract_integer(env, args[1]);
	glPointParameteri(pname, param);
	return Qnil;
}

emacs_value Fgl_fog_coordf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat coord = extract_double(env, args[0]);
	glFogCoordf(coord);
	return Qnil;
}

emacs_value Fgl_fog_coordd(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble coord = extract_double(env, args[0]);
	glFogCoordd(coord);
	return Qnil;
}

emacs_value Fgl_secondary_color3b(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbyte red = extract_integer(env, args[0]);
	GLbyte green = extract_integer(env, args[1]);
	GLbyte blue = extract_integer(env, args[2]);
	glSecondaryColor3b(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble red = extract_double(env, args[0]);
	GLdouble green = extract_double(env, args[1]);
	GLdouble blue = extract_double(env, args[2]);
	glSecondaryColor3d(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	glSecondaryColor3f(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint red = extract_integer(env, args[0]);
	GLint green = extract_integer(env, args[1]);
	GLint blue = extract_integer(env, args[2]);
	glSecondaryColor3i(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort red = extract_integer(env, args[0]);
	GLshort green = extract_integer(env, args[1]);
	GLshort blue = extract_integer(env, args[2]);
	glSecondaryColor3s(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3ub(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte red = extract_integer(env, args[0]);
	GLubyte green = extract_integer(env, args[1]);
	GLubyte blue = extract_integer(env, args[2]);
	glSecondaryColor3ub(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint red = extract_integer(env, args[0]);
	GLuint green = extract_integer(env, args[1]);
	GLuint blue = extract_integer(env, args[2]);
	glSecondaryColor3ui(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3us(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLushort red = extract_integer(env, args[0]);
	GLushort green = extract_integer(env, args[1]);
	GLushort blue = extract_integer(env, args[2]);
	glSecondaryColor3us(red, green, blue);
	return Qnil;
}

emacs_value Fgl_window_pos2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	glWindowPos2d(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	glWindowPos2f(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	glWindowPos2i(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	glWindowPos2s(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	glWindowPos3d(x, y, z);
	return Qnil;
}

emacs_value Fgl_window_pos3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	glWindowPos3f(x, y, z);
	return Qnil;
}

emacs_value Fgl_window_pos3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLint z = extract_integer(env, args[2]);
	glWindowPos3i(x, y, z);
	return Qnil;
}

emacs_value Fgl_window_pos3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	GLshort z = extract_integer(env, args[2]);
	glWindowPos3s(x, y, z);
	return Qnil;
}

emacs_value Fgl_blend_color(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	GLfloat alpha = extract_double(env, args[3]);
	glBlendColor(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_blend_equation(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glBlendEquation(mode);
	return Qnil;
}

