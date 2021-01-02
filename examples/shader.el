(require 'xwidget)
(require 'gl)


(defun init-cb (width height)
  (gl-load)

  (let* ((vertex-shader (gl-create-shader GL-VERTEX-SHADER))
         (frag-shader (gl-create-shader GL-FRAGMENT-SHADER))
         (shader-program (gl-create-program))
         (vertex-source "#version 330 core
    layout (location = 0) in vec3 position;
    void main()
    {
    gl_Position = vec4(position, 1.0);
    }")
         (frag-source "#version 330 core
    out vec4 color;
    void main()
    {
    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    }")
         (buffer-handle [0])
         (vertices [-0.5 -0.5 0.0
                         0.5 -0.5 0.0
                         0.0  0.5 0.0])
         (vbo))
    (gl-shader-source vertex-shader 1 (vector vertex-source) nil)
    (gl-compile-shader vertex-shader)
    (gl-shader-source frag-shader 1 (vector frag-source) nil)
    (gl-compile-shader frag-shader)
    (gl-attach-shader shader-program vertex-shader)
    (gl-attach-shader shader-program frag-shader)
    (gl-link-program shader-program)
    (gl-delete-shader vertex-shader)
    (gl-delete-shader frag-shader)
    (setq program-handle shader-program)

    (gl-gen-vertex-arrays 1 buffer-handle)
    (setq vao (aref buffer-handle 0))
    (gl-gen-buffers 1 buffer-handle)
    (setq vbo (aref buffer-handle 0))
    (gl-bind-vertex-array vao)
    (gl-bind-buffer GL-ARRAY-BUFFER vbo)
    (gl-buffer-data GL-ARRAY-BUFFER (* 4 (length vertices)) vertices GL-STATIC-DRAW)

    (gl-vertex-attrib-pointer 0 3 GL-FLOAT GL-FALSE 12 0)
    (gl-enable-vertex-attrib-array 0)

    (gl-bind-buffer GL-ARRAY-BUFFER 0)
    (gl-bind-vertex-array 0)))

(defun render-cb ()
  (gl-clear-color 0.5 0.5 0.5 1.0)
  (gl-clear GL-COLOR-BUFFER-BIT)

  (gl-use-program program-handle)
  (gl-bind-vertex-array vao)
  (gl-draw-arrays GL-TRIANGLES 0 3)
  (gl-bind-vertex-array 0)
  )

(glarea-new :init #'init-cb :render #'render-cb)
