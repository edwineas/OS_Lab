#include <stdio.h>
#include <limits.h>  // Include this library for using INT_MAX

int main() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    
    for (i = 0; i < 10; i++) {
        flags[i] = 0;
        allocation[i] = -1;
    }
    
    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    
    printf("Enter the size of each block: ");
    for (i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    
    printf("Enter the size of each process: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
    }
    
    for (int i = 0; i < pno; i++) {
        int bestFitIdx = -1;
        for (int j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) {
                if (bestFitIdx == -1 || bsize[j] < bsize[bestFitIdx]) {
                    bestFitIdx = j;
                }
            }
        }
        
        if (bestFitIdx != -1) {
            allocation[i] = bestFitIdx;
            bsize[bestFitIdx] -= psize[i];
        }
    }
    
    printf("\nProcess no\tProcess size\tBlock no\n");
    for (int i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

