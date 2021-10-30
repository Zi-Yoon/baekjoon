#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    if(N==1) // 예외처리 
    {
        printf("%d", 1);
        return 0;
    }
    int end = N;
    int arr[1000001]; // 여기서는 오류 나지만 실제로는 돌아감
    for (int i = 1; i <= N; i++) // 값 채워넣기
    {
        arr[i] = i;
    }
    int start = 1;
    int cnt = 0;
    while (start != end)
    {
        arr[start] = 0;
        start++;
        if(start == end)
        {
            printf("%d", arr[start]);
            return 0;
        }
        end++;
        arr[end] = arr[start];
        arr[start] = 0;
        start++;
    }
}