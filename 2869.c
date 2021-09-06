#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);

    int temp = 0;
    int day = 1;
    int one = A - B;
    int VA = V - A;
    int need = VA % one;
    int ans = VA / one;

    if (A >= V){
        day = 1;
    }
    else if ((need == 0)){
        day = ans + 1;
    }
    else
    {
        day = ans + 2;
    }
    printf("%d", day);
    return 0;
}