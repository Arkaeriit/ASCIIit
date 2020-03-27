/*------------------------------------------------------------------\
|This file contain function to transform a stream of random bytes to|
|a stream of ASCII chars and back.                                  |
\------------------------------------------------------------------*/

#ifndef ASCIIIT
#define ASCIIIT

#include <stdlib.h>
#include <stdio.h>
#include "boolArrayList.h"

#define PREFIX "0100"

char* Ai_ASCIIchar(char c);
char Ai_deASCIIchar(const char* str);

void Ai_ASCIIcharFile(const char* in, const char* out);
void Ai_deASCIIcharFile(const char* in, const char* out);
#endif

