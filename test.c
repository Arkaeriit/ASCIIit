#include "boolArrayList.h"
#include "ASCIIit.h"

int main(){
    boolArrayList* file = bal_readFile("in1");
    boolArrayList* str = bal_binToBal("01000000"); // @
#define STR1 "Le Soleil brille et rougit tes joues\nMon amour file comme le vent sur la proue"
    boolArrayList* str2 = bal_stringToBal( STR1, strlen(STR1));
    boolArrayList* vd = bal_init();
    for(int i=0; i<8; i++)
        bal_append(vd, false);
    vd->a[1] = true;
    vd->a[2] = true; // `
    bal_writeFile(file, "out1");
    bal_writeFile(str, "out2");
    bal_writeFile(vd, "out3");
    bal_concatDel(vd, str); //`@
    bal_writeFile(vd, "out4");
    bal_writeFile(str2, "out5");

    boolArrayList* sTT = bal_stringToBal("ab", 2);
    boolArrayList* sBB = bal_subBal(sTT, 8, 15);
    bal_writeFile(sBB, "/dev/stdout");
    printf("\n");

    char c = '*';
    char* cc = Ai_ASCIIchar(c);
    printf("%c%c\n",cc[0],cc[1]);
    printf("%c\n",Ai_deASCIIchar(cc));

    return 0;
}

