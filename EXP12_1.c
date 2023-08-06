#include <stdio.h>

int main() {
    int ioq[20], i, n, ihead, tot;
    float seek = 0, avgs;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &ihead);

    ioq[0] = ihead;
    ioq[n + 1] = 0;

    printf("Enter the I/O queue requests:");
    for (i = 1; i <= n; i++)
        scanf("%d", &ioq[i]);

    ioq[n + 1] = ioq[n];

    printf("Order of requests served:");
    for (i = 0; i <= n; i++) {
        tot = ioq[i + 1] - ioq[i];
        if (tot < 0)
            tot = tot * -1;
        seek += tot;
        printf("%d --> ", ioq[i]);
    }

    avgs = seek / n;
    printf("\nTotal Seek time:\t%.2f\n", seek);
    printf("Average seek time:\t%.2f\n", avgs);

    return 0;
}

/*
START
Declare variables: ioq[20] (I/O queue), i, n, ihead, tot, seek, avgs.
Input the number of requests (n).
Input the initial head position (ihead).
Initialize the I/O queue with the initial head position (ioq[0] = ihead) and set the last element of the queue as 0 (ioq[n + 1] = 0).
Input the I/O queue requests (ioq[i]).
Update the last element of the I/O queue to match the last request (ioq[n + 1] = ioq[n]).
Print "Order of requests served:".
Loop i through the I/O queue:
a. Calculate the total seek time between the current and next request (tot = ioq[i + 1] - ioq[i]).
b. If tot is negative, convert it to a positive value.
c. Increment seek by the calculated seek time.
d. Print the current request and " --> ".
Calculate the average seek time (avgs = seek / n).
Print "Total Seek time:", the calculated total seek time, and move to the next line.
Print "Average seek time:", the calculated average seek time, and move to the next line.
STOP
*/


/*
Enter the number of requests: 5
Enter the initial head position: 50
Enter the I/O queue requests: 85 71 57 44 31
Order of requests served: 50 --> 85 --> 71 --> 57 --> 44 --> 31 -->
Total Seek time:        70.00
Average seek time:     14.00

*/