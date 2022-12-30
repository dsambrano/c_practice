#include <stdio.h>
#include <string.h>

// This is all about reading user inputs

// So I already learned that you should not have main return void from SO, but
// here we learn that usually you want main to read in arguments from the
// command line. This is done somewhat similar to a combination of bash and
// python so not too hard. First is argc, which is the count of input arguments
// but like with bash (and python?) it includes the program as 1, so the actual
// argumnets start at argc[2].
//
// Next we have *argv[], which is a pointer to the actual argumnet strings.
//
// Just as noted in SO return 0 means succes, but it doesnt seem to matter for
// microcontollers since it will likely just repeat anyways.
int main(int argc, char *argv[]){
    int arg1, arg2;
    if (argc == 4){
        sscanf(argv[1], "%d", &arg1);
        sscanf(argv[3], "%d", &arg2);
        /*printf("What is argv[2]? '%s'", argv[2]);*/

        // *argv[2] == "+"  <- This is what the book says but gives warnings
        if (strcmp(argv[2], "+") == 0) printf("%d + %d = %d\n", arg1, arg2, arg1 + arg2);
        if (strcmp(argv[2], "-") == 0) printf("%d - %d = %d\n", arg1, arg2, arg1 - arg2);
        if (strcmp(argv[2], "x") == 0) printf("%d * %d = %d\n", arg1, arg2, arg1 * arg2);
        if (strcmp(argv[2], "/") == 0) printf("%d / %d = %d\n", arg1, arg2, arg1 / arg2);
    } else {
    printf("Uh-oh Wrong number of Arguments, Please try again\n");
    }

    return 0;
}
