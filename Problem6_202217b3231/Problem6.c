#include<stdio.h>

int main(){
    int n, arrive[10], burst[10],wait[10],gantt[10],turnA[10];
    float avgWT=0,avgTT=0; //average waiting time and turnaround time

    for (int i = 0; i < 10; i++)
    {
        arrive[i] = 0;
        burst[i] = 0;
        wait[i] = 0;
        gantt[i] = 0;
    }

    printf("\nEnter the no. of processes: ");
    scanf("%d",&n);

    printf("\nEnter the burst times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&burst[i]);
    }

    printf("\nEnter the arrival times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arrive[i]);
    }

    gantt[0]=0;
    for (int i = 0; i < 10; i++)
    {
        gantt[i+1]=gantt[i]+burst[i];
    }

    for (int i = 0; i < n; i++)
    {
        wait[i]=gantt[i]-arrive[i];
        turnA[i]=gantt[i+1]-arrive[i];
        avgWT=avgWT+wait[i];
        avgTT=avgTT+turnA[i];
    }

    avgWT=avgWT/n;
    avgTT=avgTT/n;

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("\tP%d\t\t%d\t\t%d\n",i,wait[i],turnA[i]);
    }

    printf("Average Waiting time: %f\n",avgWT);
    printf("Average Turnaround time: %f\n",avgTT);

}
