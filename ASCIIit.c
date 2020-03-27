/*------------------------------------------------------------------\
|This file contain function to transform a stream of random bytes to|
|a stream of ASCII chars and back.                                  |
\------------------------------------------------------------------*/

#include "ASCIIit.h"

/*
 * Take a char and return a string of two char each starting with a 4
 * bit suffix followed by a hafl of the input char.
 *  Argument:
 *      A char
 *  return:
 *      A string of two ASCII chars
 */
char* Ai_ASCIIchar(char c){
    boolArrayList* in = bal_stringToBal(&c, 1); //In a first time we create a bal with the desired returned bits
    boolArrayList* out = bal_binToBal( PREFIX );
    bal_concatDel( out, bal_subBal(in,0,3));
    bal_concatDel( out, bal_binToBal( PREFIX ));
    bal_concatDel( out, bal_subBal(in,4,7));
    char* ret = malloc(2); //Then we copy what we created on a string
    ret[0] = bal_readChar(out->a);
    ret[1] = bal_readChar(out->a + 8);
    bal_free(in); //Finally, we clean everything up
    bal_free(out);
    return ret;
}

/*
 * Take a string of two chars and return a char made by the second
 * half of each of the chars from the strings.
 *  Arguments:
 *      A two char long string
 *  return:
 *      The second half of each of the chars
 */
char Ai_deASCIIchar(const char* str){
    boolArrayList* in = bal_stringToBal(str, 2);
    boolArrayList* out = bal_subBal(in, 4, 7);
    bal_concatDel(out, bal_subBal(in, 12, 15));
    char ret = bal_readChar(out->a);
    bal_free(out);
    bal_free(in);
    return ret;
}

