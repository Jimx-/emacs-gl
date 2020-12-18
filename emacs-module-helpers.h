/* From https://github.com/jkitchin/emacs-modules */
#include "emacs-module.h"

#ifndef EMACS_MODULE_HELPERS_H_
#define EMACS_MODULE_HELPERS_H_

//  from dbg.h in Learn C the Hard Way
#include <errno.h>
#include <stdio.h>
#include <string.h>

#ifdef NDEBEG
#define debug(M, ...)
#else
#define debug(M, ...) \
    fprintf(stderr, "DEBUG %s:%d ", M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...)                                                      \
    fprintf(stderr, "[ERROR] (%s:%d errno: %s) " M "\n", __FILE__, __LINE__, \
            clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...)                                                    \
    fprintf(stderr, "[WARN] (%s:%d errno: %s) " M "\n", __FILE__, __LINE__, \
            clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...)                                                    \
    fprintf(stderr, "[INFO] (%s:%d errno: %s) " M "\n", __FILE__, __LINE__, \
            clean_errno(), ##__VA_ARGS__)

#define check(A, M, ...)         \
    if (!(A)) {                  \
        log_err(M, ##VA_ARGS__); \
        errno = 0;               \
        goto error;              \
    }

#define sentinel(M, ...)         \
    {                            \
        log_err(M, ##VA_ARGS__); \
        errno = 0;               \
        goto error;              \
    }

#define check_mem(A) check((A), "Out of memory")

#define check_debug(A, M, ...)   \
    if (!(A)) {                  \
        debug(M, ##__VA_ARGS__); \
        errno = 0;               \
        goto error;              \
    }

/* Emacs symbols. */
extern emacs_value Qt;
extern emacs_value Qnil;

void defconsti(emacs_env* env, const char* name, int value, const char* doc);
void defconsts(emacs_env* env, const char* name, const char* value,
               const char* doc);
void defconst(emacs_env* env, const char* name, double value, const char* doc);

double extract_double(emacs_env* env, emacs_value arg);
int extract_integer(emacs_env* env, emacs_value arg);

emacs_value intern(emacs_env* env, const char* feature);

void bind_function(emacs_env* env, const char* name, emacs_value Sfun);
// I could not figure out how to define this as a function, so we use this
// define instead.
#define DEFUN(lsym, csym, amin, amax, doc, data) \
    bind_function(env, lsym,                     \
                  env->make_function(env, amin, amax, csym, doc, data))

void provide(emacs_env* env, const char* feature);
void require(emacs_env* env, const char* feature);

#endif // EMACS_MODULE_HELPERS_H_
