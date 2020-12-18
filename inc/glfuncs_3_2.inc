emacs_value Fgl_provoking_vertex(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glProvokingVertex(mode);
	return Qnil;
}

emacs_value Fgl_fence_sync(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum condition = extract_integer(env, args[0]);
	GLbitfield flags = extract_integer(env, args[1]);
	glFenceSync(condition, flags);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLuint texture = extract_integer(env, args[2]);
	GLint level = extract_integer(env, args[3]);
	glFramebufferTexture(target, attachment, texture, level);
	return Qnil;
}

emacs_value Fgl_tex_image2_d_multisample(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLsizei samples = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLsizei width = extract_integer(env, args[3]);
	GLsizei height = extract_integer(env, args[4]);
	GLboolean fixedsamplelocations = extract_integer(env, args[5]);
	glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
	return Qnil;
}

emacs_value Fgl_tex_image3_d_multisample(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLsizei samples = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLsizei width = extract_integer(env, args[3]);
	GLsizei height = extract_integer(env, args[4]);
	GLsizei depth = extract_integer(env, args[5]);
	GLboolean fixedsamplelocations = extract_integer(env, args[6]);
	glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
	return Qnil;
}

emacs_value Fgl_sample_maski(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint maskNumber = extract_integer(env, args[0]);
	GLbitfield mask = extract_integer(env, args[1]);
	glSampleMaski(maskNumber, mask);
	return Qnil;
}

