//code
#include <stdio.h>

int main()
{
    int n, m, a[50][50];
    int i, j, total[50];
    int topper = 0, lowest = 0;
    int passed = 0, flag;

    float avg[50];

    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }

    printf("Student Totals: ");

    for(i = 0; i < n; i++)
    {
        total[i] = 0;
        flag = 1;

        for(j = 0; j < m; j++)
        {
            total[i] += a[i][j];

            if(a[i][j] < 50)
                flag = 0;
        }

        if(flag)
            passed++;

        printf("%d ", total[i]);

        if(total[i] > total[topper])
            topper = i;
    }

    printf("\nSubject Averages: ");

    for(j = 0; j < m; j++)
    {
        int sum = 0;

        for(i = 0; i < n; i++)
            sum += a[i][j];

        avg[j] = (float)sum / n;

        printf("%.2f ", avg[j]);

        if(avg[j] < avg[lowest])
            lowest = j;
    }

    printf("\nTopper Position: %d", topper + 1);
    printf("\nLowest Average Subject: %d", lowest + 1);
    printf("\nStudents Passed All Subjects: %d", passed);

    printf("\nTranspose:\n");

    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
            printf("%d ", a[i][j]);

        printf("\n");
    }

    return 0;
}
//sample inpue
3 3
80 75 90
60 85 70
95 90 85
  //output
  Student Totals: 245 215 270
Subject Averages: 78.33 83.33 81.67
Topper Position: 3
Lowest Average Subject: 1
Students Passed All Subjects: 3
Transpose:
80 60 95
75 85 90
90 70 85
