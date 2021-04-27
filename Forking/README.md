# Forking 

This folder contains Forking lab of Calculating Grades Problem

### Calculating Grades Problem

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

### To run Program on Linux using gcc
```bash
gcc passCounter.c -o passCounter.o
./ passCounter.o “test.txt” 3 40
```
