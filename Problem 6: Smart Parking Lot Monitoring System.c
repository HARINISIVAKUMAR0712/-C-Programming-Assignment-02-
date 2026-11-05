//code
#include <stdio.h>

int main()
{
    int n, m, a[50][50];
    int i, j;
    int occupied = 0, empty = 0;
    int maxRow = 0, maxCol = 0;
    int maxOcc = -1, maxEmpty = -1;
    int fullRows = 0, longest = 0;

    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);

            if(a[i][j] == 1)
                occupied++;
            else
                empty++;
        }
    }

    for(i = 0; i < n; i++)
    {
        int count = 0;

        for(j = 0; j < m; j++)
        {
            if(a[i][j] == 1)
                count++;
        }

        if(count > maxOcc)
        {
            maxOcc = count;
            maxRow = i;
        }

        if(count == m)
            fullRows++;
    }

    for(j = 0; j < m; j++)
    {
        int count = 0;

        for(i = 0; i < n; i++)
        {
            if(a[i][j] == 0)
                count++;
        }

        if(count > maxEmpty)
        {
            maxEmpty = count;
            maxCol = j;
        }
    }

    for(i = 0; i < n; i++)
    {
        int count = 0;

        for(j = 0; j < m; j++)
        {
            if(a[i][j] == 0)
            {
                count++;

                if(count > longest)
                    longest = count;
            }
            else
                count = 0;
        }
    }

    printf("Occupied Spaces: %d\n", occupied);
    printf("Empty Spaces: %d\n", empty);
    printf("Maximum Occupied Row: %d\n", maxRow + 1);
    printf("Maximum Empty Column: %d\n", maxCol + 1);

    printf("Completely Occupied Rows: ");

    for(i = 0; i < n; i++)
    {
        int count = 0;

        for(j = 0; j < m; j++)
        {
            if(a[i][j] == 1)
                count++;
        }

        if(count == m)
            printf("%d ", i + 1);
    }

    printf("\nLongest Continuous Empty Sequence: %d", longest);

    printf("\nOccupancy Percentage: %.2f",
           (float)occupied * 100 / (n * m));

    return 0;
}
//sample input
4 5
1 1 0 1 0
1 1 1 1 1
0 0 0 1 0
1 0 0 0 1
  //output
  Occupied Spaces: 11
Empty Spaces: 9
Maximum Occupied Row: 2
Maximum Empty Column: 3
Completely Occupied Rows:
Longest Continuous Empty Sequence: 3
Occupancy Percentage: 55.00
