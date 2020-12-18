emacs_value Fgl_draw_arrays_instanced(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	GLint first = extract_integer(env, args[1]);
	GLsizei count = extract_integer(env, args[2]);
	GLsizei instancecount = extract_integer(env, args[3]);
	glDrawArraysInstanced(mode, first, count, instancecount);
	return Qnil;
}

emacs_value Fgl_tex_buffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum internalformat = extract_integer(env, args[1]);
	GLuint buffer = extract_integer(env, args[2]);
	glTexBuffer(target, internalformat, buffer);
	return Qnil;
}

emacs_value Fgl_primitive_restart_index(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	glPrimitiveRestartIndex(index);
	return Qnil;
}

emacs_value Fgl_uniform_block_binding(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint program = extract_integer(env, args[0]);
	GLuint uniformBlockIndex = extract_integer(env, args[1]);
	GLuint uniformBlockBinding = extract_integer(env, args[2]);
	glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
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

