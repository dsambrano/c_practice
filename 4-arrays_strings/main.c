#include <stdio.h>

int main(void){
    int a[10];
    int count;

    for (count = 0; count < 10; count++){
        a[count] = count * 10 + count;
    }


    // The name of an array (a in this example) is really just a pointer to its
    // first values.
    // That is why below whether you are accessing the array via indecies
    // or via a pointer reference, you get the same value.
    // Not sure how viable that is in practice.
    printf("The first and second element of a are %d and %d\n", a[0], a[1]);
    printf("Or as pointers they are %d and %d\n", *a, *(a + 1));


    //Strings are just arrays of chars
    char str1[10] = "first";
    char str2[10] = "second";
    char str3[20];

    // According to LSP you do need * on both
    char *src, *dst;
    src = str1;
    dst = str3;
    while(*src != 0){
        // Make what ever the src currently is and copy it to dst at curren mem
        // address
        *dst = *src;
        // Increment, but what are we incrementing? The actual memory addres,
        // not that there is no *, so we are not incrementing values but the
        // memory address itself.
        //
        // Further, remember arrays are just pointers to (typically) the start
        // of and array, so we are able to manipluate the contents of the array
        // but incrementing the pointer. Essentially this is equivalent to
        // having an incrementer i and doing i++ at the end of the loop.
        src++;
        dst++;
    }
    src = str2;
    while(*src != 0){
        *dst = *src;
        src++;
        dst++;
    }

    // ending the string (char array) with the string terminator (0).
    // But remember that str3 is still pointing to the start of the array, so
    // we can access the full string by using that variable.
    *dst = 0;

    printf("%s + %s = %s\n", str1, str2, str3);
    printf("Just curious what is dst (%s) how about *dst (%d)\n", dst, *dst);
    // I am pretty sure dst is not nothing because it a a string, but of length
    // 1 and the only thing in there is the string terminator. Lets confirm
    printf("How about dst - 3? (%s) and *(dst - 3) (%d)\n", (dst - 3), *(dst - 3));
    // Based on this, I would say that it is confirmed for the string value, but
    // the pointer is still a little confusing, not sure what we are getting the
    // value we are getting. Currently 111

    // Here is a more practical way of manipulate strings after creation.
    int val = 12;
    char string[50];

    // As you can see we can use the sprintf function to create a update a string
    // it requires a string pointer first and then the rest is the same syntax
    // as the printf function only exception is instead of printing to the
    // console it prints to the pointer. Obviously this is much easier than the
    // above method and prevents you from forgetting the terminating 0
    sprintf(string, "The value of val is %d", val);
    printf("string is: \'%s\'\n", string);
    return 0;
}
