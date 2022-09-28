#include<stdio.h>
#include<stdlib.h>

void main()
{
    int inithead,n,total=0;
    printf("Enter the no of requests:");
    scanf("%d",&n);
    int req[n];
    printf("Enter the request sequence:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the initial head position:");
    scanf("%d",&inithead);

    for(int i=0;i<n;i++)
    {
        total+=abs(req[i]-inithead);
        inithead=req[i];
    }
    printf("Total head movements is: %d\n",total);
}