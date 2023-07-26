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
        for (int j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) {
                allocation[i] = j;
                bsize[j] -= psize[i];
                break;
            }
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

/*
START
Initialize variables bsize, psize, bno, pno, flags, and allocation.
Set all elements of flags to 0 and all elements of allocation to -1 to indicate that no blocks are allocated initially.
Prompt the user to enter the number of blocks (bno) and read the input.
Prompt the user to enter the size of each block (bsize) and read the inputs in a loop.
Prompt the user to enter the number of processes (pno) and read the input.
Prompt the user to enter the size of each process (psize) and read the inputs in a loop.
Start allocating processes to blocks by iterating through each process and each block:
a. Check if the block is not already allocated and has enough space to accommodate the current process (psize[i]).
b. If the conditions are met, allocate the process to the block, set the flags of the block to 1 (indicating it's allocated), and break the inner loop.
c. If no suitable block is found for the current process, it remains unallocated.
Display the allocation results for each process in the format: Processno, Procesize, Blockno:
a. If allocation[i] is not -1, print the block number where the process is allocated (add 1 to convert index to block number).
b. If allocation[i] is -1, print "Not Allocated" for that process.
STOP
*/

/*
Enter the no. of blocks: 5
Enter the size of each block: 100 200 300 150 250
Enter the no. of processes: 4
Enter the size of each process: 130 250 70 180

Processno   Procesize   Blockno
1           130         3
2           250         2
3           70          1
4           180         Not Allocated

*/