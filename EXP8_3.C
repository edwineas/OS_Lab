#include <stdio.h>

int main() {
    int total_frames, total_pages, hit = 0;
    int m, n, page, flag, k, minimum_time, temp;
    int pages[20], frames[10], arr[20], time[20];

    printf("Enter the number of pages: ");
    scanf("%d", &total_pages);

    printf("Enter the capacity of frames: ");
    scanf("%d", &total_frames);

    for (m = 0; m < total_frames; m++)
        frames[m] = -1;

    for (m = 0; m < 25; m++)
        arr[m] = -1;

    printf("Enter the reference String (RS): ");
    for (m = 0; m < total_pages; m++)
        scanf("%d", &pages[m]);

    for (m = 0; m < total_pages; m++) {
        arr[pages[m]]++;
        time[pages[m]] = m;
        flag = 0;
        k = frames[0];

        for (n = 0; n < total_frames; n++) {
            if (frames[n] == -1 || frames[n] == pages[m]) {
                if (frames[n] != -1)
                    hit++;
                flag = 1;
                frames[n] = pages[m];
                break;
            }
            if (arr[k] > arr[frames[n]])
                k = frames[n];
        }

        if (!flag) {
            minimum_time = 25;
            for (n = 0; n < total_frames; n++) {
                if (arr[frames[n]] == arr[k] && time[frames[n]] < minimum_time) {
                    temp = n;
                    minimum_time = time[frames[n]];
                }
            }
            arr[frames[temp]] = 0;
            frames[temp] = pages[m];
        }

        printf("RS: %d | ", pages[m]);
        for (int j = 0; j < total_frames; j++) {
            if (frames[j] == -1)
                printf(" _");
            else
                printf(" %d", frames[j]);
        }
        printf("\n");
    }

    printf("Page fault: %d \n", total_pages - hit);
    printf("Page hit: %d\n", hit);
    printf("Page fault ratio: %.2f%%\n", (float)(total_pages - hit) * 100 / total_pages);
    printf("Page hit ratio: %.2f%%\n", (float)hit * 100 / total_pages);

    return 0;
}


/*
START
Initialize variables total_frames, total_pages, hit, m, n, page, flag, k, minimum_time, and temp.
Initialize arrays pages, frames, arr, and time.
Input the number of pages (total_pages), the capacity of frames (total_frames), and the reference string (RS) of pages (pages).
Initialize the frames frames with -1 and the arrays arr and time with -1 to indicate all frames and page occurrences are initially empty.
Loop through the reference string (pages) and simulate the page replacement process:
a. Update the occurrence count of each page in the array arr and the last accessed time in the array time.
b. Check if the current page is already present in any frame.
c. If the page is found, update the hit counter and continue to the next page reference.
d. If there's a free frame or no frame contains the current page, allocate it to an available frame or replace the least recently used (LRU) page in the frames.
e. Print the reference string (RS) and the current state of the frames after each page reference.
Print the statistics: total page faults, page hits, page fault ratio, and page hit ratio.
STOP
*/

/*
Enter the number of pages: 12
Enter the capacity of frames: 3
Enter the reference String (RS): 7 0 1 2 0 3 0 4 2 3 1 2
RS: 7 | 7 _ _
RS: 0 | 7 0 _
RS: 1 | 7 0 1
RS: 2 | 2 0 1
RS: 0 | 2 0 1
RS: 3 | 2 0 3
RS: 0 | 2 0 3
RS: 4 | 4 0 3
RS: 2 | 4 2 3
RS: 3 | 4 2 3
RS: 1 | 4 1 3
RS: 2 | 4 1 2
Page fault: 8 
Page hit: 4
Page fault ratio: 66.67%
Page hit ratio: 33.33%

*/