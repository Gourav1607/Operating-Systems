# Vector Clock

The program takes a description of several process schedules as input (i.e., lists of send, receive or print operations). The output of your program will be a linearization of these events in the order actually performed, annotated with Vector clock values.

The input of the program will be a collection of processes, each with a list of operations to perform. The processes are named p1 ... pn for some n (you may assume that n is at most 9). 

The format of a process is:
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

The send operation simply sends a message and the process is free to continue executing the next operation. The recv operation blocks and waits to hear message msg from a given process.
(This means that there can be deadlocks if all processes are waiting to receive and there are no messages in transit.). An individual print operation takes place atomically. Messages can be sent and received, and printing can take place, in any order, provided causality is respected: that is, the order of events within a process is preserved, and a message is always
sent before it is received. One approach to handle send and recv operations is to maintain a pool of messages including sender, receiver and payload. When a message msg is sent from p1 to p2, we add message m = (p1, msg, p2) to the pool, and when the message is received by p2, m is removed from the pool. 

The output format is a single log of the events that took place during the simulation run, one per line, including Vector clock timestamps. 

The possible events are:
- sent pN msg pM T (that is, pN sent message msg to pM at local time T)
- received pN msg pM T (that is, pN received message msg from pM at local time T)
- printed pN msg T (that is, pN printed message msg to the shared terminal at time T) 

<hr style="border:2px solid gray"> </hr>

### Instructions to Run Programs:

Make changes to input.txt for changing input for the program.

In Windows:
- Open cmd prompt
- Go to the directory of the program VectorClock.cpp
- Run ‘g++ VectorClock.cpp’
- Run ‘a.exe’

**NOTE:** *In Unix based: run ‘./a.out’ instead of ‘a.exe’.*

<hr style="border:1px solid gray"> </hr>

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

<hr style="border:1px solid gray"> </hr>

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