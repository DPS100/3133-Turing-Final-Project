# CS 3133 Foundations of Computer Science Final Project
## About
The original goal of this project is to be able to supply a Turing machine that accepts a specific language. However, my goal for this project is to have a general framework that can run any Turing machine, with user-defined alphabets and state machines.

### Assignment
Give a Turing machine that gets as input two arbitrary strings *`x`* and *`y`* separated by the special symbol *`#`* and return `1` if and only if *`x`* is a subsequence of *`y`*. You may assume `|`*`x`*`|<=|`*`y`*`|`. Show the sequence of configurations of your machine when given the input `00#100`. For extra credit: implement a program that runs the Turing machine and shows its configurations while computing the answer. Your program should work for arbitrary inputs.

### Solution
Explicit definition can be found in [subseq.txt](subseq.txt).
This is an overview of the algorithm:

1. Read last character in first string.
2. Start from last character in second string, begin erasing until target character is found. If null character is found, decline.
3. Erase last character in first string.
4. Move left. If empty string, accept. If not, go back to step 1.
 
This had an issue where if it erased the entire second string to find the target character, the next attempt to find a character would enter a loop where it would never find a string.

So I inserted an extra step between 1 and 2:
- Read second to last character in first string. If empty, simply continue with step 1. Otherwise, append the second string with a null character, then the inverse of the second to last character. Then continue from step 1.

This also fixed the case where the subsequence was larger than the string it was being checked against.

## Compiling & Running
The program turing.exe has been compiled for the Windows Subsystem for Linux (WSL). It is not a native Windows executable! Please recompile if you have a different operating system.

Compiling with g++: `g++ -o turing.exe src/*.cpp`. Use the -g flag to compile for debugging.

Use `./turing.exe` to run the program.

### Command line args:
- -h, --help   Show help message.
- -i, --input  Path to target input file.
- -p, --print  Enable pretty printing. Output progress of simulated Turing machine to the console.
- -d, --delay  Delay time in ms between transition between states. Automatically enables pretty printing.

## Providing a Turing machine
See [subseq.txt](subseq.txt) for a demo input file.

The input file to define a Turing machine is formatted like so:
- *Blank line*
- State names
- *Blank like*
- Alphabet
- Input tape
- *Blank line*
- State transition instructions

The top line of the file MUST be blank! The language may not be read correctly or have malformed state names if it isn't. Each section must also be separated by a newline character. Having more instructions than states will result in a error, but having more states than instructions will lead to undefined behavior and possibly a runtime error.

### Alphabet format
Must have a length of at least one. The only special symbol in the alphabet is the first character, assumed to be the blank/null symbol. If the head moves off the defined tape, this is the symbol that will be read.

### Instruction format:
Every set of state transition instructions should be written on a new line. The name of each state is the corresponding index in the list of names. Each state must have corresponding transition instructions for every character in the alphabet, separated by a single space.
The first transition instruction corresponds to reading the first alphabet symbol, and so on. The first part of an instruction should be a number represeting what state the transition leads to, and the second part should be the instruction to execute. The list of instructions is:
- `>`: Move head right.
- `<`: Move head left.
- `W`: Write symbol. Should be followed by a character in the alphabet.
- `N`: No operation. Functionally equivalent to writing the character that was read, but simplifies the number of states.

### Special states
There are three special states:
- Start state: This is always assumed to be the first state defined. It does not have to be named anything in particular.
- Accept state: Your machine must have at least one of these two terminating states to halt. The default program assumes the accept state to be named "Accept".
- Decline state: Your machine must have at least one of these two terminating states to halt. The default program assumes the decline state to be named "Decline".

All three of these states can be set manually by using a different Turing machine constructor and recompiling the program. See [Turing.hpp](Turing.hpp).

### Helpful resources
[Turing machines for dummies](https://erik-engheim.medium.com/turing-machines-for-dummies-81e8e25471b2)

