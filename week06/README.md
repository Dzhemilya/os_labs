```
FCFS
Enter number of processes: 3
Enter arrival time of processes 1: 1
Enter burst time of processes 1: 2
Enter arrival time of processes 2: 3
Enter burst time of processes 2: 4
Enter arrival time of processes 3: 1
Enter burst time of processes 3: 3
[P#]    [WT]    [CT]    [TAT]
P1      1       2       3
P2      3       5       6
P3      6       9       10
Average TAT = 6.000000
Average WT = 3.000000

SJF
Enter number of processes: 3
Enter arrival time of processes 1: 1
Enter burst time of processes 1: 2
Enter arrival time of processes 2: 3
Enter burst time of processes 2: 4
Enter arrival time of processes 3: 1
Enter burst time of processes 3: 3
[P#]    [WT]    [CT]    [TAT]
P1      1       2       3
P2      3       5       6
P3      6       9       10
AVG TAT = 6.000000
AVG WT = 3.000000
```

Comparing the outputs of various algorithms,

I noticed that in many cases SJF works better (we usually have a lot of short tasks).

Although the SJF algorithm needs to know in advance the time it takes for this process to be performed, which sometimes impossible.

In modern operating systems we are working with something more complex,

More optimized priority variation of the round robin algorithm.
