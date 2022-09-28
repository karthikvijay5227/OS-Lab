#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

int main()
{
	void *str;
	char data[100];
	int shmid = shmget((key_t)5324, 1024, 0666 | IPC_CREAT);
	printf("Key of shared memory is: %d\n", shmid);
	str = shmat(shmid, NULL, 0);
	printf("Process attached at %p\n", str);
	printf("Enter the data to be written in memory:");
	scanf("%s",data);
	strcpy(str, data);
	return 0;
}
