#define MAX_ARRAY_LENGTH 20

#include <stdio.h>
#include "myheader.h"

#undef  FILE_SIZE
#define FILE_SIZE 42

#ifndef MESSAGE
  #define MESSAGE "You wish!"
#endif

#ifdef DEBUG
   /* Your debugging statements here */
#endif