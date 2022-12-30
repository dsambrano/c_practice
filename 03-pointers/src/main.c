#include <stdio.h>

// Apparently you need to use int as return type to indicate success with 
// return 0 : https://qr.ae/prTXmd
int main(void){
    // Intialize a and its pointer
    int a;
    int *ptr_to_a;

    // Assign ptr to actually point to a's memory address
    ptr_to_a = &a;

    // update the value of a
    a = 5;

    // print a
    printf("The value of A is %d\n", a);

    // Update a via updating the dereferenced location of it pointer.
    // In other words ptr_to_a is the pointer to a's mem address, but the * at
    // the beginner dereferences it meaning actually grabbing the value itself.
    *ptr_to_a = 6;
    // Two ways to print the value of variable (the variable and the deferenced pointer)
    printf("The value of a is now %d after being updated via the dereferenced pointer\n", a);
    printf("The ptr_to_a stores this valued %d with a dereference (*ptr_to_a)\n", *ptr_to_a);
    // Two ways to reference a pointer (the pointer and the &var)
    // Also apparently the correct format specifier for pointers is %p:
    printf("The value of ptr_to_a is (%p), which is a memory address\n", ptr_to_a);
    printf("The address of a (via &a) is %p\n", &a);
    // Second Round of examples:
    // init intval to a large number & 
    // assign it as a void pointer so it can point to anything
    int intval = 255957271;
    void *vptr = &intval;
    // Now print it as a int first then the same value as a char
    printf ("The value at vptr as an int is %d\n", *((int *) vptr));
    printf ("The value at vptr as a char is %d\n", *((char *) vptr));
    // Doing some tests it clear that this is not exactly as expected since it
    // gives the same number if it unsigned. So not sure what is happening.
    // Needs further investigation.
    return 0;

}
