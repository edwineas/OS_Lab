#include <stdio.h>

int main()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, best_index;
    static int barray[20], parray[20];

    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);

    printf("\nEnter the number of processes:");
    scanf("%d", &np);

    printf("\nEnter the size of each blocks:");
    for (i = 0; i < nb; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of each processes:");
    for (i = 0; i < np; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < np; i++)
    {
        best_index = -1;
        temp = -1;
        
        for (j = 0; j < nb; j++)
        {
            if (barray[j] == 0 && b[j] >= p[i])
            {
                if (best_index == -1 || b[j] - p[i] < temp)
                {
                    best_index = j;
                    temp = b[j] - p[i];
                }
            }
        }

        if (best_index != -1)
        {
            parray[i] = best_index;
            fragment[i] = b[best_index] - p[i];
            barray[best_index] = 1;
        }
        else
        {
            parray[i] = -1;
            fragment[i] = -1;
        }
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 0; i < np; i++)
    {
        printf("\n%d\t\t%d\t\t", i + 1, p[i]);
        if (parray[i] != -1)
        {
            printf("%d\t\t%d\t\t%d", parray[i] + 1, b[parray[i]], fragment[i]);
        }
        else
        {
            printf("Not Allocated\tNot Allocated\tNot Allocated");
        }
    }
}

/*
START
Attach necessary libraries (already done in the provided code).
Initialize variables fragment, b, p, i, j, nb, np, temp, and best_index.
Create static arrays barray and parray to keep track of allocated blocks and processes, respectively.
Prompt the user to enter the number of blocks (nb) and read the input.
Prompt the user to enter the number of processes (np) and read the input.
Prompt the user to enter the size of each block (b) using a loop to read the inputs.
Prompt the user to enter the size of each process (p) using a loop to read the inputs.
For each process (p[i]), find the best-fit block (b[best_index]) to allocate it:
a. Set best_index and temp to -1 initially.
b. Iterate through each block (b[j]) to find the best-fit block:
i. Check if the block is not already allocated (barray[j] == 0) and has enough space to accommodate the current process (b[j] >= p[i]).
ii. If the above condition is met, check if best_index is -1 (no block has been selected yet) or if the current block's space left is smaller than the previous best-fit block (b[j] - p[i] < temp).
iii. If the current block is a better fit, update best_index and temp with the current block index and the remaining space (b[j] - p[i]), respectively.
c. If a suitable block is found (best_index is not -1), store the index of the selected block in parray[i], calculate the external fragmentation for this process (fragment[i] = b[best_index] - p[i]), and mark the block as allocated by setting barray[best_index] to 1.
d. If no suitable block is found (best_index is -1), store -1 in parray[i] to indicate that the process is not allocated, and set fragment[i] to -1.
Print the allocation results for each process in the format: Process_no, Process_size, Block_no, Block_size, Fragment:
a. If parray[i] is not -1, print the block number where the process is allocated (parray[i] + 1), the size of the selected block (b[parray[i]]), and the external fragmentation for that process (fragment[i]).
b. If parray[i] is -1, print "Not Allocated" for the block number, block size, and external fragmentation for that process.
STOP
*/

/*
Enter the number of blocks: 5
Enter the number of processes: 4

Enter the size of each blocks: 100 200 300 150 250

Enter the size of each processes: 130 250 70 180

Process_no  Process_size    Block_no    Block_size  Fragment
1           130             1           100         30
2           250             3           300         50
3           70              2           200         130
4           180             5           250         70 
*/