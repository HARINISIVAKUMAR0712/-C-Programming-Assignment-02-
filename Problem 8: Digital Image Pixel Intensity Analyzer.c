//code
#include <stdio.h>

int main()
{
    int n, m, a[50][50];
    int i, j;
    int min, max;
    int minR = 0, minC = 0;
    int maxR = 0, maxC = 0;
    int dark = 0, localMax = 0;
    float total = 0;

    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);

            total += a[i][j];

            if(i == 0 && j == 0)
            {
                min = max = a[i][j];
            }

            if(a[i][j] < min)
            {
                min = a[i][j];
                minR = i;
                minC = j;
            }

            if(a[i][j] > max)
            {
                max = a[i][j];
                maxR = i;
                maxC = j;
            }

            if(a[i][j] < 50)
                dark++;
        }
    }

    printf("Average Intensity: %.2f\n", total / (n * m));

    printf("Darkest Pixel: %d at (%d,%d)\n",
           min, minR + 1, minC + 1);

    printf("Brightest Pixel: %d at (%d,%d)\n",
           max, maxR + 1, maxC + 1);

    printf("Dark Pixel Count: %d\n", dark);

    printf("Negative Image:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", 255 - a[i][j]);

        printf("\n");
    }

    printf("Rotated Image:\n");

    for(j = 0; j < m; j++)
    {
        for(i = n - 1; i >= 0; i--)
            printf("%d ", a[i][j]);

        printf("\n");
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            int flag = 1;

            if(i > 0 && a[i][j] <= a[i - 1][j])
                flag = 0;

            if(i < n - 1 && a[i][j] <= a[i + 1][j])
                flag = 0;

            if(j > 0 && a[i][j] <= a[i][j - 1])
                flag = 0;

            if(j < m - 1 && a[i][j] <= a[i][j + 1])
                flag = 0;

            if(flag)
                localMax++;
        }
    }

    printf("Local Maximum Count: %d", localMax);

    return 0;
}
//sample input
3 3
10 20 30
40 200 60
70 80 90
  // output
  Average Intensity: 66.67
Darkest Pixel: 10 at (1,1)
Brightest Pixel: 200 at (2,2)
Dark Pixel Count: 2
Negative Image:
245 235 225
215 55 195
185 175 165
Rotated Image:
70 40 10
80 200 20
90 60 30
Local Maximum Count: 1
