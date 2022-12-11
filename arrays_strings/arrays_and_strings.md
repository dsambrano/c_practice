# Arrays and Strings

If you are coming from another language, arrays may seem a bit odd.
Array, are just list of items of the same type.
So they can be a list of `int`s or `float`s, pretty standard, right?
Well this they can also be a list of `char`, you are probably more familiar with a `string`.

Yeah, that's right, strings in C are not a default type.
Rather, they are a list of `char`s.
This has a lot of consequences, way to many to describe here, so make sure to check out the book referenced in the main `README.md`, but it is definitely worth noting some.
> Note: Strings always end in `0` (*string terminator*), so you will often (but annoyingly not always) need to have that at the end of the string. Meaning that it will also consume one extra byte of space, so you will need to make your string the length + 1 of your intended string size.


## Weird Array behavior

Arrays are also weird.
Arrays are not an array per se, but rather a pointer to the first element of the array.
As you can see in the `main.c` file, we can access the same value of array `a` with the index syntax (`a[0]`) or the pointer/reference syntaxt (`&a`).

One final weird and potenially dangerous point about arrays, is that even though you specify their size up front, they are not limited to that.
So, you may have assigned a `int` array of length 5 (`int a[5] = {0, 1, 2, 3, 4};`), but if you try to index outside of that size, you will not be stopped.
What is worse, you can not only read outside that array, you can actually write.
I am not certain, but I am pretty sure this the basis for the standar buffer overflow exploits you so often here about and why C is considered memory unsafe (again just speculation at this point, but from what I am aware it makes sense this is the thing).
