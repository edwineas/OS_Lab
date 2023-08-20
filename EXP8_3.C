#include <stdio.h>

int main() {
    int referenceString[100], numPages, numFrames, frames[10], pageFaults = 0, pageAges[10] = {0}, pageFrequencies[10] = {0};

    printf("Enter the number of pages: "); // 10
    scanf("%d", &numPages);

    printf("Enter the reference string: "); // 1 2 3 4 1 2 5 1 2 3 4 5
    for (int i = 0; i < numPages; i++)
        scanf("%d", &referenceString[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    for (int i = 0; i < numFrames; i++)
        frames[i] = -1; // -1 indicates empty frame

    for (int i = 0; i < numPages; i++) {
        int pageFound = 0;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == referenceString[i]) {
                pageFound = 1;
                pageFrequencies[j]++;
                break;
            }
        }

        if (!pageFound) {
            int lfuIndex = 0, minFrequency = pageFrequencies[0];
            int maxAge = pageAges[0]; // Initialize maxAge with the age of the first frame
            for (int j = 1; j < numFrames; j++) {
                if (pageFrequencies[j] < minFrequency || (pageFrequencies[j] == minFrequency && pageAges[j] > maxAge)) {
                    lfuIndex = j;
                    minFrequency = pageFrequencies[j];
                    maxAge = pageAges[j]; // Update maxAge when frequency ties
                }
            }
            frames[lfuIndex] = referenceString[i];
            pageFrequencies[lfuIndex] = 1;
            pageFaults++;
            pageAges[lfuIndex]=0;
        }

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                pageAges[j]++;
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
