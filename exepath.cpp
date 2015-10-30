#include "exepath.h"

#if defined (_WIN32)
#include <direct.h>
#include <windows.h>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#else

#ifndef __USE_GNU
#define __USE_GNU
#include <dlfcn.h>
#undef __USE_GNU
#else
#include <dlfcn.h>
#endif

#endif

#include <string>

std::string exepath( void *main ) {
#if defined(_WIN32)
  char image[MAX_PATH];
  if (main) 
    GetModuleFileName(0, image, MAX_PATH);
  else 
    GetModuleFileName((HINSTANCE)&__ImageBase, image, MAX_PATH);
#else
  if (!main)
    main=(void*)exepath;
  Dl_info info;
  (void)dladdr(main, &info);
  const char *image = info.dli_fname;
#endif
  return std::string(image);
}
