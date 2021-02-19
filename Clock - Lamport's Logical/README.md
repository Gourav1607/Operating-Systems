# Lamport's Logical Clock

### Instructions to Run Programs:

Make changes to input.txt for changing input for the program.

In Windows:
- Open cmd prompt
- Go to the directory of the program LamportClock.cpp
- Run ‘g++ LamportClock.cpp’
- Run ‘a.exe’

**NOTE:** *In Unix based: run ‘./a.out’ instead of ‘a.exe’.*

### Errors Program can handle:

1. Extra Spaces in Input.
2. Extra Lines in Input.
3. Message can be of any length (can be separated by spaces).
4. Operation name can be in any case (small, capital or mix) as well as process names.
5. Checks for Beginning and Ending of Process. If no end, then prints ‘Incorrect Sequence of Operations’.
6. If Deadlock occurs, it is reported after other operations are executed.
7. If not all processes are in Deadlock, then also deadlock is reported.
8. Number of processes cannot exceed 10.
