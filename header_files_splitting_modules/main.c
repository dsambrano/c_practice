#include <stdio.h>
// Use `"` to signify this is a local header file, while `<` indicates its in
// the standard repos
#include "function.h"

// Defines don't consume memory because the preprocessor repaces all the strings
// with the define equivalent
#define PI 3.14159

int main(void){
    printf("The total is %d\n", add_vals(1, 2, 3));
    printf("PI (%f) is an important constant in math\n", PI);
// Special type of if statement, seems to be mostly for debugging, I don't think
// this is implmented very often in production ready code.
#if 1
    printf("This code is for diagnostic purposes only.\n");
#else
    printf("Alternative diagnostic text.\n");
#endif /* 1 */
    return 0;
}
