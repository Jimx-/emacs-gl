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

emacs_value Fgl_vertex_attrib_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint value = extract_integer(env, args[3]);
	glVertexAttribP2ui(index, type, normalized, value);
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

emacs_value Fgl_vertex_attrib_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLboolean normalized = extract_integer(env, args[2]);
	GLuint value = extract_integer(env, args[3]);
	glVertexAttribP4ui(index, type, normalized, value);
	return Qnil;
}

emacs_value Fgl_vertex_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint value = extract_integer(env, args[1]);
	glVertexP2ui(type, value);
	return Qnil;
}

emacs_value Fgl_vertex_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint value = extract_integer(env, args[1]);
	glVertexP3ui(type, value);
	return Qnil;
}

emacs_value Fgl_vertex_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint value = extract_integer(env, args[1]);
	glVertexP4ui(type, value);
	return Qnil;
}

emacs_value Fgl_tex_coord_p1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP1ui(type, coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP2ui(type, coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP3ui(type, coords);
	return Qnil;
}

emacs_value Fgl_tex_coord_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glTexCoordP4ui(type, coords);
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

emacs_value Fgl_multi_tex_coord_p2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint coords = extract_integer(env, args[2]);
	glMultiTexCoordP2ui(texture, type, coords);
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

emacs_value Fgl_multi_tex_coord_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum texture = extract_integer(env, args[0]);
	GLenum type = extract_integer(env, args[1]);
	GLuint coords = extract_integer(env, args[2]);
	glMultiTexCoordP4ui(texture, type, coords);
	return Qnil;
}

emacs_value Fgl_normal_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint coords = extract_integer(env, args[1]);
	glNormalP3ui(type, coords);
	return Qnil;
}

emacs_value Fgl_color_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint color = extract_integer(env, args[1]);
	glColorP3ui(type, color);
	return Qnil;
}

emacs_value Fgl_color_p4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint color = extract_integer(env, args[1]);
	glColorP4ui(type, color);
	return Qnil;
}

emacs_value Fgl_secondary_color_p3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum type = extract_integer(env, args[0]);
	GLuint color = extract_integer(env, args[1]);
	glSecondaryColorP3ui(type, color);
	return Qnil;
}

