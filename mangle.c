#include "libcommon/common.h"
#include "mangle.h"

#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include "libcommon/log.h"
#include "libcommon/util.h"

#include <Python.h>


static bool inited = false;
PyObject *genfunc;

void mangle_mangleContent(honggfuzz_t * hfuzz, fuzzer_t * fuzzer)
{
   if (!inited) {

         Py_SetProgramName("honggdharma");
         Py_Initialize();

         PyObject *sysmodule = PyImport_ImportModule("sys");
         PyObject *syspath = PyObject_GetAttrString(sysmodule, "path");
         PyList_Append(syspath, PyString_FromString("."));
         Py_DECREF(syspath);
         Py_DECREF(sysmodule);

         PyObject *mod = PyImport_ImportModule("honggdharma");

         if (mod != NULL) {

              genfunc = PyObject_GetAttrString(mod, "generate");

         } else {

            printf("\nUnable to load honggdharma.py!\n");
            exit(1);

         }


         inited = true;

   }


   char *tc = PyString_AsString(PyObject_CallObject(genfunc, NULL));
   size_t len = strlen(tc);


   if (len > (hfuzz->maxFileSz)) {
      return;
   }

   memmove(&fuzzer->dynamicFile[0], tc, len + 1);

}
