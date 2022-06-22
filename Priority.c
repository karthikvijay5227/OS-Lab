#include<stdio.h>

void main()
 
{
    int n;
    printf("Enter total number of processes:");
    scanf("%d",&n);
    int bt[n],wt[n],at[n],P[n],Pr[n],tat[n],avwt=0,avtat=0,i,j;
 
    printf("\nEnter Process Burst Times(in ms):\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
        P[i]=i+1;
        at[i] = 0;
    }
    
    printf("\nEnter the priorities:");
    for(i=0;i<n;i++)
    {
      scanf("%d",&Pr[i]);
    }
    
    for(i=0;i<n;i++)
    {
      int pos=i;
      for(j=i+1;j<n;j++)
      {
        if(Pr[j]<Pr[pos])
          pos=j;
      }
      int temp=Pr[i];
      Pr[i]=Pr[pos];
      Pr[pos]=temp;
      
      temp=P[i];
      P[i]=P[pos];
      P[pos]=temp;
      
      temp=bt[i];
      bt[i]=bt[pos];
      bt[pos]=temp;
    }
    
    wt[0]=0;   
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess\t Burst Time\t Waiting Time\t Arrival Time\t Turnaround Time\t Priority");
 
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t\t   %d",P[i],bt[i],wt[i],at[i],tat[i],Pr[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d ms",avwt);
    printf("\nAverage Turnaround Time:%d ms\n",avtat);
 
}
