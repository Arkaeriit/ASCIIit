#include "main.h"

int main(int argc, char** argv){
    if (argc >= 2 && !strcmp("help",argv[1])){
        help();
        return 0;
    }else if(argc == 4){
        if(!strcmp(argv[1],"ASCII"))
            Ai_ASCIIcharFile(argv[2], argv[3]);
        else if(!strcmp(argv[1],"deASCII"))
            Ai_deASCIIcharFile(argv[2], argv[3]);
    }else{
        miniHelp();
        return 66;
    }
    return 0;
}

/*
 * Print to stderr an help message if there is an error in the
 * arguments given.
 */
void miniHelp(){
    fprintf(stderr, "Wrong argument, use \"asciiit help\" for help.\n");
}

/*
 * Print a complete help message to stdout.
 */
void help(){
    printf(
        "This program let you transform a file with any content into a file with only ASCII chars and tronsform it back.\n"
        "\nUsage : asciiit <option> <input file> <output file>\n"
        "Available options :\n"
        "    ASCII : transform any file into a ASCII only char\n"
        "    deASCII : transform back a file into it's original form.\n"
        "\nIf you want to use this command with piping you can use /dev/stdin and /dev/stdout as input or output file.\n"
    );
}

