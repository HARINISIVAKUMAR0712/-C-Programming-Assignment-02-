//code
#include <stdio.h>

int main()
{
    int l, r, c;
    int a[20][20][20];
    int i, j, k;

    int total = 0;
    int occupied = 0, empty = 0;
    int floorTotal[20] = {0};
    int maxFloor = 0;

    scanf("%d %d %d", &l, &r, &c);

    for(i = 0; i < l; i++)
    {
        for(j = 0; j < r; j++)
        {
            for(k = 0; k < c; k++)
            {
                scanf("%d", &a[i][j][k]);

                total += a[i][j][k];
                floorTotal[i] += a[i][j][k];

                if(a[i][j][k] == 0)
                    empty++;
                else
                    occupied++;
            }
        }
    }

    printf("Total Patients: %d\n", total);
    printf("Occupied Beds: %d\n", occupied);
    printf("Unoccupied Beds: %d\n", empty);

    printf("Floor-wise Patient Counts:\n");

    for(i = 0; i < l; i++)
    {
        printf("Floor %d: %d\n", i + 1, floorTotal[i]);

        if(floorTotal[i] > floorTotal[maxFloor])
            maxFloor = i;
    }

    printf("Floor With Maximum Patients: %d\n", maxFloor + 1);

    printf("Floor-wise Maximum and Minimum:\n");

    for(i = 0; i < l; i++)
    {
        int max = a[i][0][0];
        int min = a[i][0][0];

        for(j = 0; j < r; j++)
        {
            for(k = 0; k < c; k++)
            {
                if(a[i][j][k] > max)
                    max = a[i][j][k];

                if(a[i][j][k] < min)
                    min = a[i][j][k];
            }
        }

        printf("Floor %d: Maximum = %d, Minimum = %d\n",
               i + 1, max, min);
    }

    printf("Even and Odd Counts:\n");

    for(i = 0; i < l; i++)
    {
        int even = 0, odd = 0;

        for(j = 0; j < r; j++)
        {
            for(k = 0; k < c; k++)
            {
                if(a[i][j][k] % 2 == 0)
                    even++;
                else
                    odd++;
            }
        }

        printf("Floor %d: Even = %d, Odd = %d\n",
               i + 1, even, odd);
    }

    printf("Array After Reversing Floors:\n");

    for(i = l - 1; i >= 0; i--)
    {
        printf("Floor %d: ", l - i);

        for(j = 0; j < r; j++)
        {
            for(k = 0; k < c; k++)
                printf("%d ", a[i][j][k]);
        }

        printf("\n");
    }

    return 0;
}
//sample input
3 2 3
10 0 5
8 6 0
12 4 2
0 7 9
3 5 0
6 8 1
  //output
  Total Patients: 86
Occupied Beds: 14
Unoccupied Beds: 4
Floor-wise Patient Counts:
Floor 1: 29
Floor 2: 34
Floor 3: 23
Floor With Maximum Patients: 2
Floor-wise Maximum and Minimum:
Floor 1: Maximum = 10, Minimum = 0
Floor 2: Maximum = 12, Minimum = 0
Floor 3: Maximum = 8, Minimum = 0
Even and Odd Counts:
Floor 1: Even = 4, Odd = 2
Floor 2: Even = 3, Odd = 3
Floor 3: Even = 3, Odd = 2
Array After Reversing Floors:
Floor 1: 6 8 1 3 5 0
Floor 2: 12 4 2 0 7 9
Floor 3: 10 0 5 8 6 0
