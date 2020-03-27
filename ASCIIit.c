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

/*
 * Take a file, ASCIIchar all of its content and put the result
 * in a second file
 *  Arguments:
 *      file_in : the input file
 *      file_out : the output file
 *  errors:
 *      If the input file can't be opened an error message will
 *      be printed and the program will stop with exit code 61
 *      If the output file can't be opened an error message will
 *      be printed and the program will stop with exit code 63
 */
void Ai_ASCIIcharFile(const char* in, const char* out){
    FILE *fin, *fout; //We oppen the files
    if( (fin = fopen(in,"r")) == NULL) {
        fprintf(stderr, "Error : impossible to read the file : %s\n", in);
        exit(61);
    }
    if( (fout = fopen(out,"w")) == NULL) {
        fprintf(stderr, "Error : impossible to open the file : %s\n", out);
        exit(63);
    }
    while(!feof(fin)){
        int c = fgetc(fin);
        if(c != 0xFFFFFFFF){
            char* toFout = Ai_ASCIIchar(c);
            printf("%c %x %c%c\n",c,c, toFout[0], toFout[1]);
            fwrite(toFout, 2, 1, fout);
            free(toFout);
        }
    }
    fclose(fin);
    fclose(fout);
}

