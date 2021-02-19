# Lamport's Logical Clock

The program takes a description of several process schedules as input (i.e., lists of send, receive or print operations). The output of your program will be a linearization of these events in the order actually performed, annotated with Lamport clock values.

The input of the program will be a collection of processes, each with a list of operations to perform.
The processes are named p1...pn for some n (you may assume that n is at most 9) The format of
a process is:
```
begin process p1
operation
...
operation
end process 
```
where each line contains a basic operation. The possible basic operations are:
- send pN msg (that is, send message msg to process pN)
- recv pN msg (that is, receive message msg from process pN)
- print msg (that is, print message msg to the terminal)
where msg is any alphanumeric string.

<hr style="border:2px solid gray"> </hr>

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

<hr style="border:2px solid gray"> </hr>

### Sample Input (Normal)

```
begin process p1
SEND p2 m1
print abc
print def

end process

begin process p2
print x1
recv p1 m1
print x2
sENd p1 m2
print x3
end process p2
```

```
NAME    OPR         MSG     TO/FROM     TIME
p1      SEND        m1      P2          1
p2      PRINT       x1                  1
p1      PRINT       abc                 2
p2      RECEIVE     m1      P1          2
p1      PRINT       def                 3
p2      PRINT       x2                  3
p2      SEND        m2      P1          4
p2      PRINT       x3                  5
```


### Sample Input (Deadlocked)

```
begin process p1
SEND p2 m1
print abc
print def

end process

begin process p2
print x1
recv p1 m1
print x2
sENd p1 m2
recv p4 mm
print x3
end process p2
```

```
NAME    OPR         MSG     TO/FROM     TIME
p1      SEND        m1      P2          1
p2      PRINT       x1                  1
p1      PRINT       abc                 2
p2      RECEIVE     m1      P1          2
p1      PRINT       def                 3
p2      PRINT       x2                  3
p2      SEND        m2      P1          4

            System Deadlocked.
            
            PROCESS     TIME
            p2          4

```