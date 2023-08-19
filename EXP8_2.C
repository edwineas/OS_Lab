#include <stdio.h>

int main() {
    int referenceString[100], numPages, numFrames, frames[10], pageFaults = 0, frameIndex = 0, pageAges[10];

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the reference string: ");
    for (int i = 0; i < numPages; i++)
        scanf("%d", &referenceString[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
        pageAges[i] = 0;
    }

    for (int i = 0; i < numPages; i++) {
        int pageFound = 0;
        
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == referenceString[i]) {
                pageFound = 1;
                pageAges[j] = i + 1;
                break;
            }
        }

        if (!pageFound) {
            int lruIndex = 0, minAge = pageAges[0];
            for (int j = 1; j < numFrames; j++) {
                if (pageAges[j] < minAge) {
                    lruIndex = j;
                    minAge = pageAges[j];
                }
            } // lruIndex now contains the index of the least recently used page
            frames[lruIndex] = referenceString[i];
            pageAges[lruIndex] = i + 1;
            pageFaults++;
        }

        printf("RS: %d | ", referenceString[i]);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == -1)
                printf("_ ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    int pageHits = numPages - pageFaults;

    printf("Page faults: %d\n", pageFaults);
    printf("Page Hits: %d\n", pageHits);
    printf("Page Fault Ratio: %.2f%%\n", (float)pageFaults * 100 / numPages);
    printf("Page Hit Ratio: %.2f%%\n", (float)pageHits * 100 / numPages);

    return 0;
}
