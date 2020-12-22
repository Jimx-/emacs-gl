(require 'xwidget)
(require 'gl)

(defun init-cb (width height)
  (gl-load)

  (gl-helper-ui-init width height 'dark))

(defun render-cb ()
  "Render callback function."
  (gl-helper-ui-new-frame (/ 1.0 60.0))
  (draw-ui)

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

(let* ((buffer (get-buffer-create "*glarea-xwidget*"))
       (window (split-window (selected-window) 20)))
  (set-window-buffer window buffer)
  (with-current-buffer buffer
    (insert " ")
    (goto-char 1)
    (let ((id (make-xwidget
               'glarea
               nil
               1
               1
               '(:init init-cb
                       :render render-cb
                       :cursor-pos cursor-pos-cb
                       :mouse-button mouse-button-cb)
               (buffer-name))))
      (put-text-property (point) (+ 1 (point))
                         'display (list 'xwidget ':xwidget id)))))

