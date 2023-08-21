#include <stdio.h>

int main() {
    int i, n, j, head, temp, scan, tot, max;
    float seek, avgs;

    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int ioq[n + 3];

    printf("Enter the initial head position: ");
    scanf("%d", &head);
    ioq[0] = head;
    ioq[1] = 0;

    printf("Enter the maximum track limit : ");
    scanf("%d", &max);
    ioq[n + 2] = max;

    printf("Enter the I/O queue requests: ");
    for (i = 2; i <= n+1; i++)
        scanf("%d", &ioq[i]);

    for (i=0;i<n+1;i++)
        for (j=0;j<n+1-i;j++)
            if (ioq[j]>ioq[j+1]) {
                temp=ioq[j];
                ioq[j]=ioq[j+1];
                ioq[j+1]=temp;
            }

    for (i = 0; i < n+2; i++) // find the position of head in the queue
        if (head == ioq[i]) {
            scan = i;
            break;
        }

    printf("Order of requests served: ");

    for(i=scan;i<=n+2;i++){ ;
        printf("%d --> ",ioq[i]);
    }

    for(i=0;i<scan;i++){
        printf("%d --> ",ioq[i]);
    }

    seek = (max - head) + max + ioq[scan-1];
    avgs = seek / n;

    printf("\nTotal Seek time:\t%.2f\n", seek);
    printf("Average seek time:\t%.2f\n", avgs);

    return 0;
}
