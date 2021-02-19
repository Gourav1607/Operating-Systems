# Vector Clock

### Instructions to Run Programs:

Make changes to input.txt for changing input for the program.

In Windows:
- Open cmd prompt
- Go to the directory of the program VectorClock.cpp
- Run ‘g++ VectorClock.cpp’
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

begin process p5
print xc
end process
```

```
NAME    OPR         MSG     TO/FROM     TIME
p1      SEND        m1      P2          (1 0 0)
p2      PRINT       x1                  (0 1 0)
p5      PRINT       xc                  (0 0 1)
p1      PRINT       abc                 (2 0 0)
p2      RECEIVE     m1      P1          (2 2 0)
p1      PRINT       def                 (3 0 0)
p2      PRINT       x2                  (2 3 0)
p2      SEND        m2      P1          (2 4 0)
p2      PRINT       x3                  (2 5 0)
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
print x3
recv p5 mm
end process p2

begin process p5
print xc
end process
```

```
NAME    OPR         MSG     TO/FROM     TIME
p1      SEND        m1      P2          (1 0 0)
p2      PRINT       x1                  (0 1 0)
p5      PRINT       xc                  (0 0 1)
p1      PRINT       abc                 (2 0 0)
p2      RECEIVE     m1      P1          (2 2 0)
p1      PRINT       def                 (3 0 0)
p2      PRINT       x2                  (2 3 0)
p2      SEND        m2      P1          (2 4 0)
p2      PRINT       x3                  (2 5 0)

            System Deadlocked.
            
            PROCESS     TIME
            p2          (2 5 0)

```