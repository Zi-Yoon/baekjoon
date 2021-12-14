#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int temp;
    int temp5 = N % 5;
    int temp3 = N % 3;
    int temp_num = N;
    int cnt = 0;

    // 5의 배수일때
    if(temp5 == 0)
    {
        printf("%d", N / 5);
        return 0;
    }

    for (int i = 0; i < temp_num; i++)
    {
        for (int j = 0; j < temp_num; j++)
        {
            temp = i * 3 + j * 5;
            if(N == temp)
            {
                printf("%d", i + j);
                return 0;
            }
        }
    }
    printf("%d", -1);
    return 0;
}