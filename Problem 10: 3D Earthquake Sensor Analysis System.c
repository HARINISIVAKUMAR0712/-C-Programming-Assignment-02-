//code

#include <stdio.h>

int isPrime(int n)
{
    int i;

    if(n < 2)
        return 0;

    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int l, r, c;
    int a[20][20][20];
    int i, j, k;

    int total = 0;
    int max, min;
    int maxL, maxR, maxC;
    int minL, minR, minC;

    int layerTotal[20] = {0};
    int primeCount[20] = {0};
    int maxLayer = 0;

    int diagonal = 0;
    int localCount = 0;

    scanf("%d %d %d", &l, &r, &c);

    // Read sensor values
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < r; j++)
        {
            for(k = 0; k < c; k++)
            {
                scanf("%d", &a[i][j][k]);

                total += a[i][j][k];
                layerTotal[i] += a[i][j][k];

                if(i == 0 && j == 0 && k == 0)
                {
                    max = min = a[i][j][k];

                    maxL = minL = i;
                    maxR = minR = j;
                    maxC = minC = k;
                }

                if(a[i][j][k] > max)
                {
                    max = a[i][j][k];
                    maxL = i;
                    maxR = j;
                    maxC = k;
                }

                if(a[i][j][k] < min)
                {
                    min = a[i][j][k];
                    minL = i;
                    minR = j;
                    minC = k;
                }

                if(isPrime(a[i][j][k]))
                    primeCount[i]++;
            }
        }
    }

    // Total vibration intensity
    printf("Total Vibration Intensity: %d\n", total);

    // Highest and lowest vibration
    printf("Highest Vibration: %d\n", max);

    printf("Highest Position: (%d,%d,%d)\n",
           maxL + 1, maxR + 1, maxC + 1);

    printf("Lowest Vibration: %d\n", min);

    printf("Lowest Position: (%d,%d,%d)\n",
           minL + 1, minR + 1, minC + 1);

    // Layer-wise totals
    printf("Layer-wise Intensity:\n");

    for(i = 0; i < l; i++)
    {
        printf("Layer %d: %d\n", i + 1, layerTotal[i]);

        if(layerTotal[i] > layerTotal[maxLayer])
            maxLayer = i;
    }

    printf("Layer With Maximum Intensity: %d\n",
           maxLayer + 1);

    // Prime counts
    printf("Prime Counts:\n");

    for(i = 0; i < l; i++)
    {
        printf("Layer %d: %d\n",
               i + 1, primeCount[i]);
    }

    // Main space diagonal
    if(l == r && r == c)
    {
        for(i = 0; i < l; i++)
            diagonal += a[i][i][i];

        printf("Main Space Diagonal Sum: %d\n", diagonal);
    }

    // Local maximum sensors
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < r; j++)
        {
            for(k = 0; k < c; k++)
            {
                int flag = 1;

                // Up
                if(i > 0 && a[i][j][k] <= a[i-1][j][k])
                    flag = 0;

                // Down
                if(i < l-1 && a[i][j][k] <= a[i+1][j][k])
                    flag = 0;

                // Front
                if(j > 0 && a[i][j][k] <= a[i][j-1][k])
                    flag = 0;

                // Back
                if(j < r-1 && a[i][j][k] <= a[i][j+1][k])
                    flag = 0;

                // Left
                if(k > 0 && a[i][j][k] <= a[i][j][k-1])
                    flag = 0;

                // Right
                if(k < c-1 && a[i][j][k] <= a[i][j][k+1])
                    flag = 0;

                if(flag)
                    localCount++;
            }
        }
    }

    printf("Local Maximum Sensor Count: %d\n", localCount);

    printf("Local Maximum Position:\n");

    for(i = 0; i < l; i++)
    {
        for(j = 0; j < r; j++)
        {
            for(k = 0; k < c; k++)
            {
                int flag = 1;

                if(i > 0 && a[i][j][k] <= a[i-1][j][k])
                    flag = 0;

                if(i < l-1 && a[i][j][k] <= a[i+1][j][k])
                    flag = 0;

                if(j > 0 && a[i][j][k] <= a[i][j-1][k])
                    flag = 0;

                if(j < r-1 && a[i][j][k] <= a[i][j+1][k])
                    flag = 0;

                if(k > 0 && a[i][j][k] <= a[i][j][k-1])
                    flag = 0;

                if(k < c-1 && a[i][j][k] <= a[i][j][k+1])
                    flag = 0;

                if(flag)
                {
                    printf("(%d,%d,%d)\n",
                           i+1, j+1, k+1);
                }
            }
        }
    }

    return 0;
}

//sample input
2 2 2
1 2
3 4
5 6
7 9
  //output
  Total Vibration Intensity: 37
Highest Vibration: 9
Highest Position: (2,2,2)
Lowest Vibration: 1
Lowest Position: (1,1,1)
Layer-wise Intensity:
Layer 1: 10
Layer 2: 27
Layer With Maximum Intensity: 2
Prime Counts:
Layer 1: 2
Layer 2: 2
Main Space Diagonal Sum: 10
Local Maximum Sensor Count: 1
Local Maximum Position:
(2,2,2)
