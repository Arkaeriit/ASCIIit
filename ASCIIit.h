/*------------------------------------------------------------------\
|This file contain function to transform a stream of random bytes to|
|a stream of ASCII chars and back.                                  |
\------------------------------------------------------------------*/

#ifndef ASCIIIT
#define ASCIIIT

#include <stdlib.h>
#include "boolArrayList.h"

#define PREFIX "0100"

char* Ai_ASCIIchar(char c);
char Ai_deASCIIchar(const char* str);

#endif

