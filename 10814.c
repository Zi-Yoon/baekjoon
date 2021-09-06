#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int age;
    char name[101];
    int num;
}person;

int compare(const void *a, const void *b)
{
    person *p1 = ((person*)a);
    person *p2 = ((person*)b);

    if (p1->age == p2->age){
        if(p1->num > p2->num){
            return 1;
        }
        else{
            return -1;
        }
    }
    else if(p1->age > p2->age)
    {
        return 1;
    }
    else{
        return -1;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    person A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &A[i].age, &A[i].name);
        A[i].num = i;
    }

    qsort(A, N, sizeof(A[0]), compare);

    for (int i = 0; i < N; i++)
    {
        printf("%d %s\n", A[i].age, A[i].name);
    }
    return 0;
}