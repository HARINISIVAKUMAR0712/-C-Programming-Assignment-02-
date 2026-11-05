//code
#include <stdio.h>

int main()
{
    int n, m, a[50][50];
    int i, j;
    int maxCity = 0, maxDay = 0;
    int count = 0;
    float cityAvg[50], dayAvg[50];
    float total = 0, overallAvg;

    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
            total += a[i][j];
        }
    }

    overallAvg = total / (n * m);

    printf("City Averages: ");

    for(i = 0; i < n; i++)
    {
        int sum = 0;

        for(j = 0; j < m; j++)
            sum += a[i][j];

        cityAvg[i] = (float)sum / m;

        printf("%.2f ", cityAvg[i]);

        if(cityAvg[i] > cityAvg[maxCity])
            maxCity = i;
    }

    printf("\nDaily Maximum: ");

    for(j = 0; j < m; j++)
    {
        int max = a[0][j];

        for(i = 1; i < n; i++)
        {
            if(a[i][j] > max)
                max = a[i][j];
        }

        printf("%d ", max);
    }

    printf("\nDaily Minimum: ");

    for(j = 0; j < m; j++)
    {
        int min = a[0][j];

        for(i = 1; i < n; i++)
        {
            if(a[i][j] < min)
                min = a[i][j];
        }

        printf("%d ", min);
    }

    for(j = 0; j < m; j++)
    {
        int sum = 0;

        for(i = 0; i < n; i++)
            sum += a[i][j];

        dayAvg[j] = (float)sum / n;

        if(dayAvg[j] > dayAvg[maxDay])
            maxDay = j;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(a[i][j] > overallAvg)
                count++;
        }
    }

    printf("\nHighest Average City: %d", maxCity + 1);
    printf("\nHighest Average Day: %d", maxDay + 1);
    printf("\nTemperatures Above Overall Average: %d", count);

    printf("\nContinuously Increasing Cities: ");

    for(i = 0; i < n; i++)
    {
        int flag = 1;

        for(j = 1; j < m; j++)
        {
            if(a[i][j] <= a[i][j - 1])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("%d ", i + 1);
    }

    printf("\nSpiral Order: ");

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while(top <= bottom && left <= right)
    {
        for(j = left; j <= right; j++)
            printf("%d ", a[top][j]);

        top++;

        for(i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);

        right--;

        if(top <= bottom)
        {
            for(j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);

            bottom--;
        }

        if(left <= right)
        {
            for(i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);

            left++;
        }
    }

    return 0;
}
//sample input
3 4
25 27 29 31
22 24 26 28
30 29 28 27
  //output
  City Averages: 28.00 25.00 28.50
Daily Maximum: 30 29 29 31
Daily Minimum: 22 24 26 27
Highest Average City: 3
Highest Average Day: 4
Temperatures Above Overall Average: 6
Continuously Increasing Cities: 1 2
Spiral Order: 25 27 29 31 28 27 28 29 30 22 24 26
