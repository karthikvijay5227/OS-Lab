#include<stdio.h>

int main()
{
  int m,n,i,j;

  printf("Ente the number of memory partitions and processes:");
  scanf("%d%d",&m,&n);

  int bSize[m],pSize[n];

  printf("Enter the memory partitions(in kB):");
  for(i=0;i<m;i++)
  {
      scanf("%d",&bSize[i]);
  }

  printf("Enter the process sizes(in kB):");
  for(i=0;i<n;i++)
  {
      scanf("%d",&pSize[i]);
  }

  int allocation[n];  //Array for storing the block number allocated for each process
  for(i = 0; i < n; i++)
  {
    allocation[i] = -1; //Filling all indexes as -1 since no block is allocated till now
  }

  for (i = 0; i < n; i++)   
  {
    for (j = 0; j < m; j++) 
    {
      if (bSize[j] >= pSize[i])
      {
        allocation[i] = j;
        bSize[j] -= pSize[i];
        break;
      }
    }
  }

  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (i = 0; i < n; i++)
  {
    printf(" %i\t\t", i+1);
    printf("%i\t\t", pSize[i]);

    if (allocation[i] != -1)
      printf("%i", allocation[i] + 1);
      
    else
      printf("Not Allocated");
    printf("\n");
  }

  return 0 ;
}
