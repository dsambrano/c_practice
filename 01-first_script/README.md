# How to use a Make file and compile C code

https://raspberrypi.stackexchange.com/questions/5599/how-to-compile-c-files-in-terminal

TL;DR

We use GCC to compile the code instead of make.
We add the `-Wall` option to provide extra warning information which it very helpful for debugging.
The base version becomes:

```bash
gcc -Wall <myName>.c -o <compiled name>
```
This will compile the code and create the file. 
The -o and compile name option can be removed if you want it to be the same name. 
Then we can run the file with `./<compiled name>`.
But we like automation, so instead we put the compile and run commands inside of a `MAKEFILE` and run that, which will automate the process.
Here is an example of the file, which takes the source code called `my_first_script.c` from the `src` dir and compiles it to a bin file called `main`.

```
all:
	gcc -Wall -o main src/my_first_script.c
	./main
```

Now, you can compile and run your program with the single command.

```
make
# or
make all
```
