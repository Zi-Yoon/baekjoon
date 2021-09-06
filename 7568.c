#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
    int kg;
    int cm;
    int rank;
    int name;
} Per;

int compare(const void *a, const void *b)
{
    Per *A = (Per*)a;
    Per *B = (Per*)b;
    if(A->kg > B->kg)
    {
        return -1;
    }
    else if (A->kg < B->kg)
    {
        return 1;
    }
    else
    {
        if(A->cm >= B->cm)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int compare_name(const void *a, const void *b)
{
    Per *A = (Per*)a;
    Per *B = (Per*)b;
    if(A->name > B->name)
    {
        return 1;
    }
    else 
    {
        return -1;
    }
    
}

int main(){
    int N;
    scanf("%d", &N);
    Per P[N];
    for (int i = 0; i < N; i++){
        scanf("%d %d", &P[i].kg, &P[i].cm);
        P[i].name = i;
        P[i].rank = 1;
    }
    qsort(P, N, sizeof(Per), compare); // kg 순으로 정렬

    for (int i = 0; i < N-1; i++) // find rank 
    {
        for (int j = i+1; j < N; j++)
        {   
            if (P[i].cm <= P[j].cm)
            {
                P[j].rank = P[i].rank;
            }
            else
            {
                P[j].rank++;
            }
        }
    }
       
    qsort(P, N, sizeof(Per), compare_name); // name 순으로 정렬

    for (int i = 0; i < N; i++){
        printf("%d ", P[i].rank);
    }
    return 0;
}