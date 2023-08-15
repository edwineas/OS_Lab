#include <stdio.h>

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
        int worstFitIdx = -1;
        for (int j = 0; j < bno; j++) {
            if (!flags[j] && bsize[j] >= psize[i]) {
                if (worstFitIdx == -1 || bsize[j] > bsize[worstFitIdx]) {
                    worstFitIdx = j;
                }
            }
        }
        
        if (worstFitIdx != -1) {
            allocation[i] = worstFitIdx;
            flags[worstFitIdx] = 1; // Mark the block as allocated
            bsize[worstFitIdx] -= psize[i];
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
