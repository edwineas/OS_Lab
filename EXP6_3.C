#include <stdio.h>

int main()
{
    int bsize[20], psize[20];
    int all[20], m, n, i, j;
    
    printf("Enter the number of blocks:");
    scanf("%d", &m);
    
    printf("Enter the size of each block:");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &bsize[i]);
    }
    
    printf("Enter the number of processes:");
    scanf("%d", &n);
    
    printf("Enter the size of each process:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &psize[i]);
        all[i] = -1;
    }
    
    for (i = 0; i < n; i++)
    {
        int worstplace = -1;
        for (j = 0; j < m; j++)
        {
            if (bsize[j] >= psize[i])
            {
                if (worstplace == -1)
                    worstplace = j;
                else if (bsize[worstplace] < bsize[j])
                    worstplace = j;
            }
        }
        if (worstplace != -1)
        {
            all[i] = worstplace;
            bsize[worstplace] -= psize[i];
        }
    }
    
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (all[i] != -1)
            printf("%d\n", all[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


/*
START
Attach necessary libraries (already done in the provided code).
Initialize arrays bsize, psize, and all, and variables m, n, i, and j.
Prompt the user to enter the number of blocks (m) and read the input.
Prompt the user to enter the size of each block (bsize) using a loop to read the inputs.
Prompt the user to enter the number of processes (n) and read the input.
Prompt the user to enter the size of each process (psize) using a loop to read the inputs, and set all elements of all to -1 to indicate no process is allocated initially.
For each process (psize[i]), find the worst-fit block to allocate it:
a. Initialize worstplace to -1 (indicating no block is selected yet).
b. Iterate through each block (bsize[j]) to find the worst-fit block:
i. Check if the block has enough space to accommodate the current process (bsize[j] >= psize[i]).
ii. If the above condition is met, check if worstplace is -1 (no block has been selected yet) or if the current block's size is larger than the previous worst-fit block (bsize[worstplace] < bsize[j]).
iii. If the current block has more space, update worstplace with the current block index.
c. If a suitable block is found (worstplace is not -1), store the index of the selected block in all[i], and reduce the size of the block by the size of the allocated process (bsize[worstplace] -= psize[i]).
Print the allocation results for each process in the format: Process No., Process Size, Block no.:
a. If all[i] is not -1, print the block number where the process is allocated (all[i] + 1).
b. If all[i] is -1, print "Not Allocated" for that process.
STOP
*/

/*
Enter the number of blocks: 5
Enter the size of each block: 100 200 300 150 250
Enter the number of processes: 4
Enter the size of each process: 130 250 70 180

Process No.  Process Size    Block no.
1           130             3
2           250             3
3           70              2
4           180             5
*/