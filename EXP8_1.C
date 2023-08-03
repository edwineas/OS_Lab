#include <stdio.h>

int main() {
    int i, j, page[100], n, capacity, frame[10];
    int pagefault = 0, frameindex = 0, frameavailable = 0, pagefound = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string (RS): ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter the capacity of frames: ");
    scanf("%d", &capacity);

    for (i = 0; i < capacity; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        pagefound = 0;

        for (j = 0; j < capacity; j++) {
            if (frame[j] == page[i]) {
                pagefound = 1;
                break;
            }
        }

        if (!pagefound) {
            if (frameavailable < capacity) {
                frame[frameavailable] = page[i];
                frameavailable++;
            } else {
                frame[frameindex] = page[i];
                frameindex = (frameindex + 1) % capacity;
            }
            pagefault++;
        }

        printf("RS: %d |", page[i]);
        for (j = 0; j < capacity; j++) {
            if (frame[j] == -1)
                printf(" _");
            else
                printf(" %d", frame[j]);
        }
        printf("\n");
    }

    printf("Page faults: %d\n", pagefault);
    printf("Page Hits: %d\n", n - pagefault);
    printf("Page Fault Ratio: %f\n", (float)pagefault * 100 / n);
    printf("Page Hit Ratio: %f\n", (float)(n - pagefault) * 100 / n);

    return 0;
}

/*
START
Initialize variables i, j, page, n, capacity, frame, pagefault, frameindex, and frameavailable.
Input the number of pages (n), the reference string (RS) of pages (page), and the capacity of frames (capacity).
Initialize the frames frame with -1 to indicate all frames are initially empty.
Initialize pagefault, frameindex, and frameavailable to 0.
Loop through the reference string (page) and simulate the page replacement process:
a. Check if the current page is already present in any frame.
b. If the page is not found, allocate it to an available frame or replace a page in the frame at frameindex.
c. Update the frameindex to the next frame (circularly) using (frameindex + 1) % capacity.
d. Increment the pagefault counter for each page fault.
e. Print the reference string (RS) and the current state of the frames after each page reference.
Print the statistics: total page faults, page hits, page fault ratio, and page hit ratio.
STOP
*/

/*
Enter the number of pages: 10
Enter the reference string (RS): 7 0 1 2 0 3 0 4 2 3
Enter the capacity of frames: 4
RS: 7 | 7 _ _ _
RS: 0 | 7 0 _ _
RS: 1 | 7 0 1 _
RS: 2 | 7 0 1 2
RS: 0 | 7 0 1 2
RS: 3 | 3 0 1 2
RS: 0 | 3 0 1 2
RS: 4 | 3 4 1 2
RS: 2 | 3 4 2 2
RS: 3 | 3 4 2 3
Page faults: 7
Page Hits: 3
Page Fault Ratio: 70.000000
Page Hit Ratio: 30.000000
*/