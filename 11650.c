#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
    int x;
    int y;
} mat;

int compare(const void *a, const void *b)
{
    mat *A = (mat*)a;
    mat *B = (mat*)b;
    if (A->y > B->y){
        return 1;
    }
    else if (A->y < B->y){
        return -1;
    }
    else{
        if(A->x > B->x){
            return 1;
        }
        else if (A->x < B->x){
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    mat M[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &M[i].x, &M[i].y);
    }

    qsort(M, N, sizeof(mat), compare);

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", M[i].x, M[i].y);
    }
    return 0;
}