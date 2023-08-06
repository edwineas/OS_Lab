#include <stdio.h>

int np, nr; // Define np (number of processes) and nr (number of resources) as global variables

int main() {
    int alloc[10][10], request[10][10], avail[10], r[10], w[10], finish[10] = {0};
    int i, j, k;

    printf("Enter the no of processes: ");
    scanf("%d", &np);

    printf("Enter the no of resources: ");
    scanf("%d", &nr);

    for (i = 0; i < nr; i++) {
        printf("Total Amount of the Resource R%d: ", i + 1);
        scanf("%d", &r[i]);
    }

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the request matrix:\n");
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Calculate the available resources
    for (j = 0; j < nr; j++) {
        avail[j] = r[j];
        for (i = 0; i < np; i++) {
            avail[j] -= alloc[i][j];
        }
    }

    int deadlock = 0;
    int count = 0; // Keep track of the number of processes that can be executed

    while (count < np) {
        int can_execute = 0;
        for (i = 0; i < np; i++) {
            if (!finish[i]) {
                int safe = 1;
                for (j = 0; j < nr; j++) {
                    if (request[i][j] > avail[j]) {
                        safe = 0;
                        break;
                    }
                }
                if (safe) {
                    for (j = 0; j < nr; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    can_execute = 1;
                    count++;
                    break;
                }
            }
        }
        if (!can_execute) {
            deadlock = 1;
            break;
        }
    }

    if (deadlock) {
        printf("Deadlock detected\n");
    } else {
        printf("No Deadlock possible\n");
    }

    return 0;
}

/*
START
Define global variables np (number of processes) and nr (number of resources).
Initialize arrays alloc[10][10], request[10][10], avail[10], r[10], w[10], and finish[10].
Initialize variables i, j, k, deadlock, and count.
Input the number of processes (np) and the number of resources (nr).
Input the total amount of each resource (r[i]) where i is the resource index.
Input the allocation matrix (alloc[i][j]) where i is the process index and j is the resource index.
Input the request matrix (request[i][j]) where i is the process index and j is the resource index.
Calculate the available resources (avail[j]) by subtracting the allocated resources from the total resources.
Initialize deadlock as 0 and count as 0.
Implement the deadlock detection algorithm using a loop:
a. Loop until count reaches np (all processes can execute) or a deadlock is detected.
b. For each process i that is not marked as finished (!finish[i]):
i. Check if the requested resources for process i are less than or equal to the available resources (request[i][j] <= avail[j] for all j).
ii. If all requested resources can be allocated (safe is true), allocate resources, mark the process as finished, increment count, and exit the loop.
c. If no process can be executed (can_execute is false), set deadlock to 1 and exit the loop.
Print the deadlock detection result.
STOP
*/

/*
Enter the no of processes: 3
Enter the no of resources: 4
Total Amount of the Resource R1: 5
Total Amount of the Resource R2: 4
Total Amount of the Resource R3: 7
Total Amount of the Resource R4: 6
Enter the allocation matrix:
0 0 0 1
1 3 5 4
2 3 5 6
Enter the request matrix:
0 0 0 1
1 0 1 2
1 0 0 0
Deadlock detected

*/