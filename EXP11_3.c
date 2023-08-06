#include <stdio.h>

struct file
{
    char fname[10];
    int start, size, block[10];
} f[10];

int main()
{
    int i, j, n;
    printf("Enter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter file name:");
        scanf("%s", f[i].fname);  // Remove the & before f[i].fname
        printf("Enter starting block:");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter no. of blocks:");
        scanf("%d", &f[i].size);

        printf("Enter block numbers:");
        for (j = 1; j <= f[i].size; j++)
        {
            scanf("%d", &f[i].block[j]);
        }
    }
    printf("File\tstart\tsize\tblock\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (j = 1; j <= f[i].size - 1; j++)
            printf("%d--->", f[i].block[j]);
        printf("%d", f[i].block[j]);
        printf("\n");
    }

    return 0;
}


/*
Enter no. of files: 3
Enter file name: file1
Enter starting block: 10
Enter no. of blocks: 4
Enter block numbers: 10 11 12 13
Enter file name: file2
Enter starting block: 20
Enter no. of blocks: 3
Enter block numbers: 20 21 22
Enter file name: file3
Enter starting block: 30
Enter no. of blocks: 2
Enter block numbers: 30 31

File    start   size    block
file1   10      4       10--->11--->12--->13
file2   20      3       20--->21--->22
file3   30      2       30--->31

*/