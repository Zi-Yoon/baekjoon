#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if(num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int main()
{
    int N, M, a;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), compare);

    scanf("%d", &M);
    int ans[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &a);
        if(bsearch(&a, A, N, sizeof(int), compare)!=NULL)
        {
            ans[i] = 1;
        }
        else
        {
            ans[i] = 0;
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}