#include <stdio.h>

void main() {
    int n, m[20], i, j, sb[20], s[20], b[20][20], x;
    
    printf("Enter no. of files:");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter starting block and size of file %d:", i + 1);
        scanf("%d %d", &sb[i], &s[i]);
        printf("Enter blocks occupied by file %d:", i + 1);
        scanf("%d", &m[i]);
        printf("Enter blocks of file %d:", i + 1);
        for (j = 0; j < m[i]; j++)
            scanf("%d", &b[i][j]);
    }
    
    printf("\nFile\t index\tlength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
    }
    
    printf("\nEnter file name:");
    scanf("%d", &x);
    printf("File name is: %d\n", x);
    i = x - 1;
    printf("Index is: %d\n", sb[i]);
    printf("Block occupied are:");
    for (j = 0; j < m[i]; j++) {
        printf("%3d", b[i][j]);
    }
    printf("\n");
}

/*
START
Declare variables n, m[20], i, j, sb[20], s[20], b[20][20], and x.
Input the number of files (n).
Loop i through each file:
a. Input the starting block (sb[i]) and size (s[i]) of file i+1.
b. Input the number of blocks occupied by file i+1 (m[i]).
c. Input the blocks occupied by file i+1 and store them in b[i][j].
Print the file details:
a. Print the header for the table: "File\t index\tlength".
b. Loop through each file and print file name (i+1), index (sb[i]), and length (m[i]).
Input the file name to search (x).
Print the details of the specified file:
a. Print the file name: "File name is: %d\n", x.
b. Set i as x - 1.
c. Print the index: "Index is: %d\n", sb[i].
d. Print the blocks occupied: "Blocks occupied are:" followed by the block numbers from b[i][0] to b[i][m[i] - 1].
STOP
*/

/*
Enter no. of files: 3
Enter starting block and size of file 1: 10 4
Enter blocks occupied by file 1: 3
Enter blocks of file 1: 20 21 22
Enter starting block and size of file 2: 30 5
Enter blocks occupied by file 2: 4
Enter blocks of file 2: 25 26 27 28
Enter starting block and size of file 3: 40 3
Enter blocks occupied by file 3: 2
Enter blocks of file 3: 30 31

File     index   length
1        10      3
2        30      4
3        40      2

Enter file name: 2
File name is: 2
Index is: 30
Block occupied are: 25 26 27 28

*/