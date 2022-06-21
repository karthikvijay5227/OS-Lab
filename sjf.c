#include<stdio.h>

void main()
{
  int n;
  printf("Enter the no of processes:");
  scanf("%d",&n);
  int p[n],at[n],bt[n],wt[n],tat[n],avwt = 0,avtat = 0,i,j;
  
  printf("Enter the process burst times(in ms):");
  for(int i = 0;i<n;i++)
  {
    printf("P[%d]:",i+1);
    scanf("%d",&bt[i]);
    p[i] = i+1;
    at[i] = 0;
  }
  
  for(i = 0;i<n;i++)
  {
    int pos = i;
    for(j = i+1;j<n;j++)
    {
      if(bt[j]<bt[pos])
         pos = j;
    }
    
    int t1 = bt[i];
    bt[i] = bt[pos];
    bt[pos] = t1;
    
    int t2 = p[i];
    p[i] = p[pos];
    p[pos] = t2;
  }
  
  wt[0] = 0;
  for(i = 1;i<n;i++)
  {
     wt[i] = 0;
     for(j = 0;j<i;j++)
        wt[i]+=bt[j];
  }
  
  printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\t Arrival Time");
  
  for(i = 0;i<n;i++)
  {
    tat[i] = bt[i] + wt[i];
    avwt+=wt[i];
    avtat+=tat[i];
    printf("\np[%d]\t  %d\t\t   %d\t\t   %d\t\t\t  %d",p[i],bt[i],wt[i],tat[i],at[i]);
  }
  avwt/=i;
  avtat/=i;
  
  printf("\n\nAvg Wtime:%d ms",avwt);
  printf("\nAvg Ttime:%d ms",avtat);
  
}
  
  
