# C-programming

This repository contains simple functions in c

## 1.Joey-Kangaroo Pair isJKP function

A joey word is a word whose number of letters is less than that of the kangaroo word and whose letters appear all in the same order as they appear in the kangaroo word. 

Examples on (kangaroo, joey) pairs are words like:

chicken &  hen

lighted & lit

instructor & tutor

Given two strings in no particular order and case-insensitive, if they are a Joey-Kangaroo Pair (JKP).

It takes two string arguments and prints 1 if they are a JKP or 0 if they aren’t.

### 1.1 To run on Linux using gcc

```bash
gcc isJKP.c -o JKP
./JKP racisT SupremAcist
```
## 2 Calculator function

It calculates the result of an arithmetic string expression (as if your program acts as a calculator). 

The input is supplied from the terminal as a string expression and the output is an integer.

● Assume the operands are NON-NEGATIVE numbers (0,1,2,..), and each operand can be of arbitrary any number of digits.

● Assume the only operator used is only + and NO brackets and NO spaces

### 2.1 To run on Linux using gcc

```bash
gcc calculator.c -o calculator
./calculator 111+222+333+111
>>777
```


