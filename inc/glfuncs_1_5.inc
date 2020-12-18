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

