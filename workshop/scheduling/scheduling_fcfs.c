#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct process{
	int pid;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int waiting_time;
	int response_time;
}process;

// MergeSort Algorithm to sort by the arrival times of processes
void merge(process *arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    process *left = malloc(n1 * sizeof(process));
    process *right = malloc(n2 * sizeof(process));

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {

	// Sort by arrival time, If two processes arrive at the same time, give priority to the process with the smaller PID
        if ((left[i].arrival_time < right[j].arrival_time) ||
	   (left[i].arrival_time == right[j].arrival_time)) {
            arr[k] = left[i];
            i++;
	   	
	}	       
	else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
	
    // Free allocated subarrays to prevent memory leaks
    free(left);
    free(right);
    left = NULL;
    right = NULL;
}

void mergeSort(process *arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


// First Come First Serve (FCFS) algorithm that takes a list of processes
// and simulates their execution in the FCFS algorithm.
void first_come_first_serve(process * processes,int process_count){
	
	// Sort the processes by their arival time
	mergeSort(processes,0,process_count-1);

	int time = 0;
	int wait_time = 0;
	int response_time = 0;
	int turnaround_time = 0;
	
	// Print the sorted processes
	for(int j = 0;j<process_count;j++){
                printf("process[%d], arrival time = %d, burst time = %d\n",j,processes[j].arrival_time,processes[j].burst_time);
	}

	
	printf("*************************************************************\n");
	printf("=== First Come First Served (FCFS) ===\n");
	printf("Gantt Chart: ");

	for (int i = 0; i < process_count; i++) {
        	printf("| P%d ", processes[i].pid);
    	}
        printf("|\n");
	
	printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
	
	// If the process which is going to arrive first has a non-zero arrival time, add it to the total time
	if(processes[0].arrival_time > 0){
		time += processes[0].arrival_time;
	}

	// Iterate through all of the processes, and complete each of them fully in their order of arrival
	for(int i = 0;i < process_count;i++){

		// Assign the wait time to the process by subtracting their wait time from the current time
		processes[i].waiting_time = time - processes[i].arrival_time;

		// In case the process arrival time is later than the current time
		if(processes[i].waiting_time < 0){
		       	processes[i].waiting_time = 0;
			time += time - processes[i].arrival_time;
		}

		// In non-preemptive algorithms, the response and wait times are the same
		processes[i].response_time = processes[i].waiting_time;

		// Simulate bursting through the process
	        time += processes[i].burst_time;

		processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
		
		
		wait_time += processes[i].waiting_time;
		turnaround_time += processes[i].turnaround_time;
		response_time += processes[i].response_time;

		  printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
               		processes[i].pid, 
               		processes[i].arrival_time, 
               		processes[i].burst_time, 
               		processes[i].waiting_time, 
               		processes[i].turnaround_time, 
               		processes[i].response_time);	
	}

	float avg_wait_time = (float) wait_time / process_count;
	float avg_turnaround_time = (float) turnaround_time / process_count;
	float avg_response_time = (float) response_time / process_count;

	printf("Average Waiting Time: %.2f\n", avg_wait_time);
        printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
        printf("Average Response Time: %.2f\n", avg_response_time);	
}



int main(){
	int process_count;
	printf("Enter the number of proceses: ");
	scanf("%d",&process_count);

	process * processes = malloc(process_count * sizeof(process));
	
	for(int i = 0;i < process_count;i++){
		printf("\nEnter the arrival time and the burst time for process %d: ",i+1);
		scanf("%d %d",&processes[i].arrival_time,&processes[i].burst_time);
		processes[i].pid = i+1;
		processes[i].turnaround_time = 0;
		processes[i].waiting_time = 0;
		processes[i].response_time = 0;
		printf("process[%d], arrival time = %d, burst time = %d\n",i,processes[i].arrival_time,processes[i].burst_time);		
	}

	printf("******************************************************************\n");
	
	first_come_first_serve(processes,process_count);

	return 0;
}
