emacs_value Fgl_copy_tex_sub_image3_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLint xoffset = extract_integer(env, args[2]);
	GLint yoffset = extract_integer(env, args[3]);
	GLint zoffset = extract_integer(env, args[4]);
	GLint x = extract_integer(env, args[5]);
	GLint y = extract_integer(env, args[6]);
	GLsizei width = extract_integer(env, args[7]);
	GLsizei height = extract_integer(env, args[8]);
	glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
	return Qnil;
}

