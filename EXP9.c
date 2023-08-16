#include <stdio.h>

int main() {
    int np, nr;

    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the number of resources: ");
    scanf("%d", &nr);

    int alloc[np][nr], max[np][nr], avail[nr], need[np][nr], finish[np], safesequence[np];

    // Initialize finish array to 0
    for (int i = 0; i < np; i++) {
        finish[i] = 0;
    }

    // Read allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Read maximum matrix
    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++)
            scanf("%d", &max[i][j]);
    }

    // Read available resources
    printf("Enter the available matrix:\n");
    for (int i = 0; i < nr; i++)
        scanf("%d", &avail[i]);

    // Calculate need matrix and print it
    printf("NEED matrix is:\n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Find a safe sequence
    int ind = 0;
    for (int i = 0; i < np; i++) {
        if (!finish[i]) {
            int canAllocate = 1;
            for (int j = 0; j < nr; j++) {
                if (need[i][j] > avail[j]) {
                    canAllocate = 0;
                    break;
                }
            }
            if (canAllocate) {
                safesequence[ind++] = i;
                for (int j = 0; j < nr; j++)
                    avail[j] += alloc[i][j];
                finish[i] = 1;
                i = -1;  // Start checking from the beginning again
            }
        }
    }

    // Print the safe sequence
    printf("\nFollowing is the SAFE Sequence:\n");
    for (int i = 0; i < np; i++) {
        printf("P%d", safesequence[i]);
        if (i < np - 1)
            printf(" -> ");
    }
    printf("\n");

    return 0;
}
