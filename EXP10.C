#include <stdio.h>

int numProcesses, numResources;

int main() {
    int allocated[10][10], requested[10][10], totalResources[10], availableResources[10], work[10], finished[10] = {0};
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    for (i = 0; i < numResources; i++) {
        printf("Total amount of Resource R%d: ", i + 1);
        scanf("%d", &totalResources[i]);
    }

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < numProcesses; i++) {
        for (j = 0; j < numResources; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter the request matrix:\n");
    for (i = 0; i < numProcesses; i++) {
        for (j = 0; j < numResources; j++) {
            scanf("%d", &requested[i][j]);
        }
    }

    // Calculate the available resources
    for (j = 0; j < numResources; j++) {
        availableResources[j] = totalResources[j];
        for (i = 0; i < numProcesses; i++) {
            availableResources[j] -= allocated[i][j];
        }
    }

    int deadlockDetected = 0;
    int processesFinished = 0;

    while (processesFinished < numProcesses) {
        int processExecuted = 0;
        for (i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                int isSafe = 1;
                for (j = 0; j < numResources; j++) {
                    if (requested[i][j] > availableResources[j]) {
                        isSafe = 0;
                        break;
                    }
                }
                if (isSafe) {
                    for (j = 0; j < numResources; j++) {
                        availableResources[j] += allocated[i][j];
                    }
                    finished[i] = 1;
                    processExecuted = 1;
                    processesFinished++;
                    break;
                }
            }
        }
        if (!processExecuted) {
            deadlockDetected = 1;
            break;
        }
    }

    if (deadlockDetected) {
        printf("Deadlock detected\n");
    } else {
        printf("No deadlock possible\n");
    }

    return 0;
}
