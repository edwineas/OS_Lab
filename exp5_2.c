#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int shmid;
	void *shm;
	char str[300];
	shmid = shmget((key_t) 2366, 1024, 0666);
	printf("Key of shared memory is %d \n",shmid);
	shm = shmat(shmid, NULL, 0);
	printf("Process is attached at %p \n",shm);
	printf("value read from shared is %s \n",(char*)shm);
	shmdt(str);
	shmctl(shmid,IPC_RMID, NULL);
	return 0;
}
