emacs_value Fgl_draw_arrays(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	GLint first = extract_integer(env, args[1]);
	GLsizei count = extract_integer(env, args[2]);
	glDrawArrays(mode, first, count);
	return Qnil;
}

emacs_value Fgl_polygon_offset(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat factor = extract_double(env, args[0]);
	GLfloat units = extract_double(env, args[1]);
	glPolygonOffset(factor, units);
	return Qnil;
}

emacs_value Fgl_copy_tex_image1_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLint x = extract_integer(env, args[3]);
	GLint y = extract_integer(env, args[4]);
	GLsizei width = extract_integer(env, args[5]);
	GLint border = extract_integer(env, args[6]);
	glCopyTexImage1D(target, level, internalformat, x, y, width, border);
	return Qnil;
}

emacs_value Fgl_copy_tex_image2_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLint x = extract_integer(env, args[3]);
	GLint y = extract_integer(env, args[4]);
	GLsizei width = extract_integer(env, args[5]);
	GLsizei height = extract_integer(env, args[6]);
	GLint border = extract_integer(env, args[7]);
	glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
	return Qnil;
}

emacs_value Fgl_copy_tex_sub_image1_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLint xoffset = extract_integer(env, args[2]);
	GLint x = extract_integer(env, args[3]);
	GLint y = extract_integer(env, args[4]);
	GLsizei width = extract_integer(env, args[5]);
	glCopyTexSubImage1D(target, level, xoffset, x, y, width);
	return Qnil;
}

emacs_value Fgl_copy_tex_sub_image2_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint level = extract_integer(env, args[1]);
	GLint xoffset = extract_integer(env, args[2]);
	GLint yoffset = extract_integer(env, args[3]);
	GLint x = extract_integer(env, args[4]);
	GLint y = extract_integer(env, args[5]);
	GLsizei width = extract_integer(env, args[6]);
	GLsizei height = extract_integer(env, args[7]);
	glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	return Qnil;
}

emacs_value Fgl_bind_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint texture = extract_integer(env, args[1]);
	glBindTexture(target, texture);
	return Qnil;
}

emacs_value Fgl_delete_textures(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* textures = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			textures[_textures_idx] = extract_integer(env, env->vec_get(env, args[1], _textures_idx));
	}
	glDeleteTextures(n, textures);
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			env->vec_set(env, args[1], _textures_idx, env->make_integer(env, textures[_textures_idx]));
	}
	free(textures);
	return Qnil;
}

emacs_value Fgl_gen_textures(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* textures = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			textures[_textures_idx] = extract_integer(env, env->vec_get(env, args[1], _textures_idx));
	}
	glGenTextures(n, textures);
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			env->vec_set(env, args[1], _textures_idx, env->make_integer(env, textures[_textures_idx]));
	}
	free(textures);
	return Qnil;
}

emacs_value Fgl_is_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint texture = extract_integer(env, args[0]);
	glIsTexture(texture);
	return Qnil;
}

emacs_value Fgl_array_element(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint i = extract_integer(env, args[0]);
	glArrayElement(i);
	return Qnil;
}

emacs_value Fgl_disable_client_state(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum array = extract_integer(env, args[0]);
	glDisableClientState(array);
	return Qnil;
}

emacs_value Fgl_enable_client_state(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum array = extract_integer(env, args[0]);
	glEnableClientState(array);
	return Qnil;
}

emacs_value Fgl_are_textures_resident(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* textures = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			textures[_textures_idx] = extract_integer(env, env->vec_get(env, args[1], _textures_idx));
	}
	GLboolean* residences = (GLboolean*) calloc(n, sizeof(GLboolean));
	{
		int _residences_idx;
		for (_residences_idx = 0; _residences_idx < n; _residences_idx++)
			residences[_residences_idx] = extract_integer(env, env->vec_get(env, args[2], _residences_idx));
	}
	glAreTexturesResident(n, textures, residences);
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			env->vec_set(env, args[1], _textures_idx, env->make_integer(env, textures[_textures_idx]));
	}
	free(textures);
	{
		int _residences_idx;
		for (_residences_idx = 0; _residences_idx < n; _residences_idx++)
			env->vec_set(env, args[2], _residences_idx, env->make_integer(env, residences[_residences_idx]));
	}
	free(residences);
	return Qnil;
}

emacs_value Fgl_prioritize_textures(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei n = extract_integer(env, args[0]);
	GLuint* textures = (GLuint*) calloc(n, sizeof(GLuint));
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			textures[_textures_idx] = extract_integer(env, env->vec_get(env, args[1], _textures_idx));
	}
	GLfloat* priorities = (GLfloat*) calloc(n, sizeof(GLfloat));
	{
		int _priorities_idx;
		for (_priorities_idx = 0; _priorities_idx < n; _priorities_idx++)
			priorities[_priorities_idx] = extract_double(env, env->vec_get(env, args[2], _priorities_idx));
	}
	glPrioritizeTextures(n, textures, priorities);
	{
		int _textures_idx;
		for (_textures_idx = 0; _textures_idx < n; _textures_idx++)
			env->vec_set(env, args[1], _textures_idx, env->make_integer(env, textures[_textures_idx]));
	}
	free(textures);
	{
		int _priorities_idx;
		for (_priorities_idx = 0; _priorities_idx < n; _priorities_idx++)
			env->vec_set(env, args[2], _priorities_idx, env->make_float(env, priorities[_priorities_idx]));
	}
	free(priorities);
	return Qnil;
}

emacs_value Fgl_indexub(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte c = extract_integer(env, args[0]);
	glIndexub(c);
	return Qnil;
}

emacs_value Fgl_indexubv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte* c = (GLubyte*) calloc(1, sizeof(GLubyte));
	{
		int _c_idx;
		for (_c_idx = 0; _c_idx < 1; _c_idx++)
			c[_c_idx] = extract_integer(env, env->vec_get(env, args[0], _c_idx));
	}
	glIndexubv(c);
	{
		int _c_idx;
		for (_c_idx = 0; _c_idx < 1; _c_idx++)
			env->vec_set(env, args[0], _c_idx, env->make_integer(env, c[_c_idx]));
	}
	free(c);
	return Qnil;
}

emacs_value Fgl_pop_client_attrib(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glPopClientAttrib();
	return Qnil;
}

emacs_value Fgl_push_client_attrib(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbitfield mask = extract_integer(env, args[0]);
	glPushClientAttrib(mask);
	return Qnil;
}

