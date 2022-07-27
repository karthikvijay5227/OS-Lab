#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i, shmem;
    void *str;
    int shmid = shmget((key_t)5324, 1024, 0666 | IPC_CREAT);
    str = shmat(shmid, NULL, 0);
    printf("Key of shared memory is %d\n", shmid);
    printf("Process attached at %p\n", &str);
    printf("Data read from memory: %s\n", (char *)str);
    return 0;
}
