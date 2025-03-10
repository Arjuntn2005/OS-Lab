#include<stdio.h>

int main()
{
   int n;
   
   printf("Enter the Number of processes : ");
   scanf("%d",&n);
   int bt[n],wt[n],tat[n];
   
   int total_bt=0,total_wt=0,total_tat=0;
   
   for(int i=0;i<n;i++)
   {
     printf("Enter the Burst Time for process: %d : ",i+1);
     scanf("%d",&bt[i]);
   }
   
   wt[0]= 0;
   
   for(int i=0;i<n;i++)
   {
     wt[i]=wt[i-1]+bt[i-1];
   }
   
   for(int i=0;i<n;i++)
   {
     tat[i]=bt[i]+wt[i];
   }
   for(int i=0;i<n;i++)
   {
     total_wt+=wt[i];
     total_tat+=tat[i];
   }
   
   printf("\nGant Chart\n");
   printf(" ");
   for(int i=0;i<n;i++)
   {
     printf("  P%d\t",i+1);
   }
   printf("|\n");
   
   printf(" ");
   int time=0;
   
   for(int i=0;i<n+1;i++) 
   {
 
    printf("%d\t",time);
     time+=bt[i];
   }
   printf("\n\n");
   printf("ProcessTime\tBurstTime\tWaitingTime\tTurnAroundTime\n");
   for(int i=0;i<n;i++)
   {
   printf("%d\t\t%d\t\t%d\t\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
   }
   
   printf("Average Waiting Time :%.2f",(float)total_wt/n);
   printf("Average Turn Around Time :%.2f",(float)total_tat/n);
   
   return 0;
   
 
}  
   
   
