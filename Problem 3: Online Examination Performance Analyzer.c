//code
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[100], i, j;
    int pass = 0, max, second = -1;
    int longest = 1, current = 1;
    int diff, minDiff;
    int p1, p2;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];

    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];

        if(a[i] >= 50)
            pass++;
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] < max && a[i] > second)
            second = a[i];
    }

    printf("Highest Marks: %d\n", max);

    if(second == -1)
        printf("Second Highest Marks: Not Available\n");
    else
        printf("Second Highest Marks: %d\n", second);

    printf("Frequencies:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[i] == a[j])
                break;
        }

        if(j == i)
        {
            int count = 0;

            for(j = 0; j < n; j++)
            {
                if(a[i] == a[j])
                    count++;
            }

            printf("%d - %d\n", a[i], count);
        }
    }

    printf("Passed Students: %d\n", pass);

    for(i = 1; i < n; i++)
    {
        if(a[i] > a[i - 1])
            current++;
        else
            current = 1;

        if(current > longest)
            longest = current;
    }

    printf("Longest Increasing Sequence Length: %d\n", longest);

    minDiff = abs(a[0] - a[1]);
    p1 = a[0];
    p2 = a[1];

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            diff = abs(a[i] - a[j]);

            if(diff < minDiff)
            {
                minDiff = diff;
                p1 = a[i];
                p2 = a[j];
            }
        }
    }

    printf("Minimum Difference Pair: %d %d\n", p1, p2);

    printf("Reversed Array: ");

    for(i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    return 0;
}
//sample input
8
45 60 75 80 65 65 90 55
  //output
  Highest Marks: 90
Second Highest Marks: 80
Frequencies:
45 - 1
60 - 1
75 - 1
80 - 1
65 - 2
90 - 1
55 - 1
Passed Students: 7
Longest Increasing Sequence Length: 4
Minimum Difference Pair: 65 65
Reversed Array: 55 90 65 65 80 75 60 45
