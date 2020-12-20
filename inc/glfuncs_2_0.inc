emacs_value Fgl_blend_equation_separate(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum modeRGB = extract_integer(env, args[0]);
	GLenum modeAlpha = extract_integer(env, args[1]);
	glBlendEquationSeparate(modeRGB, modeAlpha);
	return Qnil;
}

emacs_value Fgl_draw_buffers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLenum* bufs = (GLenum*) calloc(n, sizeof(GLenum));
	{
		int _bufs_idx;
		for (_bufs_idx = 0; _bufs_idx < n; _bufs_idx++)
			bufs[_bufs_idx] = extract_integer(env, env->vec_get(env, args[1], _bufs_idx));
	}
	glDrawBuffers(n, bufs);
	{
		int _bufs_idx;
		for (_bufs_idx = 0; _bufs_idx < n; _bufs_idx++)
			env->vec_set(env, args[1], _bufs_idx, env->make_integer(env, bufs[_bufs_idx]));
	}
	free(bufs);
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

emacs_value Fgl_get_attached_shaders(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	GLsizei maxCount = extract_integer(env, args[1]);
	GLsizei* count = (GLsizei*) calloc(1, sizeof(GLsizei));
	{
		int _count_idx;
		for (_count_idx = 0; _count_idx < 1; _count_idx++)
			count[_count_idx] = extract_integer(env, env->vec_get(env, args[2], _count_idx));
	}
	GLuint* shaders = (GLuint*) calloc(maxCount, sizeof(GLuint));
	{
		int _shaders_idx;
		for (_shaders_idx = 0; _shaders_idx < maxCount; _shaders_idx++)
			shaders[_shaders_idx] = extract_integer(env, env->vec_get(env, args[3], _shaders_idx));
	}
	glGetAttachedShaders(program, maxCount, count, shaders);
	{
		int _count_idx;
		for (_count_idx = 0; _count_idx < 1; _count_idx++)
			env->vec_set(env, args[2], _count_idx, env->make_integer(env, count[_count_idx]));
	}
	free(count);
	{
		int _shaders_idx;
		for (_shaders_idx = 0; _shaders_idx < maxCount; _shaders_idx++)
			env->vec_set(env, args[3], _shaders_idx, env->make_integer(env, shaders[_shaders_idx]));
	}
	free(shaders);
	return Qnil;
}

emacs_value Fgl_get_vertex_attribdv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLdouble* params = (GLdouble*) calloc(4, sizeof(GLdouble));
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 4; _params_idx++)
			params[_params_idx] = extract_double(env, env->vec_get(env, args[2], _params_idx));
	}
	glGetVertexAttribdv(index, pname, params);
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 4; _params_idx++)
			env->vec_set(env, args[2], _params_idx, env->make_float(env, params[_params_idx]));
	}
	free(params);
	return Qnil;
}

emacs_value Fgl_get_vertex_attribfv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLfloat* params = (GLfloat*) calloc(4, sizeof(GLfloat));
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 4; _params_idx++)
			params[_params_idx] = extract_double(env, env->vec_get(env, args[2], _params_idx));
	}
	glGetVertexAttribfv(index, pname, params);
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 4; _params_idx++)
			env->vec_set(env, args[2], _params_idx, env->make_float(env, params[_params_idx]));
	}
	free(params);
	return Qnil;
}

emacs_value Fgl_get_vertex_attribiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint* params = (GLint*) calloc(4, sizeof(GLint));
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 4; _params_idx++)
			params[_params_idx] = extract_integer(env, env->vec_get(env, args[2], _params_idx));
	}
	glGetVertexAttribiv(index, pname, params);
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 4; _params_idx++)
			env->vec_set(env, args[2], _params_idx, env->make_integer(env, params[_params_idx]));
	}
	free(params);
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

emacs_value Fgl_uniform1fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLfloat* value = (GLfloat*) calloc(count*1, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*1; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform1fv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*1; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform2fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLfloat* value = (GLfloat*) calloc(count*2, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*2; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform2fv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*2; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLfloat* value = (GLfloat*) calloc(count*3, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*3; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform3fv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*3; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform4fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLfloat* value = (GLfloat*) calloc(count*4, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform4fv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform1iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLint* value = (GLint*) calloc(count*1, sizeof(GLint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform1iv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*1; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform2iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLint* value = (GLint*) calloc(count*2, sizeof(GLint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*2; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform2iv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*2; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform3iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLint* value = (GLint*) calloc(count*3, sizeof(GLint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*3; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform3iv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*3; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform4iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLint* value = (GLint*) calloc(count*4, sizeof(GLint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform4iv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix2fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*4, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix2fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*9, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*9; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix3fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*9; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix4fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*16, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*16; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix4fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*16; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
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

emacs_value Fgl_vertex_attrib1dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(1, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib1dv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat x = extract_double(env, args[1]);
	glVertexAttrib1f(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib1fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(1, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib1fv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib1s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort x = extract_integer(env, args[1]);
	glVertexAttrib1s(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib1sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(1, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib1sv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib2dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(2, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib2dv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib2fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(2, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib2fv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib2sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(2, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib2sv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib3dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(3, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib3dv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(3, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib3fv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib3sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(3, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib3sv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4_nbv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLbyte* v = (GLbyte*) calloc(4, sizeof(GLbyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4Nbv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4_niv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(4, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4Niv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4_nsv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(4, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4Nsv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib4_nubv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLubyte* v = (GLubyte*) calloc(4, sizeof(GLubyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4Nubv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4_nuiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint* v = (GLuint*) calloc(4, sizeof(GLuint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4Nuiv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4_nusv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLushort* v = (GLushort*) calloc(4, sizeof(GLushort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4Nusv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4bv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLbyte* v = (GLbyte*) calloc(4, sizeof(GLbyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4bv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib4dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(4, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4dv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib4fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(4, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4fv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(4, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4iv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
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

emacs_value Fgl_vertex_attrib4sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(4, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4sv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4ubv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLubyte* v = (GLubyte*) calloc(4, sizeof(GLubyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4ubv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint* v = (GLuint*) calloc(4, sizeof(GLuint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4uiv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib4usv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLushort* v = (GLushort*) calloc(4, sizeof(GLushort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttrib4usv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

