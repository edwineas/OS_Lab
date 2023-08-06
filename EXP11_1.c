#include <stdio.h>

void main() {
    int n, i, j, b[20], sb[20], t[20], x, c[20][20];
    
    printf("Enter no. of files:");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter no. of blocks occupied by file %d:", i + 1);
        scanf("%d", &b[i]);
        printf("Enter the starting block of file %d:", i + 1);
        scanf("%d", &sb[i]);
        t[i] = sb[i];
        for (j = 0; j < b[i]; j++) {
            c[i][j] = sb[i]++;
        }
    }
    
    printf("\nFilename\tStart block\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);
    }
    
    printf("Enter file name:");
    scanf("%d", &x);
    
    printf("File name is: %d\n", x);
    printf("Length is: %d\n", b[x - 1]);
    printf("Blocks occupied:");
    for (i = 0; i < b[x - 1]; i++) {
        printf("%4d", c[x - 1][i]);
    }
    printf("\n");
}

/*

Here's the simplified and structured algorithm for the given file allocation program based on the provided C code:

START
Declare variables n, i, j, b[20], sb[20], t[20], x, and c[20][20].
Input the number of files (n).
Loop i through each file:
a. Input the number of blocks occupied by file i+1 (b[i]).
b. Input the starting block of file i+1 (sb[i]).
c. Set t[i] as sb[i].
d. Loop j through each block of the file:
i. Calculate the block numbers and store them in c[i][j].
Print the file details:
a. Print the header for the table: "Filename\tStart block\tLength".
b. Loop through each file and print filename (i+1), start block (t[i]), and length (b[i]).
Input the file name to search (x).
Print the details of the specified file:
a. Print the file name: "File name is: %d\n", x.
b. Print the length: "Length is: %d\n", b[x - 1].
c. Print the blocks occupied: "Blocks occupied:" followed by the block numbers from c[x - 1][0] to c[x - 1][b[x - 1] - 1].
STOP
*/

/*
Enter no. of files: 3
Enter no. of blocks occupied by file 1: 4
Enter the starting block of file 1: 10
Enter no. of blocks occupied by file 2: 3
Enter the starting block of file 2: 20
Enter no. of blocks occupied by file 3: 5
Enter the starting block of file 3: 30

Filename    Start block    Length
1           10             4
2           20             3
3           30             5
Enter file name: 2
File name is: 2
Length is: 3
Blocks occupied:  20  21  22

*/