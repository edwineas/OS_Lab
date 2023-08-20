    #include <stdio.h>
    int main() {
        int n;
        printf("Enter the number of process to be inserted: ");
        scanf("%d", &n);
        int a[n][5], i, j, k, temp;
        float atat, awt, ttat = 0, twt = 0;
        for (i = 0; i < n; i++) {
            printf("Enter the arrival time and burst time of P%d: ", i);
            scanf("%d%d", &a[i][1], &a[i][2]);
        }
        for (i = 0; i < n - 1; i++) //sorting according to arrival time
            for (j = 0; j < n - 1 - i; j++)
                if (a[j][1] > a[j + 1][1])
                    for (k = 1; k <= 2; k++) {
                        temp = a[j][k];
                        a[j][k] = a[j + 1][k];
                        a[j + 1][k] = temp;
                    }
        a[0][3] = a[0][2] + a[0][1];
        for (i = 1; i < n; i++)
            a[i][3] = a[i - 1][3] + a[i][2];
        for (i = 0; i < n; i++)
            a[i][4] = a[i][3] - a[i][1];
        for (i = 0; i < n; i++)
            a[i][5] = a[i][4] - a[i][2];
        for (i = 0; i < n; i++) {
            ttat = ttat + a[i][4];
            twt = twt + a[i][5];
        }
        atat = ttat / n;
        awt = twt / n;
        printf("P\tat\tbt\ttat\tt\n");
        for (i = 0; i < n; i++)
            printf("%d\t%d\t%d\t%d\t%d\n", i, a[i][1], a[i][2], a[i][4], a[i][5]);
        printf("awt:%f | atat:%f\n", awt, atat);
    }
