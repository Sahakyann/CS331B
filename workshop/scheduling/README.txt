=== First Come First Served (FCFS) ===

This code asks the user for an input of the number of processes to schedule, and asks the user to input the arrival and burst times of each process in order. It executes a FCFS scheduling algorithm where it filters the processes based on their arrival times - from earliest to latest. If two processes have the same arrival time, the preference is given to the process with a smaller PID

Example Input

Enter the number of proceses: 4

Enter the arrival time and the burst time for process 1: 0 8
process[0], arrival time = 0, burst time = 8

Enter the arrival time and the burst time for process 2: 4 8
process[1], arrival time = 4, burst time = 8

Enter the arrival time and the burst time for process 3: 9 1
process[2], arrival time = 9, burst time = 1

Enter the arrival time and the burst time for process 4: 0 5
process[3], arrival time = 0, burst time = 5
******************************************************************

Example Output

process[0], arrival time = 0, burst time = 8
process[1], arrival time = 0, burst time = 5
process[2], arrival time = 4, burst time = 8
process[3], arrival time = 9, burst time = 1
*************************************************************
=== First Come First Served (FCFS) ===
Gantt Chart: | P1 | P4 | P2 | P3 |
PID     AT      BT      WT      TAT     RT
1       0       8       0       8       0
4       0       5       8       13      8
2       4       8       9       17      9
3       9       1       12      13      12
Average Waiting Time: 7.25
Average Turnaround Time: 12.75
Average Response Time: 7.25



=== Shortest Job First (SJF) ===
This asks the user for an input of the number of processes to schedule, and asks the user to input the arrival and burst times of each process in order. It executes a SJF non-preemtive scheduling algorithm where it filters the processes based on their burst times - from smallest to largest. At each time stamp we check what is the shortest burst time process arrived and execute it fully. If two processes have the same burst time, the preference in the sorting is given to the process with an earlier arrival time

Enter the number of proceses: 4

Enter the arrival time and the burst time for process 1: 8 9
process[0], arrival time = 8, burst time = 9

Enter the arrival time and the burst time for process 2: 4 3
process[1], arrival time = 4, burst time = 3

Enter the arrival time and the burst time for process 3: 0 15
process[2], arrival time = 0, burst time = 15

Enter the arrival time and the burst time for process 4: 6 8
process[3], arrival time = 6, burst time = 8
******************************************************************
process[0], arrival time = 4, burst time = 3
process[1], arrival time = 6, burst time = 8
process[2], arrival time = 8, burst time = 9
process[3], arrival time = 0, burst time = 15
*************************************************************
=== Shortest Job First (SJF) ===
Gantt Chart: | P2 | P4 | P1 | P3 |
PID     AT      BT      WT      TAT     RT
3       0       15      0       15      0
2       4       3       11      14      11
4       6       8       12      20      12
1       8       9       18      27      18
Average Waiting Time: 10.25
Average Turnaround Time: 19.00
Average Response Time: 10.25


