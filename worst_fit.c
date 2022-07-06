#include <stdio.h>

int main()
{
    int m, n, i, j;

    printf("Enter the number of memory partitions and processes:");
    scanf("%d%d", &m, &n);

    int bSize[m], pSize[n];

    printf("Enter the memory partitions(in kB):");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &bSize[i]);
    }

    printf("Enter the process sizes(in kB):");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pSize[i]);
    }

    int allocation[n];

    // Initially no block is assigned to any process
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        // Find the best fit block for current process
        int wstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (bSize[j] >= pSize[i])
            {
                if (wstIdx == -1 || bSize[j] > bSize[wstIdx])
                    wstIdx = j;
            }
        }

        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
            bSize[wstIdx] -= pSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++)
    {
        printf(" %i\t\t", i + 1);
        printf("%i\t\t", pSize[i]);

        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);

        else
            printf("Not Allocated");
        printf("\n");
    }
    return 0;
}
