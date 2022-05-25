#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    
    printf("\n");
    
    int s1=0,s2=0;
    int id=fork();
    
    if(id != 0)
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)
               s1+=i;
        }
        printf("Sum of odd numbers is: %d\n",s1);
        printf("Parent Process ID: %d\n",getppid());
        printf("\n");
    }
    
    else
    {
       for(int i=1;i<=n;i++)
       {
            if(i%2 == 0)
               s2+=i;
       }
       printf("Sum of even numbers is: %d\n",s2);
       printf("Child Process ID: %d\n",getpid());
    }
    
	return 0;
}

