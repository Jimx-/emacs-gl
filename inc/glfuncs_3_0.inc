emacs_value Fgl_color_maski(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLboolean r = extract_integer(env, args[1]);
	GLboolean g = extract_integer(env, args[2]);
	GLboolean b = extract_integer(env, args[3]);
	GLboolean a = extract_integer(env, args[4]);
	glColorMaski(index, r, g, b, a);
	return Qnil;
}

emacs_value Fgl_enablei(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glEnablei(target, index);
	return Qnil;
}

emacs_value Fgl_disablei(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glDisablei(target, index);
	return Qnil;
}

emacs_value Fgl_is_enabledi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glIsEnabledi(target, index);
	return Qnil;
}

emacs_value Fgl_begin_transform_feedback(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum primitiveMode = extract_integer(env, args[0]);
	glBeginTransformFeedback(primitiveMode);
	return Qnil;
}

emacs_value Fgl_end_transform_feedback(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glEndTransformFeedback();
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

emacs_value Fgl_clamp_color(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum clamp = extract_integer(env, args[1]);
	glClampColor(target, clamp);
	return Qnil;
}

emacs_value Fgl_begin_conditional_render(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint id = extract_integer(env, args[0]);
	GLenum mode = extract_integer(env, args[1]);
	glBeginConditionalRender(id, mode);
	return Qnil;
}

emacs_value Fgl_end_conditional_render(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	glEndConditionalRender();
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i1i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	glVertexAttribI1i(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i2i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	GLint y = extract_integer(env, args[2]);
	glVertexAttribI2i(index, x, y);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i3i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	GLint y = extract_integer(env, args[2]);
	GLint z = extract_integer(env, args[3]);
	glVertexAttribI3i(index, x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4i(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLint x = extract_integer(env, args[1]);
	GLint y = extract_integer(env, args[2]);
	GLint z = extract_integer(env, args[3]);
	GLint w = extract_integer(env, args[4]);
	glVertexAttribI4i(index, x, y, z, w);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	glVertexAttribI1ui(index, x);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	GLuint y = extract_integer(env, args[2]);
	glVertexAttribI2ui(index, x, y);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	GLuint y = extract_integer(env, args[2]);
	GLuint z = extract_integer(env, args[3]);
	glVertexAttribI3ui(index, x, y, z);
	return Qnil;
}

emacs_value Fgl_vertex_attrib_i4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint index = extract_integer(env, args[0]);
	GLuint x = extract_integer(env, args[1]);
	GLuint y = extract_integer(env, args[2]);
	GLuint z = extract_integer(env, args[3]);
	GLuint w = extract_integer(env, args[4]);
	glVertexAttribI4ui(index, x, y, z, w);
	return Qnil;
}

emacs_value Fgl_uniform1ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	glUniform1ui(location, v0);
	return Qnil;
}

emacs_value Fgl_uniform2ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	GLuint v1 = extract_integer(env, args[2]);
	glUniform2ui(location, v0, v1);
	return Qnil;
}

emacs_value Fgl_uniform3ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	GLuint v1 = extract_integer(env, args[2]);
	GLuint v2 = extract_integer(env, args[3]);
	glUniform3ui(location, v0, v1, v2);
	return Qnil;
}

emacs_value Fgl_uniform4ui(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint location = extract_integer(env, args[0]);
	GLuint v0 = extract_integer(env, args[1]);
	GLuint v1 = extract_integer(env, args[2]);
	GLuint v2 = extract_integer(env, args[3]);
	GLuint v3 = extract_integer(env, args[4]);
	glUniform4ui(location, v0, v1, v2, v3);
	return Qnil;
}

emacs_value Fgl_clear_bufferfi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum buffer = extract_integer(env, args[0]);
	GLint drawbuffer = extract_integer(env, args[1]);
	GLfloat depth = extract_double(env, args[2]);
	GLint stencil = extract_integer(env, args[3]);
	glClearBufferfi(buffer, drawbuffer, depth, stencil);
	return Qnil;
}

emacs_value Fgl_get_stringi(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum name = extract_integer(env, args[0]);
	GLuint index = extract_integer(env, args[1]);
	glGetStringi(name, index);
	return Qnil;
}

emacs_value Fgl_is_renderbuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint renderbuffer = extract_integer(env, args[0]);
	glIsRenderbuffer(renderbuffer);
	return Qnil;
}

emacs_value Fgl_bind_renderbuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint renderbuffer = extract_integer(env, args[1]);
	glBindRenderbuffer(target, renderbuffer);
	return Qnil;
}

emacs_value Fgl_renderbuffer_storage(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum internalformat = extract_integer(env, args[1]);
	GLsizei width = extract_integer(env, args[2]);
	GLsizei height = extract_integer(env, args[3]);
	glRenderbufferStorage(target, internalformat, width, height);
	return Qnil;
}

emacs_value Fgl_is_framebuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint framebuffer = extract_integer(env, args[0]);
	glIsFramebuffer(framebuffer);
	return Qnil;
}

emacs_value Fgl_bind_framebuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLuint framebuffer = extract_integer(env, args[1]);
	glBindFramebuffer(target, framebuffer);
	return Qnil;
}

emacs_value Fgl_check_framebuffer_status(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	glCheckFramebufferStatus(target);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture1_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum textarget = extract_integer(env, args[2]);
	GLuint texture = extract_integer(env, args[3]);
	GLint level = extract_integer(env, args[4]);
	glFramebufferTexture1D(target, attachment, textarget, texture, level);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture2_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum textarget = extract_integer(env, args[2]);
	GLuint texture = extract_integer(env, args[3]);
	GLint level = extract_integer(env, args[4]);
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture3_d(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum textarget = extract_integer(env, args[2]);
	GLuint texture = extract_integer(env, args[3]);
	GLint level = extract_integer(env, args[4]);
	GLint zoffset = extract_integer(env, args[5]);
	glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
	return Qnil;
}

emacs_value Fgl_framebuffer_renderbuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLenum renderbuffertarget = extract_integer(env, args[2]);
	GLuint renderbuffer = extract_integer(env, args[3]);
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
	return Qnil;
}

emacs_value Fgl_generate_mipmap(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	glGenerateMipmap(target);
	return Qnil;
}

emacs_value Fgl_blit_framebuffer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLint srcX0 = extract_integer(env, args[0]);
	GLint srcY0 = extract_integer(env, args[1]);
	GLint srcX1 = extract_integer(env, args[2]);
	GLint srcY1 = extract_integer(env, args[3]);
	GLint dstX0 = extract_integer(env, args[4]);
	GLint dstY0 = extract_integer(env, args[5]);
	GLint dstX1 = extract_integer(env, args[6]);
	GLint dstY1 = extract_integer(env, args[7]);
	GLbitfield mask = extract_integer(env, args[8]);
	GLenum filter = extract_integer(env, args[9]);
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	return Qnil;
}

emacs_value Fgl_renderbuffer_storage_multisample(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLsizei samples = extract_integer(env, args[1]);
	GLenum internalformat = extract_integer(env, args[2]);
	GLsizei width = extract_integer(env, args[3]);
	GLsizei height = extract_integer(env, args[4]);
	glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
	return Qnil;
}

emacs_value Fgl_framebuffer_texture_layer(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLenum target = extract_integer(env, args[0]);
	GLenum attachment = extract_integer(env, args[1]);
	GLuint texture = extract_integer(env, args[2]);
	GLint level = extract_integer(env, args[3]);
	GLint layer = extract_integer(env, args[4]);
	glFramebufferTextureLayer(target, attachment, texture, level, layer);
	return Qnil;
}

emacs_value Fgl_bind_vertex_array(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint array = extract_integer(env, args[0]);
	glBindVertexArray(array);
	return Qnil;
}

emacs_value Fgl_is_vertex_array(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)
{
	GLuint array = extract_integer(env, args[0]);
	glIsVertexArray(array);
	return Qnil;
}

