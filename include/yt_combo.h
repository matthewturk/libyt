#ifndef __YT_COMBO_H__
#define __YT_COMBO_H__



/*******************************************************************************
/
/  This header includes various headers relevant for libyt just for convenience
/
********************************************************************************/


// Python-related headers
// ==> define NO_PYTHON for files having nothing to do with Python
#ifndef NO_PYTHON

// for using C-API in multiple files
// ==> note that NO_IMPORT_ARRAY must not be defined for the file calling import_array()
// reference: http://docs.scipy.org/doc/numpy/reference/c-api.array.html#importing-the-api
#ifndef CALL_IMPORT_ARRAY
#define NO_IMPORT_ARRAY
#endif
#define PY_ARRAY_UNIQUE_SYMBOL LIBYT_ARRAY_API

// to get rid of the warning messages about using deprecated NumPy API
#define NPY_NO_DEPRECATED_API NPY_API_VERSION

// Python.h must be included before any standard headers are included
#include <Python.h>
#include "numpy/arrayobject.h"

#endif // #ifndef NO_PYTHON


// standard headers
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


// libyt headers
#include "yt_macro.h"
#include "yt_type.h"
#include "yt_prototype.h"
#include "yt_global.h"

// for performance measuring
#ifdef SUPPORT_TIMER
#include "Timer.h"
#endif // #ifdef SUPPORT_TIMER

#endif // #ifndef __YT_COMBO_H__
