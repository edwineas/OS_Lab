// Title: FCFS Disk Scheduling Algorithm
#include <stdio.h>
int main(){
	printf("Enter the number of requests: ");
	scanf("%d", &n);
	printf("Enter the initial head position: ");
	scanf("%d", &head);
	ioq[0] = head;
	printf("Enter the I/O queue requests: ");
	for (i = 1; i <= n; i++)
		scanf("%d", &ioq[i]);
	printf("Order of requests served: ");
	



