(require 'xwidget)
(require 'gl)

(defun init-cb (width height)
  (gl-load))

(defun render-cb ()
  (gl-clear-color 0.5 0.5 0.5 1.0)
  (gl-clear GL-COLOR-BUFFER-BIT)

  (gl-matrix-mode GL-PROJECTION)
  (gl-load-identity)

  (gl-matrix-mode GL-MODELVIEW)
  (gl-load-identity)

  (gl-begin GL-TRIANGLES)
  (gl-color3f 1.0 0.0 0.0)
  (gl-vertex3f -0.75 -0.75 0)
  (gl-color3f 0.0 1.0 0.0)
  (gl-vertex3f 0.75 -0.75 0)
  (gl-color3f 0.0 0.0 1.0)
  (gl-vertex3f 0.0 0.75 0)
  (gl-end))

(glarea-new :init #'init-cb :render #'render-cb)
