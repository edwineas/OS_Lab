// Title: FCFS Disk Scheduling Algorithm
#include <stdio.h>

int main() {
    int ioq[20], i, n, sd,head;
    float seek = 0, avgs;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the I/O queue requests:");
    for (i = 1; i <= n; i++)
        scanf("%d", &ioq[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);
    ioq[0] = head;

    printf("Order of requests served:");
    for (i = 0; i < n; i++) {
        sd = ioq[i + 1] - ioq[i];
        if (sd < 0)
            sd = sd * -1;
        seek += sd;
        printf("%d --> ", ioq[i]);
    }printf("%d >\n", ioq[n]);

    avgs = seek / n;
    printf("Total Seek time : %.2f\n", seek);
    printf("Average seek time :  %.2f\n", avgs);

    return 0;
}