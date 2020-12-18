emacs_value Fgl_blend_equation_separate(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum modeRGB = extract_integer(env, args[0]);
	GLenum modeAlpha = extract_integer(env, args[1]);
	glBlendEquationSeparate(modeRGB, modeAlpha);
	return Qnil;
}

emacs_value Fgl_stencil_op_separate(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum face = extract_integer(env, args[0]);
	GLenum sfail = extract_integer(env, args[1]);
	GLenum dpfail = extract_integer(env, args[2]);
	GLenum dppass = extract_integer(env, args[3]);
	glStencilOpSeparate(face, sfail, dpfail, dppass);
	return Qnil;
}

emacs_value Fgl_stencil_func_separate(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum face = extract_integer(env, args[0]);
	GLenum func = extract_integer(env, args[1]);
	GLint ref = extract_integer(env, args[2]);
	GLuint mask = extract_integer(env, args[3]);
	glStencilFuncSeparate(face, func, ref, mask);
	return Qnil;
}

emacs_value Fgl_stencil_mask_separate(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum face = extract_integer(env, args[0]);
	GLuint mask = extract_integer(env, args[1]);
	glStencilMaskSeparate(face, mask);
	return Qnil;
}

emacs_value Fgl_attach_shader(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	GLuint shader = extract_integer(env, args[1]);
	glAttachShader(program, shader);
	return Qnil;
}

emacs_value Fgl_compile_shader(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint shader = extract_integer(env, args[0]);
	glCompileShader(shader);
	return Qnil;
}

emacs_value Fgl_create_program(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glCreateProgram();
	return Qnil;
}

emacs_value Fgl_create_shader(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	glCreateShader(type);
	return Qnil;
}

emacs_value Fgl_delete_program(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	glDeleteProgram(program);
	return Qnil;
}

emacs_value Fgl_delete_shader(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint shader = extract_integer(env, args[0]);
	glDeleteShader(shader);
	return Qnil;
}

emacs_value Fgl_detach_shader(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	GLuint shader = extract_integer(env, args[1]);
	glDetachShader(program, shader);
	return Qnil;
}

emacs_value Fgl_disable_vertex_attrib_array(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	glDisableVertexAttribArray(index);
	return Qnil;
}

emacs_value Fgl_enable_vertex_attrib_array(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	glEnableVertexAttribArray(index);
	return Qnil;
}

emacs_value Fgl_is_program(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	glIsProgram(program);
	return Qnil;
}

emacs_value Fgl_is_shader(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint shader = extract_integer(env, args[0]);
	glIsShader(shader);
	return Qnil;
}

emacs_value Fgl_link_program(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	glLinkProgram(program);
	return Qnil;
}

emacs_value Fgl_use_program(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	glUseProgram(program);
	return Qnil;
}

emacs_value Fgl_uniform1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLfloat v0 = extract_double(env, args[1]);
	glUniform1f(location, v0);
	return Qnil;
}

emacs_value Fgl_uniform2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLfloat v0 = extract_double(env, args[1]);
	GLfloat v1 = extract_double(env, args[2]);
	glUniform2f(location, v0, v1);
	return Qnil;
}

emacs_value Fgl_uniform3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLfloat v0 = extract_double(env, args[1]);
	GLfloat v1 = extract_double(env, args[2]);
	GLfloat v2 = extract_double(env, args[3]);
	glUniform3f(location, v0, v1, v2);
	return Qnil;
}

emacs_value Fgl_uniform4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLfloat v0 = extract_double(env, args[1]);
	GLfloat v1 = extract_double(env, args[2]);
	GLfloat v2 = extract_double(env, args[3]);
	GLfloat v3 = extract_double(env, args[4]);
	glUniform4f(location, v0, v1, v2, v3);
	return Qnil;
}

emacs_value Fgl_uniform1i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLint v0 = extract_integer(env, args[1]);
	glUniform1i(location, v0);
	return Qnil;
}

emacs_value Fgl_uniform2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLint v0 = extract_integer(env, args[1]);
	GLint v1 = extract_integer(env, args[2]);
	glUniform2i(location, v0, v1);
	return Qnil;
}

emacs_value Fgl_uniform3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLint v0 = extract_integer(env, args[1]);
	GLint v1 = extract_integer(env, args[2]);
	GLint v2 = extract_integer(env, args[3]);
	glUniform3i(location, v0, v1, v2);
	return Qnil;
}

emacs_value Fgl_uniform4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLint v0 = extract_integer(env, args[1]);
	GLint v1 = extract_integer(env, args[2]);
	GLint v2 = extract_integer(env, args[3]);
	GLint v3 = extract_integer(env, args[4]);
	glUniform4i(location, v0, v1, v2, v3);
	return Qnil;
}

emacs_value Fgl_validate_program(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	glValidateProgram(program);
	return Qnil;
}

emacs_value Fgl_vertex_attrib1d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble x = extract_double(env, args[1]);
	glVertexAttrib1d(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat x = extract_double(env, args[1]);
	glVertexAttrib1f(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib1s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort x = extract_integer(env, args[1]);
	glVertexAttrib1s(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble x = extract_double(env, args[1]);
	GLdouble y = extract_double(env, args[2]);
	glVertexAttrib2d(index, x, y);
	return Qnil;
}

emacs_value Fgl_vertex_attrib2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat x = extract_double(env, args[1]);
	GLfloat y = extract_double(env, args[2]);
	glVertexAttrib2f(index, x, y);
	return Qnil;
}

emacs_value Fgl_vertex_attrib2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort x = extract_integer(env, args[1]);
	GLshort y = extract_integer(env, args[2]);
	glVertexAttrib2s(index, x, y);
	return Qnil;
}

emacs_value Fgl_vertex_attrib3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble x = extract_double(env, args[1]);
	GLdouble y = extract_double(env, args[2]);
	GLdouble z = extract_double(env, args[3]);
	glVertexAttrib3d(index, x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex_attrib3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat x = extract_double(env, args[1]);
	GLfloat y = extract_double(env, args[2]);
	GLfloat z = extract_double(env, args[3]);
	glVertexAttrib3f(index, x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex_attrib3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort x = extract_integer(env, args[1]);
	GLshort y = extract_integer(env, args[2]);
	GLshort z = extract_integer(env, args[3]);
	glVertexAttrib3s(index, x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4_nub(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLubyte x = extract_integer(env, args[1]);
	GLubyte y = extract_integer(env, args[2]);
	GLubyte z = extract_integer(env, args[3]);
	GLubyte w = extract_integer(env, args[4]);
	glVertexAttrib4Nub(index, x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble x = extract_double(env, args[1]);
	GLdouble y = extract_double(env, args[2]);
	GLdouble z = extract_double(env, args[3]);
	GLdouble w = extract_double(env, args[4]);
	glVertexAttrib4d(index, x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat x = extract_double(env, args[1]);
	GLfloat y = extract_double(env, args[2]);
	GLfloat z = extract_double(env, args[3]);
	GLfloat w = extract_double(env, args[4]);
	glVertexAttrib4f(index, x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort x = extract_integer(env, args[1]);
	GLshort y = extract_integer(env, args[2]);
	GLshort z = extract_integer(env, args[3]);
	GLshort w = extract_integer(env, args[4]);
	glVertexAttrib4s(index, x, y, z, w);
	return Qnil;
}

