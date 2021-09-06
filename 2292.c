#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N == 1){
        printf("%d", 1);
        return 0;
    }

    int bee = (N/6) + 2;
    
    for (int i = 2; i <= bee; i++){
        int sum = 1;
        for (int j = 1; j < i; j++){
            sum += j * 6;
        }
        if(sum >= N)
        {
            printf("%d", i);
            return 0;
        }
    }
}