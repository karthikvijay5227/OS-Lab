#include<stdio.h>
#include<stdlib.h>

void main()
{
    int inithead,n,total=0,i;
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

    int disksize,dir;
    printf("Enter the disk size:");
    scanf("%d",&disksize);

    printf("Directions ==>1.High\t2.Low\nEnter the direction:");
    scanf("%d",&dir);

    //Sorting Request array for SCAN 

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }

    int index;
    for(int i=0;i<n;i++)
    {
        if(req[i]>inithead)
        {
            index=i;
            break;
        }
    }
    if(dir==1)
    {
        for(int i=index;i<n;i++)
        {
            total+=abs(req[i]-inithead);
            inithead=req[i];
        }
        total+=abs(disksize-req[i-1]-1);
        inithead=disksize-1;
        for(i=index-1;i>=0;i--)
        {
            total+=abs(req[i]-inithead);
            inithead=req[i];
        }

    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            total+=abs(req[i]-inithead);
            inithead=req[i];
        }
        total+=req[i+1];
        inithead=0;
        for(int i=index;i<n;i++)
        {
            total+=abs(req[i]-inithead);
            inithead=req[i];
        }
    }
    printf("Total head movement is: %d\n",total);
}