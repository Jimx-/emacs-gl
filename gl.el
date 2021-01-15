;;; gl.el --- OpenGL bindings for Emacs -*- lexical-binding: t; -*-

;; Copyright (C) 2020-2021 by Jin Xue
;;
;; Author: Jin Xue <csjinxue@outlook.com>
;; Version: 0.0.1
;; URL: https://github.com/Jimx-/emacs-gl
;; Keywords: graphics
;; Package-Requires: ((emacs "28.0"))


;; This file is not part of GNU Emacs.

;; This file is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 2, or (at your option)
;; any later version.

;; This file is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GNU Emacs.  If not, see <https://www.gnu.org/licenses/>.

;;; Commentary:
;;;
;;; OpenGL bindings for Emacs Lisp.  It enables drawing to Emacs buffers
;;; with OpenGL through a GLArea xwidget embedded in the buffers.

;;; Code:

(require 'xwidget)

(unless (require 'gl-module nil t)
  (error "GL will not work unless `gl-module' is compiled!"))

(require 'gl-decl)

(defvar-local gl--xwidget nil
  "Current GLArea xwidget.")

(defun gl--self-insert ()
  "Send invoking key to GL module."
  (interactive)
  (when gl--xwidget
    (let* ((modifiers (event-modifiers last-input-event))
           (shift (memq 'shift modifiers))
           (meta (memq 'meta modifiers))
           (ctrl (memq 'control modifiers)))
      (when-let ((key (key-description (vector (event-basic-type last-input-event)))))
        (gl-send-key key shift meta ctrl)))))

(defun gl-send-key (key &optional shift meta ctrl)
  "Send KEY to GL module with optional modifiers SHIFT, META and CTRL."
  (when gl--xwidget
    (let ((inhibit-redisplay t)
          (inhibit-read-only t))
      (when (and (not (symbolp last-input-event)) shift (not meta) (not ctrl))
        (setq key (upcase key)))
      (gl-helper-ui-send-key key shift meta ctrl)
      (xwidget-queue-redraw gl--xwidget))))

(defun gl-send-backspace ()
  "Send `<backspace>' to GL module."
  (interactive)
  (gl-send-key "<backspace>"))

(defun gl-send-delete ()
  "Send `<delete>' to GL module."
  (interactive)
  (gl-send-key "<delete>"))

(defun gl-send-tab ()
  "Send `<tab>' to GL module."
  (interactive)
  (gl-send-key "<tab>"))

(defun gl-send-return ()
  "Send `<return>' to GL module."
  (interactive)
  (gl-send-key "<return>"))

(defun gl-send-left ()
  "Send `<left>' to GL module."
  (interactive)
  (gl-send-key "<left>"))

(defun gl-send-right ()
  "Send `<right>' to GL module."
  (interactive)
  (gl-send-key "<right>"))

(defun gl-send-up ()
  "Send `<up>' to GL module."
  (interactive)
  (gl-send-key "<up>"))

(defun gl-send-down ()
  "Send `<down>' to GL module."
  (interactive)
  (gl-send-key "<down>"))

(defvar gl-mode-map
  (let ((map (make-sparse-keymap)))
    (define-key map [tab]                       #'gl-send-tab)
    (define-key map (kbd "TAB")                 #'gl-send-tab)
    (define-key map [return]                    #'gl-send-return)
    (define-key map (kbd "RET")                 #'gl-send-return)
    (define-key map [backspace]                 #'gl-send-backspace)
    (define-key map (kbd "DEL")                 #'gl-send-backspace)
    (define-key map [delete]                    #'gl-send-delete)
    (define-key map [left]                      #'gl-send-left)
    (define-key map [right]                     #'gl-send-right)
    (define-key map [up]                        #'gl-send-up)
    (define-key map [down]                      #'gl-send-down)
    (define-key map [home]                      #'gl--self-insert)
    (define-key map [end]                       #'gl--self-insert)
    (define-key map [C-home]                    #'gl--self-insert)
    (define-key map [C-end]                     #'gl--self-insert)
    (define-key map [escape]                    #'gl--self-insert)
    (define-key map [remap self-insert-command] #'gl--self-insert)
    map))

(define-derived-mode gl-mode fundamental-mode "GL"
  "Major mode for GL buffer."
  (buffer-disable-undo)

  (setq gl--xwidget (xwidget-at (point-min)))
  (setq buffer-read-only t))

(defun glarea-new (&rest args)
  "Create a new GLArea xwidget with a new buffer."
  (let ((buffer (generate-new-buffer (or (plist-get args :name) "*glarea*"))))
    (with-current-buffer buffer
      (insert " ")
      (goto-char 1)
      (let ((id (make-xwidget 'glarea nil 1 1 args (buffer-name))))
        (put-text-property (point) (+ 1 (point))
                           'display (list 'xwidget ':xwidget id)))
      (gl-mode)
      (switch-to-buffer buffer))))

(provide 'gl)
;;; gl.el ends here
