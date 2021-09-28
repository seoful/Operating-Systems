#include <stdio.h>
int num_of_proc;


void robin(int arrival_time[], int burst_time[], int quantum){
    int waiting_time[num_of_proc], turn_around_time[num_of_proc], completion_time[num_of_proc];
    int burst_time_cpy[num_of_proc], count = 0;
    double total_waiting = 0, total_TAT = 0;
    waiting_time[0] = 0;
    for(int i = 0 ; i < num_of_proc; i++) {
        burst_time_cpy[i] = burst_time[i];
    }
    int x = num_of_proc;
    double allWT = 0, allTAT = 0;
    for (int t = 0, i = 0; x != 0; ) {
        if (burst_time_cpy[i] <= quantum && burst_time_cpy[i] > 0) {
            t += burst_time_cpy[i];
            burst_time_cpy[i] = 0;
            count = 1;
        } else if (burst_time_cpy[i] > 0) {
            burst_time_cpy[i] = burst_time_cpy[i] - quantum;
            t += quantum;
        }
        if (burst_time_cpy[i] == 0 && count == 1) {
            waiting_time[i] = t - arrival_time[i] - burst_time[i];
            turn_around_time[i] = t - arrival_time[i];
            completion_time[i] = t;
            allWT = allWT + waiting_time[i];
            allTAT = allTAT + turn_around_time[i];
            count = 0;
            x--;
        }
        if (i == num_of_proc-1) i = 0;
        else if (arrival_time[i + 1] <= t) i++;
        else i = 0;
    }
    for(int i = 0 ; i < num_of_proc; i++){
        total_waiting += waiting_time[i];
        total_TAT += turn_around_time[i];
        printf("processes %d:\nBurst time: %d\nArrival time: %d\nWaiting time: %d\nTurnaround time: %d\n"
               "Completion time: %d\n\n", i + 1, burst_time[i], arrival_time[i], waiting_time[i],turn_around_time[i],
               completion_time[i]);
    }
    printf("Average Waiting time: %lf\n", (double)total_waiting/(double)num_of_proc);
    printf("Average Average Turnaround time: %lf", (double)total_TAT/(double)num_of_proc);
}


int main() {
    printf("Enter number of processes:\n");
    scanf("%d", &num_of_proc);
    int arrival_time[num_of_proc], burst_time[num_of_proc], quantum;
    printf("Enter arrival_time and burst_time for each process:\n");
    for(int i = 0; i < num_of_proc; i++){
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    printf("Time quantum: ");
    scanf("%d",&quantum);
    robin(arrival_time, burst_time, quantum);
    return 0;
}