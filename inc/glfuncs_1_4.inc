emacs_value Fgl_blend_func_separate(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum sfactorRGB = extract_integer(env, args[0]);
	GLenum dfactorRGB = extract_integer(env, args[1]);
	GLenum sfactorAlpha = extract_integer(env, args[2]);
	GLenum dfactorAlpha = extract_integer(env, args[3]);
	glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	return Qnil;
}

emacs_value Fgl_point_parameterf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLfloat param = extract_double(env, args[1]);
	glPointParameterf(pname, param);
	return Qnil;
}

emacs_value Fgl_point_parameteri(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum pname = extract_integer(env, args[0]);
	GLint param = extract_integer(env, args[1]);
	glPointParameteri(pname, param);
	return Qnil;
}

emacs_value Fgl_fog_coordf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat coord = extract_double(env, args[0]);
	glFogCoordf(coord);
	return Qnil;
}

emacs_value Fgl_fog_coordfv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat* coord = (GLfloat*) calloc(1, sizeof(GLfloat));
	{
		int _coord_idx;
		for (_coord_idx = 0; _coord_idx < 1; _coord_idx++)
			coord[_coord_idx] = extract_double(env, env->vec_get(env, args[0], _coord_idx));
	}
	glFogCoordfv(coord);
	{
		int _coord_idx;
		for (_coord_idx = 0; _coord_idx < 1; _coord_idx++)
			env->vec_set(env, args[0], _coord_idx, env->make_float(env, coord[_coord_idx]));
	}
	free(coord);
	return Qnil;
}

emacs_value Fgl_fog_coordd(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble coord = extract_double(env, args[0]);
	glFogCoordd(coord);
	return Qnil;
}

emacs_value Fgl_fog_coorddv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble* coord = (GLdouble*) calloc(1, sizeof(GLdouble));
	{
		int _coord_idx;
		for (_coord_idx = 0; _coord_idx < 1; _coord_idx++)
			coord[_coord_idx] = extract_double(env, env->vec_get(env, args[0], _coord_idx));
	}
	glFogCoorddv(coord);
	{
		int _coord_idx;
		for (_coord_idx = 0; _coord_idx < 1; _coord_idx++)
			env->vec_set(env, args[0], _coord_idx, env->make_float(env, coord[_coord_idx]));
	}
	free(coord);
	return Qnil;
}

emacs_value Fgl_secondary_color3b(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbyte red = extract_integer(env, args[0]);
	GLbyte green = extract_integer(env, args[1]);
	GLbyte blue = extract_integer(env, args[2]);
	glSecondaryColor3b(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3bv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLbyte* v = (GLbyte*) calloc(3, sizeof(GLbyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3bv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_secondary_color3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble red = extract_double(env, args[0]);
	GLdouble green = extract_double(env, args[1]);
	GLdouble blue = extract_double(env, args[2]);
	glSecondaryColor3d(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble* v = (GLdouble*) calloc(3, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3dv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_secondary_color3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	glSecondaryColor3f(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat* v = (GLfloat*) calloc(3, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3fv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_secondary_color3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint red = extract_integer(env, args[0]);
	GLint green = extract_integer(env, args[1]);
	GLint blue = extract_integer(env, args[2]);
	glSecondaryColor3i(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint* v = (GLint*) calloc(3, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3iv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_secondary_color3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort red = extract_integer(env, args[0]);
	GLshort green = extract_integer(env, args[1]);
	GLshort blue = extract_integer(env, args[2]);
	glSecondaryColor3s(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort* v = (GLshort*) calloc(3, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3sv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_secondary_color3ub(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte red = extract_integer(env, args[0]);
	GLubyte green = extract_integer(env, args[1]);
	GLubyte blue = extract_integer(env, args[2]);
	glSecondaryColor3ub(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3ubv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLubyte* v = (GLubyte*) calloc(3, sizeof(GLubyte));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3ubv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_secondary_color3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint red = extract_integer(env, args[0]);
	GLuint green = extract_integer(env, args[1]);
	GLuint blue = extract_integer(env, args[2]);
	glSecondaryColor3ui(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint* v = (GLuint*) calloc(3, sizeof(GLuint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3uiv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_secondary_color3us(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLushort red = extract_integer(env, args[0]);
	GLushort green = extract_integer(env, args[1]);
	GLushort blue = extract_integer(env, args[2]);
	glSecondaryColor3us(red, green, blue);
	return Qnil;
}

emacs_value Fgl_secondary_color3usv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLushort* v = (GLushort*) calloc(3, sizeof(GLushort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glSecondaryColor3usv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos2d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	glWindowPos2d(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos2dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble* v = (GLdouble*) calloc(2, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos2dv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos2f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	glWindowPos2f(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos2fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat* v = (GLfloat*) calloc(2, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos2fv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	glWindowPos2i(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos2iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint* v = (GLint*) calloc(2, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos2iv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos2s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	glWindowPos2s(x, y);
	return Qnil;
}

emacs_value Fgl_window_pos2sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort* v = (GLshort*) calloc(2, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos2sv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 2; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos3d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble x = extract_double(env, args[0]);
	GLdouble y = extract_double(env, args[1]);
	GLdouble z = extract_double(env, args[2]);
	glWindowPos3d(x, y, z);
	return Qnil;
}

emacs_value Fgl_window_pos3dv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLdouble* v = (GLdouble*) calloc(3, sizeof(GLdouble));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos3dv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat x = extract_double(env, args[0]);
	GLfloat y = extract_double(env, args[1]);
	GLfloat z = extract_double(env, args[2]);
	glWindowPos3f(x, y, z);
	return Qnil;
}

emacs_value Fgl_window_pos3fv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat* v = (GLfloat*) calloc(3, sizeof(GLfloat));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_double(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos3fv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_float(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint x = extract_integer(env, args[0]);
	GLint y = extract_integer(env, args[1]);
	GLint z = extract_integer(env, args[2]);
	glWindowPos3i(x, y, z);
	return Qnil;
}

emacs_value Fgl_window_pos3iv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint* v = (GLint*) calloc(3, sizeof(GLint));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos3iv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_window_pos3s(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort x = extract_integer(env, args[0]);
	GLshort y = extract_integer(env, args[1]);
	GLshort z = extract_integer(env, args[2]);
	glWindowPos3s(x, y, z);
	return Qnil;
}

emacs_value Fgl_window_pos3sv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLshort* v = (GLshort*) calloc(3, sizeof(GLshort));
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			v[_v_idx] = extract_integer(env, env->vec_get(env, args[0], _v_idx));
	}
	glWindowPos3sv(v);
	{
		int _v_idx;
		for (_v_idx = 0; _v_idx < 3; _v_idx++)
			env->vec_set(env, args[0], _v_idx, env->make_integer(env, v[_v_idx]));
	}
	free(v);
	return Qnil;
}

emacs_value Fgl_blend_color(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLfloat red = extract_double(env, args[0]);
	GLfloat green = extract_double(env, args[1]);
	GLfloat blue = extract_double(env, args[2]);
	GLfloat alpha = extract_double(env, args[3]);
	glBlendColor(red, green, blue, alpha);
	return Qnil;
}

emacs_value Fgl_blend_equation(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum mode = extract_integer(env, args[0]);
	glBlendEquation(mode);
	return Qnil;
}

