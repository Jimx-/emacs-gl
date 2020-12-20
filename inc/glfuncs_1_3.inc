emacs_value Fgl_active_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	glActiveTexture(texture);
	return Qnil;
}

emacs_value Fgl_sample_coverage(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat value = extract_double(env, args[0]);
	GLboolean invert = extract_integer(env, args[1]);
	glSampleCoverage(value, invert);
	return Qnil;
}

emacs_value Fgl_client_active_texture(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	glClientActiveTexture(texture);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	glMultiTexCoord1d(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(1, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord1dv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	glMultiTexCoord1f(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(1, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord1fv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	glMultiTexCoord1i(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(1, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord1iv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	glMultiTexCoord1s(target, s);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord1sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(1, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord1sv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 1; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	GLdouble t = extract_double(env, args[2]);
	glMultiTexCoord2d(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(2, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord2dv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	GLfloat t = extract_double(env, args[2]);
	glMultiTexCoord2f(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(2, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord2fv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	GLint t = extract_integer(env, args[2]);
	glMultiTexCoord2i(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(2, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord2iv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	GLshort t = extract_integer(env, args[2]);
	glMultiTexCoord2s(target, s, t);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord2sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(2, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord2sv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	GLdouble t = extract_double(env, args[2]);
	GLdouble r = extract_double(env, args[3]);
	glMultiTexCoord3d(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(3, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord3dv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	GLfloat t = extract_double(env, args[2]);
	GLfloat r = extract_double(env, args[3]);
	glMultiTexCoord3f(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(3, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord3fv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	GLint t = extract_integer(env, args[2]);
	GLint r = extract_integer(env, args[3]);
	glMultiTexCoord3i(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(3, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord3iv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	GLshort t = extract_integer(env, args[2]);
	GLshort r = extract_integer(env, args[3]);
	glMultiTexCoord3s(target, s, t, r);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord3sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(3, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord3sv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble s = extract_double(env, args[1]);
	GLdouble t = extract_double(env, args[2]);
	GLdouble r = extract_double(env, args[3]);
	GLdouble q = extract_double(env, args[4]);
	glMultiTexCoord4d(target, s, t, r, q);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLdouble* v = (GLdouble*) calloc(4, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord4dv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat s = extract_double(env, args[1]);
	GLfloat t = extract_double(env, args[2]);
	GLfloat r = extract_double(env, args[3]);
	GLfloat q = extract_double(env, args[4]);
	glMultiTexCoord4f(target, s, t, r, q);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLfloat* v = (GLfloat*) calloc(4, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord4fv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint s = extract_integer(env, args[1]);
	GLint t = extract_integer(env, args[2]);
	GLint r = extract_integer(env, args[3]);
	GLint q = extract_integer(env, args[4]);
	glMultiTexCoord4i(target, s, t, r, q);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLint* v = (GLint*) calloc(4, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord4iv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort s = extract_integer(env, args[1]);
	GLshort t = extract_integer(env, args[2]);
	GLshort r = extract_integer(env, args[3]);
	GLshort q = extract_integer(env, args[4]);
	glMultiTexCoord4s(target, s, t, r, q);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord4sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLshort* v = (GLshort*) calloc(4, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[1], _v_idx));
	}
	glMultiTexCoord4sv(target, v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 4; _v_idx++)
			env->vec_set(env, args[1], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_load_transpose_matrixf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat* m = (GLfloat*) calloc(16, sizeof(GLfloat));
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			m[_m_idx] = extract_double(env, env->vec_get(env, args[0], _m_idx));
	}
	glLoadTransposeMatrixf(m);
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			env->vec_set(env, args[0], _m_idx, env->make_float(env, m[_m_idx]));
	}
	free(m);
	return Qnil;
}

emacs_value Fgl_load_transpose_matrixd(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble* m = (GLdouble*) calloc(16, sizeof(GLdouble));
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			m[_m_idx] = extract_double(env, env->vec_get(env, args[0], _m_idx));
	}
	glLoadTransposeMatrixd(m);
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			env->vec_set(env, args[0], _m_idx, env->make_float(env, m[_m_idx]));
	}
	free(m);
	return Qnil;
}

emacs_value Fgl_mult_transpose_matrixf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat* m = (GLfloat*) calloc(16, sizeof(GLfloat));
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			m[_m_idx] = extract_double(env, env->vec_get(env, args[0], _m_idx));
	}
	glMultTransposeMatrixf(m);
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			env->vec_set(env, args[0], _m_idx, env->make_float(env, m[_m_idx]));
	}
	free(m);
	return Qnil;
}

emacs_value Fgl_mult_transpose_matrixd(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble* m = (GLdouble*) calloc(16, sizeof(GLdouble));
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			m[_m_idx] = extract_double(env, env->vec_get(env, args[0], _m_idx));
	}
	glMultTransposeMatrixd(m);
	{
		int _m_idx;
		for (_m_idx = 0; _m_idx < 16; _m_idx++)
			env->vec_set(env, args[0], _m_idx, env->make_float(env, m[_m_idx]));
	}
	free(m);
	return Qnil;
}

