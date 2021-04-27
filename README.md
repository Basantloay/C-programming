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

## 3. Forking Calculating Grades Problem

It is decided to hire N teaching assistants such that each TA is responsible only for evaluating a single group of students.

Each TA is required to decide whether a student should pass the course or not by calculating the grades of the student in the midterm and the final exam respectively.

If the total grades is equal to or exceeds the minimum passing grade P, then the student passes the course. Otherwise, he fails the course.

Finally, each TA should report the number of passing students from their assigned group. The department committee should receive the count of passing students from each TA

By using forking concepts with a single parent process (department committee) and N children processes (TAs). The program accepts three arguments from the command line:
1. A file path indicating the grades of all students enrolled in the course. All grades are non- negative integer values. 
2. 2. N: The number of TAs (N>0)
3. P: The minimum pass grade. (P>0)
Input File Format:
- The first line in the file indicates the number of students (S) in the list. - Each line in the following S lines represents the grades of a single student. It consists of two integers
separated by a space. The first integer is the grade of the student in the midterm exam and the second integer is the grade of the student in the final exam.

- Expected Output:
2 1 2

### 3.1 To run Program on Linux using gcc
```bash
gcc passCounter.c -o passCounter.o
./ passCounter.o “test.txt” 3 40
```
