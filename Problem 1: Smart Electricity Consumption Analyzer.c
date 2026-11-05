//code
#include <stdio.h>

int main()
{
    int n, a[100], i, total = 0;
    int max, min, count = 0;

    float avg;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        total += a[i];
    }

    max = min = a[0];

    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];

        if(a[i] < min)
            min = a[i];
    }

    avg = (float)total / n;

    for(i = 0; i < n; i++)
    {
        if(a[i] > avg)
            count++;
    }

    printf("Total Consumption: %d\n", total);
    printf("Average Consumption: %.2f\n", avg);
    printf("Maximum Consumption: %d\n", max);
    printf("Minimum Consumption: %d\n", min);
    printf("Days Above Average: %d\n", count);

    printf("Maximum Consumption Position: ");

    for(i = 0; i < n; i++)
    {
        if(a[i] == max)
            printf("%d ", i + 1);
    }

    printf("\nReversed Array: ");

    for(i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    return 0;
}
//Sample Input
7
120 150 100 180 150 200 100
  //output
  Total Consumption: 1000
Average Consumption: 142.86
Maximum Consumption: 200
Minimum Consumption: 100
Days Above Average: 4
Maximum Consumption Position: 6
Reversed Array: 100 200 150 180 100 150 120
