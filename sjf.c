 #include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process id of all the processes: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter burst time of all the processes: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Process\tBurst time\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", pid[i], bt[i]);
    }

    for(int step = 0; step < n; step++)
    {
        for(int i = 0; i < n - step - 1; i++)
        {
            if(bt[i] > bt[i + 1])
            {
                int temp = bt[i];
                bt[i] = bt[i + 1];
                bt[i + 1] = temp;

                temp = pid[i];
                pid[i] = pid[i + 1];
                pid[i + 1] = temp;
            }
        }
    }

    int start = 0;
    int end = 0;
    printf("\nGANTT CHART\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d \t", pid[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        end += bt[i];
        printf("%d- %d \t", start, end);
        start += bt[i];
    }
    printf("\n");

    int wt[n];
    wt[0] = 0;
    for(int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float twt = 0.0;
    float tat = 0.0;
    for(int i = 0; i < n; i++)
    {
        int turnAround = bt[i] + wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], turnAround);
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }

    float awt = twt / n;
    float att = tat / n;
    printf("\nAvg. waiting time = %f\n", awt);
    printf("Avg. turnaround time = %f\n", att);

    return 0;
}

