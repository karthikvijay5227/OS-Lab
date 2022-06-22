#include<stdio.h>
int main()
{
      int n;
      printf("Enter the no of processes:");
      scanf("%d",&n);

      int bt[n],at[n],P[n],avwt = 0,avtat = 0;
      int x,temp[n],tq,total = 0,i,j,c=0,wt=0,tat=0;
      x = n;

      printf("Enter the process burst times and arrival times(in ms):");
      for (i = 0; i < n; i++)
      {
         printf("P[%d]",i+1);
         scanf("%d",&bt[i]);
         scanf("%d",&at[i]);
         P[i] = i+1;
         temp[i] = bt[i];
      }

      printf("\nEnter Time Quantum(in ms):");
      scanf("%d", &tq);

      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= tq && temp[i] > 0)
            {
                  total += temp[i];
                  temp[i] = 0;
                  c = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i]-= tq;
                  total += tq;
            }
            if(temp[i] == 0 && c == 1)
            {
                  x--;
                  printf("\nP[%d]\t\t\t    %d\t\t     %d\t\t\t    %d", i + 1, bt[i], total - at[i], total - (at[i] + bt[i]));
                  wt += total - at[i] - bt[i];
                  tat += total - at[i];
                  c = 0;
            }
            
            if(i == n - 1)
               i = 0;
            else if(at[i + 1] <= total)
               i++;
            else
               i = 0;
      }
 
      avwt = wt * 1.0 / n;
      avtat = tat * 1.0 / n;
      printf("\n\nAverage Waiting Time:%d ms", avwt);
      printf("\nAverage Turnaround Time:%d ms\n", avtat);
    
    return 0;
}
