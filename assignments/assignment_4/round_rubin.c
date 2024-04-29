#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid; // Process ID
    int arrival; // Arrival time
    int burst; // Burst time
    int remaining; // Remaining burst time
    int turn_around; // Turnaround time
    int waiting; // Waiting time
};

void round_robin(struct process procs[], int n, int time_quantum) {
    int time = 0; // Current time
    int completed = 0; // Completed processes count

    while (completed < n) {
        int ran_at_least_one = 0; // To ensure the loop runs properly

        for (int i = 0; i < n; i++) {
            if (procs[i].remaining > 0 && procs[i].arrival <= time) {
                ran_at_least_one = 1;
                int run_time = procs[i].remaining < time_quantum ? procs[i].remaining : time_quantum;

                printf("Time %d: Process P%d runs for %d time units\n", time, procs[i].pid, run_time);

                time += run_time;
                procs[i].remaining -= run_time;

                if (procs[i].remaining == 0) {
                    procs[i].turn_around = time - procs[i].arrival;
                    procs[i].waiting = procs[i].turn_around - procs[i].burst;
                    completed++;
                }
            }
        }

        if (!ran_at_least_one) {
            time++; // Advance time if no process ran
        }
    }

    printf("\nFinal Results:\n");
    double total_turn_around = 0, total_waiting = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d: Turnaround time: %d, Waiting time: %d\n", procs[i].pid, procs[i].turn_around, procs[i].waiting);
        total_turn_around += procs[i].turn_around;
        total_waiting += procs[i].waiting;
    }

    double avg_turn_around = total_turn_around / n;
    double avg_waiting = total_waiting / n;

    printf("Total Turnaround Time: %.2f\n", total_turn_around);
    printf("Total Waiting Time: %.2f\n", total_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turn_around);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
}

void read_processes(struct process procs[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process P%d: ", i);
        scanf("%d %d", &procs[i].arrival, &procs[i].burst);
        procs[i].pid = i;
        procs[i].remaining = procs[i].burst;
    }
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct process procs[n];
    read_processes(procs, n);

    round_robin(procs, n, time_quantum);

    return 0;
}
