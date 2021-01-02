(require 'xwidget)
(require 'gl)

(defvar widget nil)

(defun init-cb (width height)
  (gl-load)

  (gl-helper-ui-init width height 'dark))

(defun render-cb ()
  (gl-clear-color 0.5 0.5 0.5 1.0)
  (gl-clear GL-COLOR-BUFFER-BIT)

  (gl-helper-ui-new-frame (/ 1.0 60.0))

  (gl-helper-ui-begin-window "Hello, world!")
  (gl-helper-ui-text "Emacs is the best editor.")
  (gl-helper-ui-button "OK")
  (gl-helper-ui-end-window)

  (gl-helper-ui-render))

(defun cursor-pos-cb (x y)
  (gl-helper-ui-cursor-pos-callback x y)
  (xwidget-queue-redraw widget))

(defun mouse-button-cb (button action)
  (gl-helper-ui-mouse-button-callback button action)
  (xwidget-queue-redraw widget))

(let ((buffer (glarea-new :init #'init-cb
                          :render #'render-cb
                          :cursor-pos #'cursor-pos-cb
                          :mouse-button #'mouse-button-cb)))
  (with-current-buffer buffer
    (setq widget (xwidget-at 1))))
