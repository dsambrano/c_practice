#include <stdio.h>

int main(){
    // Chars are only 1 byte in memory so can only hold values 256 values 2 ^ 8
    // Chars are between -128 and 127
    char a = 127;
    printf("A starts off as %d\n", a);
    // So if you add 1 to 127, you wont get 128 but -128 and then keep adding from there
    a ++;
    printf("Add 1 to A and it becomes %d\n", a);

    // Similarly Unsigned chars go from 0 to 255
    unsigned char b = 255;
    printf("B ends off as %d\n", b);
    // So if you add 1 to 255 you get 0 not 256
    b ++;
    printf("Add 1 to B and it becomes %d\n", b);

}
