#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return (num1-num2);
}

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    qsort(A, sizeof(A) / sizeof(int), sizeof(int), compare);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}