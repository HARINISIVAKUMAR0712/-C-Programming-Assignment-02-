//code
#include <stdio.h>

int main()
{
    int n, a[100], b[100];
    int i, j, k = 0, count = 0;
    int max, second = -1;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];

    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] < max && a[i] > second)
            second = a[i];
    }

    printf("Second Largest Distinct Quantity: ");

    if(second == -1)
        printf("Not Available\n");
    else
        printf("%d\n", second);

    printf("Zero Positions: ");

    for(i = 0; i < n; i++)
    {
        if(a[i] == 0)
            printf("%d ", i + 1);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                count++;
                break;
            }
        }

        if(j == i)
            b[k++] = a[i];
    }

    printf("\nDuplicate Occurrences: %d", count);

    printf("\nArray After Removing Duplicates: ");

    for(i = 0; i < k; i++)
        printf("%d ", b[i]);

    printf("\nArray After Moving Zeros: ");

    for(i = 0; i < n; i++)
    {
        if(a[i] != 0)
            printf("%d ", a[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] == 0)
            printf("0 ");
    }

    return 0;
}
//sample input
8
20 0 35 20 15 0 35 50
  //output
Second Largest Distinct Quantity: 35
Zero Positions: 2 6
Duplicate Occurrences: 2
Array After Removing Duplicates: 20 0 35 15 50
Array After Moving Zeros: 20 35 20 15 35 50 0 0
