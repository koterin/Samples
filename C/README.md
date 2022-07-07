## named_hello.c

The simpliest stuff out there - gets user input and greets him by thee name.

## sort.c

Sorts 10 input numbers via Bubble sort

## cycle_shift.c

Moves input 10 input numbers in a loop on the specified number of symbols and direction

## fast_sort

Heap- and quick-sorting algorythms

## matrix.c

Takes mode for allocating memory for matrix - 1, 2 or 3, then its size (like `2 2`) and its contents.
Returns the input matrix in the row-column way

## /simple_strings

A little part of C-string lib - `strchr`, `strtok`, `strstr`, `strcat`, `strcpy`, `strcmp`, `strlen`.
Makefile, tests.

## /stack

Stack and List implementation for door example.
Makefile, tests.

## /btree

Binary tree implementation.
Makefile, tests.

### /btree/documentation_module.c

var_args use in C

### /btree/main_module_entry_point.c

Callbacks use in C

## /cipher/logger.c

C-logger implementation with `logger.h` lib and `log_levels.h` enum levels.
Use sample is shown via `cipher.c`

## /cipher/cipher.c

> Important! The binary file is generated to the `../build` directory, so there must be one to compile successfully.

Code sample for manipulating data:
First input parameter - menu mode:
   - `1`: output the data. Next you'll have to input the filepath, for example, `ai_modules/m1.c`. It will show the file contents
   - `2`: add some data. Can only be used after the `1` option, because it uses the same input filepath. After `2` it waits for the line to be appended to the file. Does not output it contents after execution
   - `3`: cipher stuff. Waits for the step number - for example, 4 (or 104, or -56); next wait for the filepath and executes the Caesar cipher on its contents: changing all symbols to the `+step` (`a` + `2` = `c`)
   - `-1`: exits the program. Before that it runs in an endless loop (there are some bugs... sometimes the exit mode doesn't really work, hehe)

For compiling in simple mode - use `make`, to compile with logger enabled - use `make logging_cipher`
