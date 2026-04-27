# Assignment 1 - Circular Buffer in C

## Description
This project implements a Circular Buffer in C.

The buffer supports:
- Initialization
- Writing data
- Reading data
- Handling overflow (buffer full)
- Handling underflow (buffer empty)

## Main Program
The program:
1. Reads the user's name from standard input.
2. Appends the string "CE-ESY" to the name.
3. Stores the result in the circular buffer character by character.
4. Reads the data back from the buffer and prints it.
5. Ensures the buffer is empty at the end.

## How to Compile and Run
Using gcc:
```bash
gcc prog.c -o prog
./prog
