//code
#include <stdio.h>

int main()
{
    int n, a[100], i, j;
    int k, t, total = 0;
    int maxSum, currentSum;
    int start = 0, end = 0;
    int inversions = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        total += a[i];
    }

    scanf("%d %d", &k, &t);

    maxSum = a[0];
    currentSum = 0;

    for(i = 0; i < n; i++)
    {
        currentSum = 0;

        for(j = i; j < n; j++)
        {
            currentSum += a[j];

            if(currentSum > maxSum)
            {
                maxSum = currentSum;
                start = i;
                end = j;
            }
        }
    }

    printf("Total Distance: %d\n", total);
    printf("Maximum Contiguous Distance: %d\n", maxSum);
    printf("Starting Position: %d\n", start + 1);
    printf("Ending Position: %d\n", end + 1);

    int minLength = n + 1;

    for(i = 0; i < n; i++)
    {
        int sum = 0;

        for(j = i; j < n; j++)
        {
            sum += a[j];

            if(sum >= t)
            {
                if(j - i + 1 < minLength)
                    minLength = j - i + 1;

                break;
            }
        }
    }

    if(minLength == n + 1)
        minLength = 0;

    printf("Minimum Locations Required: %d\n", minLength);

    printf("Rotated Array: ");

    k = k % n;

    for(i = n - k; i < n; i++)
        printf("%d ", a[i]);

    for(i = 0; i < n - k; i++)
        printf("%d ", a[i]);

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
                inversions++;
        }
    }

    printf("\nInversion Count: %d", inversions);

    return 0;
}
//sample input
3 3
80 75 90
60 85 70
95 90 85
  //output
  Total Distance: 20
Maximum Contiguous Distance: 20
Starting Position: 1
Ending Position: 7
Minimum Locations Required: 2
Rotated Array: 6 1 2 3 1 5 2
Inversion Count: 8
