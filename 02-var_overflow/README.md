## Variable Overflows


Variables are assigned a specific number of bytes in memory, therefore they can only represent a space as large as the size they are given.

We will use `char` because they are small enough for this to be easily demonstrated, but the same holds true for other variables as well.

`char` variables go from -128 to 127 or (0 to 255 if you use the `unsigned` keyword).
So if you have assigned a `char` variable to 127, and add 2 to it, you will end up with -127, not 129.
This is because you have rolled over the byte (aka an overflow).

To give another example, imagine if I havea 2 bits to represent info.
So you could have 1 (in binary is would be `01`), two would be (`10`), 3 would be (`11`).
Now we run into a problem.
If you add one more it should be `100` to represent 4, but you only allowed the number two bits, so, for the two bits we are allowed to use (e.g., the two on the right), it reads as `00` or 0.
This is the problem and why it happens.
You only have the assined number of bits as you told C to assign upfront for `char` its 8, so you have 2^8 or 256 numbers (-128 to 127 for signed, and 0 -255 for unsigned).
For `int` you have 4 bytes ([source][int-bytes]) 2^32 (reminder a byte is for bits), so from -2,147,483,648 to 2,147,483,647.
As you can tell this is plenty long enough but you can also store it as a double with is has twice as much spec so it can be much much larger as well ([source][int-size]).
`float`s also have a similar story, but they have 23 bits for the mantissa 8 bits for the exponent and 1 for the sign ([source][float-precision]), as you might have guess, you can also have double precision for floats as well.

[int-bytes]: https://stackoverflow.com/a/11438838 "Int bytes in C"
[int-size]: http://www.ece.northwestern.edu/local-apps/matlabhelp/techdoc/ref/int8.html "Int Memory Size"
[float-precision]: https://stackoverflow.com/a/10108267 "Float Precision"
