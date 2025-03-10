#include <stdio.h>

void main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int bt[n], wt[n], tat[n], rem_bt[n];
    int ct = 0, completed = 0;
    float avgt = 0, avgw = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        wt[i] = 0;
        tat[i] = 0;
    }

    printf("\nGantt Chart:\n|");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                printf(" P%d |", i + 1);
                if (rem_bt[i] > tq) {
                    ct += tq;
                    rem_bt[i] -= tq;
                } else {
                    ct += rem_bt[i];
                    tat[i] = ct;
                    wt[i] = tat[i] - bt[i];
                    rem_bt[i] = 0;
                    completed++;
                }
                printf(" %d ", ct);
            }
        }
    }

    printf("\n\nPID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        avgw += wt[i];
        avgt += tat[i];
    }
clear


    printf("\nThe average waiting time: %.2f\n", avgw / n);
    printf("The average turnaround time: %.2f\n", avgt / n);
}
