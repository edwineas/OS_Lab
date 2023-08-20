 printf("Page faults: %d\n", pageFaults);
    printf("Page Hits: %d\n", pageHits);
    printf("Page Fault Ratio: %.2f%%\n", (float)pageFaults * 100 / numPages);
    printf("Page Hit Ratio: %.2f%%\n", (float)pageHits * 100 / numPages);
