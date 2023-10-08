# CS 3133 Foundations of Computer Science Final Project
## About
The original goal of this project is to be able to supply a Turing machine that accepts a specific language. However, my goal for this project is to have a general framework that can run any Turing machine, with user-defined alphabets and state machines.

### Assignment
Give a Turing machine that gets as input two arbitrary strings *`x`* and *`y`* separated by the special symbol *`#`* and return `1` if and only if *`x`* is a subsequence of *`y`*. You may assume `|`*`x`*`|<=|`*`y`*`|`. Show the sequence of configurations of your machine when given the input `00#100`. For extra credit: implement a program that runs the Turing machine and shows its configurations while computing the answer. Your program should work for arbitrary inputs.

## How it works
...

## Todo
- [x] DFA object:
  - State machine that moves based on input, and takes an action based on the input
- [x] Tape object:
  - Linear tape that can be written to/read from. Techincally unlimited length, dynamically sized vector? Also has an input section
- [x] Turing machine:
  - Combination of DFA and tape
  - Ability to run instantly? Step? Breakpoints? Represent DFA/Tape while running? Print state changes/number of moves?
  - Actions: Left, Right, NoOp, ~~Read~~, Write 
- [ ] Printing output:
  - Every step will display
    - [ ] tape
    - [ ] current state
    - [ ] alphabet symbols & states in
    - [ ] alphabet symbols & and states out

### Helpful resources
[Turing machines for dummies](https://erik-engheim.medium.com/turing-machines-for-dummies-81e8e25471b2)

