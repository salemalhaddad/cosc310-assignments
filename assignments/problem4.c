#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void calculate_times(Process processes[], int n, int time_quantum) {
    int time = 0, completed = 0, i = 0;
    while (completed < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time) {
                found = 1;
                if (processes[i].remaining_time <= time_quantum) {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = time;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed++;
                    printf("Time %d: Process P%d completes\n", time, processes[i].id);
                } else {
                    time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                    printf("Time %d: Process P%d runs\n", time, processes[i].id);
                }
            }
        }
        if (!found) time++;
    }
}

void print_results(Process processes[], int n) {
    float total_turnaround = 0, total_waiting = 0;
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        total_turnaround += processes[i].turnaround_time;
        total_waiting += processes[i].waiting_time;
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);
    printf("Average Waiting Time: %.2f\n", total_waiting / n);
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i;
        printf("Enter arrival time and burst time for process P%d: ", i);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculate_times(processes, n, time_quantum);
    print_results(processes, n);

    free(processes);
    return 0;
}
