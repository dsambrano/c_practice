# Pointers in C

Apparently you need to use int as return type for main in C.
The reason is because you use `return 0` to indicate the program successfully completed ([source][main-int], I believe values other than zero specifically higher than 0 indicate different failures).

A `ptr` is the memory address (or location) of a variable.
In other words, it is the location where the variable's data/information is stored on the computer's RAM.
You can assign pointers by using `*` in front of the pointer's variable name:

```c
int a = 5;
int *ptr = &a; // also equivalent to int* ptr and int * ptr since C doesn't care about spaces
printf("%d\n", *ptr) // According to SO, right side should be (void *) &a
```

One confusing thing, is `*` indicates that you are storing the memory address, but if you use `*` on an assigned pointer (e.g., line 3 above)you are dereferencing the pointer, meaning you are actually getting back the value stored at that memory address.
Also note the `&` on line 2 (above).
This is how you access the memory address of a variable.


So now we have two ways to access the memory address (`*ptr` and `&a`), but we also have two ways to access the value stored at that memory address (`ptr` and `&a`).

Frinally, as shown in the final line above, the proper way to format a pointer in a `printf` function is with `%p`, but there are others for more complicated situations ([source][pointer-formatters]).

[main-int]: https://qr.ae/prTXmd "Why int main in C"
[pointer-formatters]: https://stackoverflow.com/a/9053835 "Format Specifiers for pointers in C"
