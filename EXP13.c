#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int c = 99, fd, sz;
    char *c1 = (char *)calloc(100, sizeof(char));

    while (c != 0) {
        printf("CHOOSE OPERATION\n 1.Create\n 2.Open\n 3.Close\n 4.Write\n 5.Read\n 6.Exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1:
                fd = creat("f1.txt", 0777);
                printf("fd=%d\n", fd);
                close(fd);
                break;

            case 2:
                fd = open("f1.txt", O_RDONLY | O_CREAT, 0777);
                printf("Opened the file with fd=%d\n", fd);
                close(fd);
                break;

            case 3:
                close(fd);
                printf("Closed the file with fd=%d\n", fd);
                break;

            case 4:
                fd = open("f1.txt", O_WRONLY | O_CREAT, 0777);
                sz = write(fd, "hi,hello\n", strlen("hi,hello\n"));
                close(fd);
                break;

            case 5:
                fd = open("f1.txt", O_RDONLY);
                sz = read(fd, c1, 10);
                printf("Size of character string sz=%d\n", sz);
                printf("fd=%d\n", fd);
                c1[sz] = '\0';
                printf("Content in the file is %s\n", c1);
                close(fd);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}


/*
1. START
2. Initialize variables: c = 99, fd, sz, c1[100].
3. Loop while c is not 0:
    4. Display menu and input user choice (c).
    5. Switch based on c:
        6. If choice is 1:
            7. Create a file "f1.txt" with permission 0777.
            8. Close the file.
        9. Else, if choice is 2:
            10. Open "f1.txt" for reading and writing (create if not exists) with permission 0777.
            11. Close the file.
        12. Else, if choice is 3:
            13. Close the file (if open).
        14. Else, if choice is 4:
            15. Open "f1.txt" for writing (create if not exists) with permission 0777.
            16. Write "hi,hello\n" to the file.
            17. Close the file.
        18. Else, if choice is 5:
            19. Open "f1.txt" for reading.
            20. Read up to 10 characters into c1 and store read size in sz.
            21. Print read content and size.
            22. Close the file.
        23. Else, if choice is 6: 
            24. Exit the program.
        25. Otherwise:
            26. Print "Invalid choice".
    27. End switch.
28. End loop.
29. STOP

*/

/*
CHOOSE OPERATION
1. Create
2. Open
3. Close
4. Write
5. Read
6. Exit
1
fd=3

CHOOSE OPERATION
1. Create
2. Open
3. Close
4. Write
5. Read
6. Exit
2
Opened the file with fd=3

CHOOSE OPERATION
1. Create
2. Open
3. Close
4. Write
5. Read
6. Exit
4
Enter the content to write: Hello, world!
Size of character string sz=13

CHOOSE OPERATION
1. Create
2. Open
3. Close
4. Write
5. Read
6. Exit
5
Size of character string sz=13
fd=3
Content in the file is Hello, world!

CHOOSE OPERATION
1. Create
2. Open
3. Close
4. Write
5. Read
6. Exit
6

*/