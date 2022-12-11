#include <stdio.h>
#include <string.h>

int main(void){
    char str1[10] = "first";
    char str2[10] = "second";
    char str3[20];

    // Copy str1 to str3
    strcpy(str3, str1);
    // Now concatenate str2
    strcat(str3, str2);
    printf("%s + %s = %s\n", str1, str2, str3);

    char a[10] = "first";
    char b[10] = "fire";

    char *ptr1 = a, *ptr2 = b;

    while(*ptr1 != 0){
        if(*ptr1 != *ptr2){
            break;
        }
        ptr1++;
        ptr2++;
    }

    if(*ptr1 == 0 && *ptr2 == 0){
        printf("The two strings are EQUAL\n");
    } else {
        printf("The two strings are NOT equal\n");
    }
    // A much simpliar version that does not need the while loop
    // One oddety is that 0 is success so you need to check if equal to 0.
    // Or awkwardly slip the if else options.
    if(strcmp(a, b) == 0){
        printf("The two strings are the SAME\n");
    } else{
        printf("The two strings are DIFFERENT\n");
    }
    int n_letters = 3;
    if(strncmp(a, b, n_letters) == 0){
        printf("The first %d letters are the SAME\n", n_letters);
    } else {
        printf("The first %d letters are DIFFERENT\n", n_letters);
    }
    //If you dont care about case, check out strcasecmp and strncasecmp

    // Converting String to Int
    // sprintf goes from var to string, well sscanf does the opposite
    int val;
    char string[13] = "My value 250";

    //Note that you need them both to be pointers, but since a string var is
    //already technically a pointer, you don't need to do anything, so you only
    //need to amke the int value a pointer with &. This is because functions
    //cant change a arguments values but it can change a pointer location.
    sscanf(string, "My value %d", &val);
    printf("We pulled out the int value from string and it was %d\n", val);

    int value;
    char my_string[10];
    char long_string[30] = "The first value is 10";
    if(sscanf(long_string, "The %s value is %d", my_string, &value) == 2){
        printf("String: %s, Int: %d\n", my_string, value);
    } else {
        printf("We could not parse both variables\n");
    }
    printf("long_string: '%s' has %ld characters\n", long_string, strlen(long_string));


    return 0;
}
