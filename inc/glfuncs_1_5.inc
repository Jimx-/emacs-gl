emacs_value Fgl_gen_queries(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* ids = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _ids_idx;
		for (_ids_idx = 0; _ids_idx < n; _ids_idx++)
			ids[_ids_idx] = extract_integer(env, env->vec_get(env, args[1], _ids_idx));
	}
	glGenQueries(n, ids);
	{
		int _ids_idx;
		for (_ids_idx = 0; _ids_idx < n; _ids_idx++)
			env->vec_set(env, args[1], _ids_idx, env->make_integer(env, ids[_ids_idx]));
	}
	free(ids);
	return Qnil;
}

emacs_value Fgl_delete_queries(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* ids = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _ids_idx;
		for (_ids_idx = 0; _ids_idx < n; _ids_idx++)
			ids[_ids_idx] = extract_integer(env, env->vec_get(env, args[1], _ids_idx));
	}
	glDeleteQueries(n, ids);
	{
		int _ids_idx;
		for (_ids_idx = 0; _ids_idx < n; _ids_idx++)
			env->vec_set(env, args[1], _ids_idx, env->make_integer(env, ids[_ids_idx]));
	}
	free(ids);
	return Qnil;
}

emacs_value Fgl_is_query(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint id = extract_integer(env, args[0]);
	glIsQuery(id);
	return Qnil;
}

emacs_value Fgl_begin_query(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint id = extract_integer(env, args[1]);
	glBeginQuery(target, id);
	return Qnil;
}

emacs_value Fgl_end_query(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	glEndQuery(target);
	return Qnil;
}

emacs_value Fgl_bind_buffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint buffer = extract_integer(env, args[1]);
	glBindBuffer(target, buffer);
	return Qnil;
}

emacs_value Fgl_delete_buffers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* buffers = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _buffers_idx;
		for (_buffers_idx = 0; _buffers_idx < n; _buffers_idx++)
			buffers[_buffers_idx] = extract_integer(env, env->vec_get(env, args[1], _buffers_idx));
	}
	glDeleteBuffers(n, buffers);
	{
		int _buffers_idx;
		for (_buffers_idx = 0; _buffers_idx < n; _buffers_idx++)
			env->vec_set(env, args[1], _buffers_idx, env->make_integer(env, buffers[_buffers_idx]));
	}
	free(buffers);
	return Qnil;
}

emacs_value Fgl_gen_buffers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* buffers = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _buffers_idx;
		for (_buffers_idx = 0; _buffers_idx < n; _buffers_idx++)
			buffers[_buffers_idx] = extract_integer(env, env->vec_get(env, args[1], _buffers_idx));
	}
	glGenBuffers(n, buffers);
	{
		int _buffers_idx;
		for (_buffers_idx = 0; _buffers_idx < n; _buffers_idx++)
			env->vec_set(env, args[1], _buffers_idx, env->make_integer(env, buffers[_buffers_idx]));
	}
	free(buffers);
	return Qnil;
}

emacs_value Fgl_is_buffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint buffer = extract_integer(env, args[0]);
	glIsBuffer(buffer);
	return Qnil;
}

emacs_value Fgl_map_buffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum access = extract_integer(env, args[1]);
	glMapBuffer(target, access);
	return Qnil;
}

emacs_value Fgl_unmap_buffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	glUnmapBuffer(target);
	return Qnil;
}

