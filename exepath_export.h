#ifndef exepath_export_h
#define exepath_export_h

#ifdef _WIN32
#  ifdef EXEPATH_STATIC_DEFINE
#    define EXEPATH_EXPORT
#  else
#    ifndef EXEPATH_EXPORT
#      ifdef BUILDING_EXEPATH
         /* We are building this library */
#        define EXEPATH_EXPORT __declspec(dllexport)
#      else
         /* We are using this library */
#        define EXEPATH_EXPORT __declspec(dllimport)
#      endif
#    endif
#  endif
#else
#  define EXEPATH_EXPORT
#endif

#endif
