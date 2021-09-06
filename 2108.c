#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return (num1-num2);
}

int main() {
    int N;
    int sum = 0;
    int middle, range;
    scanf("%d", &N);
    int number[N];
    int most[8001];
    int most2[8001];

    // 최빈값 reset
    for (int i = 0; i < 8001; i++)
    {
        most[i] = 0;
        most2[i] = 0;
    }

    // sum 구해놓기
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &number[i]);
        sum += number[i];
        most[4000+number[i]]++; // 0 => -4000 ~ 4000 => 8000
        most2[4000+number[i]]++;
    }
    
    // 산술평균
    double average = (sum /(double)N);
    // 중앙값
    qsort(number, N, sizeof(int), compare);
    middle = number[((N+1)/2) - 1];

    int temp1 = 0; // 갯수
    int temp2 = 0;
    int cnt = 0;
    int max = 0;
    int ans_most = 0; // 최빈값
    int j = 1;
    int k = 2;
    for (int i = 0; i <= 8001; i++)
    {
        if (most[i]==0)
        {
            continue;
        }
        else
        {
            if (temp1 <= most[i])
            {   
                temp1 = most[i];
                temp2 = most[j];
                if(temp1 == temp2)
                {
                    cnt++;
                }
                temp2 = temp1;

                j = i;

            }
            
        }
    }
    max = 1;
    for (int i = 0; i < 8001; i++)
    {
        if(most2[i] >= max){
            max = most2[i];
            ans_most = i - 4000;
        }
    }
    // 범위
    range = number[N-1] - number[0];

    printf("%.f\n", round(average));
    printf("%d\n", middle);
    printf("%d\n", ans_most);
    printf("%d\n", range);

    return 0;
}