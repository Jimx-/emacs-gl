emacs_value Fgl_color_maski(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLboolean r = extract_integer(env, args[1]);
	GLboolean g = extract_integer(env, args[2]);
	GLboolean b = extract_integer(env, args[3]);
	GLboolean a = extract_integer(env, args[4]);
	glColorMaski(index, r, g, b, a);
	return Qnil;
}

emacs_value Fgl_enablei(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glEnablei(target, index);
	return Qnil;
}

emacs_value Fgl_disablei(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glDisablei(target, index);
	return Qnil;
}

emacs_value Fgl_is_enabledi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glIsEnabledi(target, index);
	return Qnil;
}

emacs_value Fgl_begin_transform_feedback(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum primitiveMode = extract_integer(env, args[0]);
	glBeginTransformFeedback(primitiveMode);
	return Qnil;
}

emacs_value Fgl_end_transform_feedback(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glEndTransformFeedback();
	return Qnil;
}

emacs_value Fgl_bind_buffer_base(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	GLuint buffer = extract_integer(env, args[2]);
	glBindBufferBase(target, index, buffer);
	return Qnil;
}

emacs_value Fgl_clamp_color(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum clamp = extract_integer(env, args[1]);
	glClampColor(target, clamp);
	return Qnil;
}

emacs_value Fgl_begin_conditional_render(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint id = extract_integer(env, args[0]);
	GLenum mode = extract_integer(env, args[1]);
	glBeginConditionalRender(id, mode);
	return Qnil;
}

emacs_value Fgl_end_conditional_render(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glEndConditionalRender();
	return Qnil;
}

emacs_value Fgl_get_vertex_attrib_iiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint* params = (GLint*) calloc(1, sizeof(GLint));
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 1; _params_idx++)
			params[_params_idx] = extract_integer(env, env->vec_get(env, args[2], _params_idx));
	}
	glGetVertexAttribIiv(index, pname, params);
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 1; _params_idx++)
			env->vec_set(env, args[2], _params_idx, env->make_integer(env, params[_params_idx]));
	}
	free(params);
	return Qnil;
}

emacs_value Fgl_get_vertex_attrib_iuiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLuint* params = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 1; _params_idx++)
			params[_params_idx] = extract_integer(env, env->vec_get(env, args[2], _params_idx));
	}
	glGetVertexAttribIuiv(index, pname, params);
	{
		int _params_idx;
		for (_params_idx = 0; _params_idx < 1; _params_idx++)
			env->vec_set(env, args[2], _params_idx, env->make_integer(env, params[_params_idx]));
	}
	free(params);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i1i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	glVertexAttribI1i(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	GLint y = extract_integer(env, args[2]);
	glVertexAttribI2i(index, x, y);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	GLint y = extract_integer(env, args[2]);
	GLint z = extract_integer(env, args[3]);
	glVertexAttribI3i(index, x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	GLint y = extract_integer(env, args[2]);
	GLint z = extract_integer(env, args[3]);
	GLint w = extract_integer(env, args[4]);
	glVertexAttribI4i(index, x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	glVertexAttribI1ui(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	GLuint y = extract_integer(env, args[2]);
	glVertexAttribI2ui(index, x, y);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	GLuint y = extract_integer(env, args[2]);
	GLuint z = extract_integer(env, args[3]);
	glVertexAttribI3ui(index, x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	GLuint y = extract_integer(env, args[2]);
	GLuint z = extract_integer(env, args[3]);
	GLuint w = extract_integer(env, args[4]);
	glVertexAttribI4ui(index, x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i1iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(1, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI1iv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i2iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(2, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI2iv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i3iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(3, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI3iv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(4, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI4iv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i1uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint* v = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI1uiv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i2uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint* v = (GLuint*) calloc(2, sizeof(GLuint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI2uiv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint* v = (GLuint*) calloc(3, sizeof(GLuint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI3uiv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint* v = (GLuint*) calloc(4, sizeof(GLuint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI4uiv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4bv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLbyte* v = (GLbyte*) calloc(4, sizeof(GLbyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI4bv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(4, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI4sv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4ubv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLubyte* v = (GLubyte*) calloc(4, sizeof(GLubyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI4ubv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4usv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLushort* v = (GLushort*) calloc(4, sizeof(GLushort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glVertexAttribI4usv(index, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_uniform1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	glUniform1ui(location, v0);
	return Qnil;
}

emacs_value Fgl_uniform2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	GLuint v1 = extract_integer(env, args[2]);
	glUniform2ui(location, v0, v1);
	return Qnil;
}

emacs_value Fgl_uniform3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	GLuint v1 = extract_integer(env, args[2]);
	GLuint v2 = extract_integer(env, args[3]);
	glUniform3ui(location, v0, v1, v2);
	return Qnil;
}

emacs_value Fgl_uniform4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	GLuint v1 = extract_integer(env, args[2]);
	GLuint v2 = extract_integer(env, args[3]);
	GLuint v3 = extract_integer(env, args[4]);
	glUniform4ui(location, v0, v1, v2, v3);
	return Qnil;
}

emacs_value Fgl_uniform1uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLuint* value = (GLuint*) calloc(count*1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform1uiv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*1; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform2uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLuint* value = (GLuint*) calloc(count*2, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*2; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform2uiv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*2; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLuint* value = (GLuint*) calloc(count*3, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*3; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform3uiv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*3; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLuint* value = (GLuint*) calloc(count*4, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[2], _value_idx));
	}
	glUniform4uiv(location, count, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*4; _value_idx++)
			env->vec_set(env, args[2], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_clear_bufferfi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum buffer = extract_integer(env, args[0]);
	GLint drawbuffer = extract_integer(env, args[1]);
	GLfloat depth = extract_double(env, args[2]);
	GLint stencil = extract_integer(env, args[3]);
	glClearBufferfi(buffer, drawbuffer, depth, stencil);
	return Qnil;
}

emacs_value Fgl_get_stringi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum name = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glGetStringi(name, index);
	return Qnil;
}

emacs_value Fgl_is_renderbuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint renderbuffer = extract_integer(env, args[0]);
	glIsRenderbuffer(renderbuffer);
	return Qnil;
}

emacs_value Fgl_bind_renderbuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint renderbuffer = extract_integer(env, args[1]);
	glBindRenderbuffer(target, renderbuffer);
	return Qnil;
}

emacs_value Fgl_delete_renderbuffers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* renderbuffers = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _renderbuffers_idx;
		for (_renderbuffers_idx = 0; _renderbuffers_idx < n; _renderbuffers_idx++)
			renderbuffers[_renderbuffers_idx] = extract_integer(env, env->vec_get(env, args[1], _renderbuffers_idx));
	}
	glDeleteRenderbuffers(n, renderbuffers);
	{
		int _renderbuffers_idx;
		for (_renderbuffers_idx = 0; _renderbuffers_idx < n; _renderbuffers_idx++)
			env->vec_set(env, args[1], _renderbuffers_idx, env->make_integer(env, renderbuffers[_renderbuffers_idx]));
	}
	free(renderbuffers);
	return Qnil;
}

emacs_value Fgl_gen_renderbuffers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* renderbuffers = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _renderbuffers_idx;
		for (_renderbuffers_idx = 0; _renderbuffers_idx < n; _renderbuffers_idx++)
			renderbuffers[_renderbuffers_idx] = extract_integer(env, env->vec_get(env, args[1], _renderbuffers_idx));
	}
	glGenRenderbuffers(n, renderbuffers);
	{
		int _renderbuffers_idx;
		for (_renderbuffers_idx = 0; _renderbuffers_idx < n; _renderbuffers_idx++)
			env->vec_set(env, args[1], _renderbuffers_idx, env->make_integer(env, renderbuffers[_renderbuffers_idx]));
	}
	free(renderbuffers);
	return Qnil;
}

emacs_value Fgl_renderbuffer_storage(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum internalformat = extract_integer(env, args[1]);
	GLsizei width = extract_integer(env, args[2]);
	GLsizei height = extract_integer(env, args[3]);
	glRenderbufferStorage(target, internalformat, width, height);
	return Qnil;
}

emacs_value Fgl_is_framebuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint framebuffer = extract_integer(env, args[0]);
	glIsFramebuffer(framebuffer);
	return Qnil;
}

emacs_value Fgl_bind_framebuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint framebuffer = extract_integer(env, args[1]);
	glBindFramebuffer(target, framebuffer);
	return Qnil;
}

emacs_value Fgl_delete_framebuffers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* framebuffers = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _framebuffers_idx;
		for (_framebuffers_idx = 0; _framebuffers_idx < n; _framebuffers_idx++)
			framebuffers[_framebuffers_idx] = extract_integer(env, env->vec_get(env, args[1], _framebuffers_idx));
	}
	glDeleteFramebuffers(n, framebuffers);
	{
		int _framebuffers_idx;
		for (_framebuffers_idx = 0; _framebuffers_idx < n; _framebuffers_idx++)
			env->vec_set(env, args[1], _framebuffers_idx, env->make_integer(env, framebuffers[_framebuffers_idx]));
	}
	free(framebuffers);
	return Qnil;
}

emacs_value Fgl_gen_framebuffers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* framebuffers = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _framebuffers_idx;
		for (_framebuffers_idx = 0; _framebuffers_idx < n; _framebuffers_idx++)
			framebuffers[_framebuffers_idx] = extract_integer(env, env->vec_get(env, args[1], _framebuffers_idx));
	}
	glGenFramebuffers(n, framebuffers);
	{
		int _framebuffers_idx;
		for (_framebuffers_idx = 0; _framebuffers_idx < n; _framebuffers_idx++)
			env->vec_set(env, args[1], _framebuffers_idx, env->make_integer(env, framebuffers[_framebuffers_idx]));
	}
	free(framebuffers);
	return Qnil;
}

emacs_value Fgl_check_framebuffer_status(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	glCheckFramebufferStatus(target);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture1_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum textarget = extract_integer(env, args[2]);
	GLuint texture = extract_integer(env, args[3]);
	GLint level = extract_integer(env, args[4]);
	glFramebufferTexture1D(target, attachment, textarget, texture, level);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture2_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum textarget = extract_integer(env, args[2]);
	GLuint texture = extract_integer(env, args[3]);
	GLint level = extract_integer(env, args[4]);
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture3_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum textarget = extract_integer(env, args[2]);
	GLuint texture = extract_integer(env, args[3]);
	GLint level = extract_integer(env, args[4]);
	GLint zoffset = extract_integer(env, args[5]);
	glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
	return Qnil;
}

emacs_value Fgl_framebuffer_renderbuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum renderbuffertarget = extract_integer(env, args[2]);
	GLuint renderbuffer = extract_integer(env, args[3]);
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
	return Qnil;
}

emacs_value Fgl_generate_mipmap(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	glGenerateMipmap(target);
	return Qnil;
}

emacs_value Fgl_blit_framebuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint srcX0 = extract_integer(env, args[0]);
	GLint srcY0 = extract_integer(env, args[1]);
	GLint srcX1 = extract_integer(env, args[2]);
	GLint srcY1 = extract_integer(env, args[3]);
	GLint dstX0 = extract_integer(env, args[4]);
	GLint dstY0 = extract_integer(env, args[5]);
	GLint dstX1 = extract_integer(env, args[6]);
	GLint dstY1 = extract_integer(env, args[7]);
	GLbitfield mask = extract_integer(env, args[8]);
	GLenum filter = extract_integer(env, args[9]);
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	return Qnil;
}

emacs_value Fgl_renderbuffer_storage_multisample(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLsizei samples = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLsizei width = extract_integer(env, args[3]);
	GLsizei height = extract_integer(env, args[4]);
	glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture_layer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLuint texture = extract_integer(env, args[2]);
	GLint level = extract_integer(env, args[3]);
	GLint layer = extract_integer(env, args[4]);
	glFramebufferTextureLayer(target, attachment, texture, level, layer);
	return Qnil;
}

emacs_value Fgl_bind_vertex_array(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint array = extract_integer(env, args[0]);
	glBindVertexArray(array);
	return Qnil;
}

emacs_value Fgl_delete_vertex_arrays(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* arrays = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _arrays_idx;
		for (_arrays_idx = 0; _arrays_idx < n; _arrays_idx++)
			arrays[_arrays_idx] = extract_integer(env, env->vec_get(env, args[1], _arrays_idx));
	}
	glDeleteVertexArrays(n, arrays);
	{
		int _arrays_idx;
		for (_arrays_idx = 0; _arrays_idx < n; _arrays_idx++)
			env->vec_set(env, args[1], _arrays_idx, env->make_integer(env, arrays[_arrays_idx]));
	}
	free(arrays);
	return Qnil;
}

emacs_value Fgl_gen_vertex_arrays(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* arrays = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _arrays_idx;
		for (_arrays_idx = 0; _arrays_idx < n; _arrays_idx++)
			arrays[_arrays_idx] = extract_integer(env, env->vec_get(env, args[1], _arrays_idx));
	}
	glGenVertexArrays(n, arrays);
	{
		int _arrays_idx;
		for (_arrays_idx = 0; _arrays_idx < n; _arrays_idx++)
			env->vec_set(env, args[1], _arrays_idx, env->make_integer(env, arrays[_arrays_idx]));
	}
	free(arrays);
	return Qnil;
}

emacs_value Fgl_is_vertex_array(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint array = extract_integer(env, args[0]);
	glIsVertexArray(array);
	return Qnil;
}

