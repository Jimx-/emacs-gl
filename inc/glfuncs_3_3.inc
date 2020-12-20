emacs_value Fgl_gen_samplers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei count = extract_integer(env, args[0]);
	GLuint* samplers = (GLuint*) calloc(count, sizeof(GLuint));
	{
		int _samplers_idx;
		for (_samplers_idx = 0; _samplers_idx < count; _samplers_idx++)
			samplers[_samplers_idx] = extract_integer(env, env->vec_get(env, args[1], _samplers_idx));
	}
	glGenSamplers(count, samplers);
	{
		int _samplers_idx;
		for (_samplers_idx = 0; _samplers_idx < count; _samplers_idx++)
			env->vec_set(env, args[1], _samplers_idx, env->make_integer(env, samplers[_samplers_idx]));
	}
	free(samplers);
	return Qnil;
}

emacs_value Fgl_delete_samplers(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLsizei count = extract_integer(env, args[0]);
	GLuint* samplers = (GLuint*) calloc(count, sizeof(GLuint));
	{
		int _samplers_idx;
		for (_samplers_idx = 0; _samplers_idx < count; _samplers_idx++)
			samplers[_samplers_idx] = extract_integer(env, env->vec_get(env, args[1], _samplers_idx));
	}
	glDeleteSamplers(count, samplers);
	{
		int _samplers_idx;
		for (_samplers_idx = 0; _samplers_idx < count; _samplers_idx++)
			env->vec_set(env, args[1], _samplers_idx, env->make_integer(env, samplers[_samplers_idx]));
	}
	free(samplers);
	return Qnil;
}

emacs_value Fgl_is_sampler(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint sampler = extract_integer(env, args[0]);
	glIsSampler(sampler);
	return Qnil;
}

emacs_value Fgl_bind_sampler(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint unit = extract_integer(env, args[0]);
	GLuint sampler = extract_integer(env, args[1]);
	glBindSampler(unit, sampler);
	return Qnil;
}

emacs_value Fgl_sampler_parameteri(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint sampler = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLint param = extract_integer(env, args[2]);
	glSamplerParameteri(sampler, pname, param);
	return Qnil;
}

emacs_value Fgl_sampler_parameterf(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint sampler = extract_integer(env, args[0]);
	GLenum pname = extract_integer(env, args[1]);
	GLfloat param = extract_double(env, args[2]);
	glSamplerParameterf(sampler, pname, param);
	return Qnil;
}

emacs_value Fgl_query_counter(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint id = extract_integer(env, args[0]);
	GLenum target = extract_integer(env, args[1]);
	glQueryCounter(id, target);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_divisor(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint divisor = extract_integer(env, args[1]);
	glVertexAttribDivisor(index, divisor);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint value = extract_integer(env, args[3]);
	glVertexAttribP1ui(index, type, normalized, value);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p1uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint* value = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[3], _value_idx));
	}
	glVertexAttribP1uiv(index, type, normalized, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint value = extract_integer(env, args[3]);
	glVertexAttribP2ui(index, type, normalized, value);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p2uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint* value = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[3], _value_idx));
	}
	glVertexAttribP2uiv(index, type, normalized, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint value = extract_integer(env, args[3]);
	glVertexAttribP3ui(index, type, normalized, value);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint* value = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[3], _value_idx));
	}
	glVertexAttribP3uiv(index, type, normalized, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint value = extract_integer(env, args[3]);
	glVertexAttribP4ui(index, type, normalized, value);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_p4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint* value = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[3], _value_idx));
	}
	glVertexAttribP4uiv(index, type, normalized, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			env->vec_set(env, args[3], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_vertex_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint value = extract_integer(env, args[1]);
	glVertexP2ui(type, value);
	return Qnil;
}

emacs_value Fgl_vertex_p2uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* value = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[1], _value_idx));
	}
	glVertexP2uiv(type, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			env->vec_set(env, args[1], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_vertex_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint value = extract_integer(env, args[1]);
	glVertexP3ui(type, value);
	return Qnil;
}

emacs_value Fgl_vertex_p3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* value = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[1], _value_idx));
	}
	glVertexP3uiv(type, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			env->vec_set(env, args[1], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_vertex_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint value = extract_integer(env, args[1]);
	glVertexP4ui(type, value);
	return Qnil;
}

emacs_value Fgl_vertex_p4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* value = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			value[_value_idx] = extract_integer(env, env->vec_get(env, args[1], _value_idx));
	}
	glVertexP4uiv(type, value);
	{
		int _value_idx;
		for (_value_idx = 0; _value_idx < 1; _value_idx++)
			env->vec_set(env, args[1], _value_idx, env->make_integer(env, value[_value_idx]));
	}
	free(value);
	return Qnil;
}

emacs_value Fgl_tex_coord_p1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP1ui(type, coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p1uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[1], _coords_idx));
	}
	glTexCoordP1uiv(type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[1], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP2ui(type, coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p2uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[1], _coords_idx));
	}
	glTexCoordP2uiv(type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[1], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP3ui(type, coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[1], _coords_idx));
	}
	glTexCoordP3uiv(type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[1], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP4ui(type, coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[1], _coords_idx));
	}
	glTexCoordP4uiv(type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[1], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint coords = extract_integer(env, args[2]);
	glMultiTexCoordP1ui(texture, type, coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p1uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[2], _coords_idx));
	}
	glMultiTexCoordP1uiv(texture, type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[2], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint coords = extract_integer(env, args[2]);
	glMultiTexCoordP2ui(texture, type, coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p2uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[2], _coords_idx));
	}
	glMultiTexCoordP2uiv(texture, type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[2], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint coords = extract_integer(env, args[2]);
	glMultiTexCoordP3ui(texture, type, coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[2], _coords_idx));
	}
	glMultiTexCoordP3uiv(texture, type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[2], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint coords = extract_integer(env, args[2]);
	glMultiTexCoordP4ui(texture, type, coords);
	return Qnil;
}

emacs_value Fgl_multi_tex_coord_p4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[2], _coords_idx));
	}
	glMultiTexCoordP4uiv(texture, type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[2], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_normal_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glNormalP3ui(type, coords);
	return Qnil;
}

emacs_value Fgl_normal_p3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* coords = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			coords[_coords_idx] = extract_integer(env, env->vec_get(env, args[1], _coords_idx));
	}
	glNormalP3uiv(type, coords);
	{
		int _coords_idx;
		for (_coords_idx = 0; _coords_idx < 1; _coords_idx++)
			env->vec_set(env, args[1], _coords_idx, env->make_integer(env, coords[_coords_idx]));
	}
	free(coords);
	return Qnil;
}

emacs_value Fgl_color_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint color = extract_integer(env, args[1]);
	glColorP3ui(type, color);
	return Qnil;
}

emacs_value Fgl_color_p3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* color = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _color_idx;
		for (_color_idx = 0; _color_idx < 1; _color_idx++)
			color[_color_idx] = extract_integer(env, env->vec_get(env, args[1], _color_idx));
	}
	glColorP3uiv(type, color);
	{
		int _color_idx;
		for (_color_idx = 0; _color_idx < 1; _color_idx++)
			env->vec_set(env, args[1], _color_idx, env->make_integer(env, color[_color_idx]));
	}
	free(color);
	return Qnil;
}

emacs_value Fgl_color_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint color = extract_integer(env, args[1]);
	glColorP4ui(type, color);
	return Qnil;
}

emacs_value Fgl_color_p4uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* color = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _color_idx;
		for (_color_idx = 0; _color_idx < 1; _color_idx++)
			color[_color_idx] = extract_integer(env, env->vec_get(env, args[1], _color_idx));
	}
	glColorP4uiv(type, color);
	{
		int _color_idx;
		for (_color_idx = 0; _color_idx < 1; _color_idx++)
			env->vec_set(env, args[1], _color_idx, env->make_integer(env, color[_color_idx]));
	}
	free(color);
	return Qnil;
}

emacs_value Fgl_secondary_color_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint color = extract_integer(env, args[1]);
	glSecondaryColorP3ui(type, color);
	return Qnil;
}

emacs_value Fgl_secondary_color_p3uiv(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint* color = (GLuint*) calloc(1, sizeof(GLuint));
	{
		int _color_idx;
		for (_color_idx = 0; _color_idx < 1; _color_idx++)
			color[_color_idx] = extract_integer(env, env->vec_get(env, args[1], _color_idx));
	}
	glSecondaryColorP3uiv(type, color);
	{
		int _color_idx;
		for (_color_idx = 0; _color_idx < 1; _color_idx++)
			env->vec_set(env, args[1], _color_idx, env->make_integer(env, color[_color_idx]));
	}
	free(color);
	return Qnil;
}

