#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0, empty = 10, x = 0;

void Producer()
{
	
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer produces item %d",x);
	++mutex;
}

void Consumer()
{
	
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumes item %d",x);
	x--;
	++mutex;
}
void main()
{
	int ch;
	do{
		printf("\n1.Producer\t2.Consumer\t3.Exit\n");
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		switch (ch) 
        {
		    case 1:
			    if ((mutex == 1) && (full != 10)) {
				    Producer();
			    }
			    else {
				    printf("Buffer is full!");
			    }
			    break;

		    case 2:
			    if ((mutex == 1) && (empty != 10)) {
				    Consumer();
			    }
			    else {
				    printf("Buffer is empty!");
			    }
			    break;
		
            case 3:exit(0);
		           break;
		}
	}while(ch!=3);
}
