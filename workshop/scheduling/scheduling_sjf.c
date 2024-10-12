#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct process{
        int pid;
        int arrival_time;
        int burst_time;
        int turnaround_time;
        int waiting_time;
        int response_time;
	bool isCompleted;
}process;

// MergeSort algorithm that sorts by the burst time of the process
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

	// In cases of the burst times being equal, sort by the arrival time instead
        if ( (left[i].burst_time < right[j].burst_time) ||
	     (left[i].burst_time == right[j].burst_time && left[i].arrival_time < right[j].arrival_time)) {
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

// Assumes that the processes have already been sorted by their burst time
// Takes the list of processes, and the current time
// Returns: the shortest process that has not been completed yet, returns NULL if there are no available processes at the given time
process* shortest_arrived_process(process *processes,int process_count, int time){
        for(int i = 0;i < process_count; i++)
        {
                if(processes[i].arrival_time <= time && processes[i].isCompleted == 0){
                        return &processes[i];
                }
        }
        return NULL;
}

// Shortest Job First (SJF) algorithm that takes the list of processes
// and schedules them to be executed by their burst times ascending
void shortest_job_first(process * processes,int process_count){

	// Sort the processes by their burst times
        mergeSort(processes,0,process_count-1);

	int time = 0;
        int wait_time = 0;
        int response_time = 0;
        int turnaround_time = 0;
	int i = 0;
	process *current = &processes[0];
	
	// Print the processes sorted
        for(int j = 0;j<process_count;j++){
                printf("process[%d], arrival time = %d, burst time = %d\n",j,processes[j].arrival_time,processes[j].burst_time);
        }


        printf("*************************************************************\n");
        printf("=== Shortest Job First (SJF) ===\n");
        printf("Gantt Chart: ");

        for (int i = 0; i < process_count; i++) {
                printf("| P%d ", processes[i].pid);
        }
        printf("|\n");

        printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
	
	// Keep iterating until all of the processes have been completed
	while(i != process_count){

		// Assuming that the processes are sorted by their burst times, find the shortest one arrived
		current = shortest_arrived_process(processes,process_count,time);

		// If there are no arrived processes at the moment, increment the time and keep iterating
		if(current == NULL){
			time++;
			continue;
		}
        	
        	current->waiting_time = time - current->arrival_time;
        	current->response_time = current->waiting_time;
		
		// Simulate bursting through the process
        	time += current->burst_time;
		
		// Turnaround time is the time it took to complete the process, so the current time - time it arrived
        	current->turnaround_time = time - current->arrival_time;

        	wait_time += current->waiting_time;
        	turnaround_time += current->turnaround_time;
        	response_time += current->response_time;

        	printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               		current->pid,
               		current->arrival_time,
               		current->burst_time,
               		current->waiting_time,
               		current->turnaround_time,
               		current->response_time);
		
		// Complete the process
        	current->isCompleted = true;
        	i++;
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
	
	// Take input of process_count processes, set default values together with the user input, all new processes are not completed
        for(int i = 0;i < process_count;i++){
                printf("\nEnter the arrival time and the burst time for process %d: ",i+1);
                scanf("%d %d",&processes[i].arrival_time,&processes[i].burst_time);
                processes[i].pid = i+1;
                processes[i].turnaround_time = 0;
                processes[i].waiting_time = 0;
                processes[i].response_time = 0;
		processes[i].isCompleted = false;
                printf("process[%d], arrival time = %d, burst time = %d\n",i,processes[i].arrival_time,processes[i].burst_time);         
        }

        printf("******************************************************************\n");

        shortest_job_first(processes,process_count);

        return 0;
}

