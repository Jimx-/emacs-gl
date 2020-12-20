emacs_value Fgl_uniform_matrix2x3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*6, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*6; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix2x3fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*6; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix3x2fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*6, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*6; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix3x2fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*6; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix2x4fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*8, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*8; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix2x4fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*8; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix4x2fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*8, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*8; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix4x2fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*8; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix3x4fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*12, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*12; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix3x4fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*12; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_uniform_matrix4x3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLsizei count = extract_integer(env, args[1]);
	GLboolean transpose = extract_integer(env, args[2]);
	GLfloat* value = (GLfloat*) calloc(count*12, sizeof(GLfloat));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*12; _value_idx++)
			value[_value_idx] = extract_double(env, env->vec_get(env, args[3], _value_idx));
	}
	glUniformMatrix4x3fv(location, count, transpose, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < count*12; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_float(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

