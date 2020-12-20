/* From https://github.com/jkitchin/emacs-modules */
#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <stdlib.h>
#include <string.h>

emacs_value Qt;
emacs_value Qnil;

// Extract a number as a double from arg. ints are cast as floats.
double extract_double(emacs_env* env, emacs_value arg)
{
    emacs_value type = env->type_of(env, arg);
    double result = 0.0;
    if (env->eq(env, type, env->intern(env, "integer"))) {
        result = (float)env->extract_integer(env, arg);
    } else if (env->eq(env, type, env->intern(env, "float"))) {
        result = env->extract_float(env, arg);
    }
    return result;
}

// Extract a number as an integer from arg. floats are cast as ints.
int extract_integer(emacs_env* env, emacs_value arg)
{
    emacs_value type = env->type_of(env, arg);
    int result = 0;
    if (env->eq(env, type, env->intern(env, "integer"))) {
        result = env->extract_integer(env, arg);
    } else if (env->eq(env, type, env->intern(env, "float"))) {
        result = (int)env->extract_float(env, arg);
    }
    return result;
}

char* copy_string_contents(emacs_env* env, emacs_value arg, size_t* len)
{
    char* buffer;
    ptrdiff_t buf_size;

    if (!env->copy_string_contents(env, arg, NULL, &buf_size)) return NULL;

    buffer = malloc(buf_size);
    if (!buffer) return NULL;

    if (!env->copy_string_contents(env, arg, buffer, &buf_size)) {
        free(buffer);
        return NULL;
    }

    if (len) *len = buf_size;
    return buffer;
}

// define a constant that is an integer in emacs
void defconsti(emacs_env* env, const char* name, int value, const char* doc)
{
    // These are functions we will call
    emacs_value eval = env->intern(env, "eval");
    emacs_value list = env->intern(env, "list");

    // These will make up the list we will eventually eval
    emacs_value fdefconst = env->intern(env, "defconst");
    emacs_value sym = env->intern(env, name);
    emacs_value val = env->make_integer(env, value);
    emacs_value sdoc = env->make_string(env, doc, strlen(doc));

    // make a list of (defconst sym val doc)
    emacs_value largs[] = {fdefconst, sym, val, sdoc};
    emacs_value qlist = env->funcall(env, list, 4, largs);

    // now eval the list of symbols
    emacs_value args[] = {qlist};
    env->funcall(env, eval, 1, args);
}

// define a constant that is a string in Emacs
void defconsts(emacs_env* env, const char* name, const char* value,
               const char* doc)
{
    // These are functions we will call
    emacs_value eval = env->intern(env, "eval");
    emacs_value list = env->intern(env, "list");

    // These will make up the list we will eventually eval
    emacs_value fdefconst = env->intern(env, "defconst");
    emacs_value sym = env->intern(env, name);
    emacs_value val = env->make_string(env, value, strlen(value));
    emacs_value sdoc = env->make_string(env, doc, strlen(doc));

    // make a list of (defconst sym val doc)
    emacs_value largs[] = {fdefconst, sym, val, sdoc};
    emacs_value qlist = env->funcall(env, list, 4, largs);

    // now eval the list of symbols
    emacs_value args[] = {qlist};
    env->funcall(env, eval, 1, args);
}

// define a constant that is a float in Emacs
void defconst(emacs_env* env, const char* name, double value, const char* doc)
{
    // These are functions we will call
    emacs_value eval = env->intern(env, "eval");
    emacs_value list = env->intern(env, "list");

    // These will make up the list we will eventually eval
    emacs_value fdefconst = env->intern(env, "defconst");
    emacs_value sym = env->intern(env, name);
    emacs_value val = env->make_float(env, value);
    emacs_value sdoc = env->make_string(env, doc, strlen(doc));

    // make a list of (defconst sym val doc)
    emacs_value largs[] = {fdefconst, sym, val, sdoc};
    emacs_value qlist = env->funcall(env, list, 4, largs);

    // now eval the list of symbols
    emacs_value args[] = {qlist};
    env->funcall(env, eval, 1, args);
}

// bind a function with emacs name to the symbol Sfun
// (fset symbol definition)
// This is usually used with the DEFUN macro
void bind_function(emacs_env* env, const char* name, emacs_value Sfun)
{
    /* Set the function cell of the symbol named NAME to SFUN using
       the 'fset' function.  */

    /* Convert the strings to symbols by interning them */
    emacs_value Qfset = env->intern(env, "fset");
    emacs_value Qsym = env->intern(env, name);

    /* Prepare the arguments array */
    emacs_value args[] = {Qsym, Sfun};

    /* Make the call (2 == nb of arguments) */
    env->funcall(env, Qfset, 2, args);
}

void provide(emacs_env* env, const char* feature)
{
    emacs_value Qfeat = env->intern(env, feature);
    emacs_value Qprovide = env->intern(env, "provide");
    emacs_value args[] = {Qfeat};

    env->funcall(env, Qprovide, 1, args);
}

// This is a smidge shorter than env->intern (env, feature)
// intern(env, feature)
emacs_value intern(emacs_env* env, const char* feature)
{
    return env->intern(env, feature);
}

// require("feature")
// This is for use in a module
void require(emacs_env* env, const char* feature)
{
    emacs_value args[] = {intern(env, feature)};
    env->funcall(env, intern(env, "require"), 1, args);
}
