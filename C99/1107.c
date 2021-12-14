#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int plusonly(int a, int b)
{
    return b - a;
}

int minusonly(int a, int b)
{
    return a - b;
}

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return (num1-num2);
}

int main() {
    int N;
    int cnt = 0;
    int start = 100;
    scanf("%d", &N); // 목표채널

    int error; // 고장난 버튼 갯수
    scanf("%d", &error);

    int M[error]; // 고장난 버튼
    for (int i = 0; i < error; i++)
    {
        scanf("%d", &M[i]);
    }
    qsort(M, sizeof(M) / sizeof(int), sizeof(int), compare);

    // 예외처리
    if (error == 10 || (error == 9 && M[0] ==1 )){
        if(N>100){
            plusonly(100, N);
        }
        else if(N<100){
            minusonly(100, N);
        }
        else{
            printf("%d", 0);
            return 0;
        }
    }

    int button[10 - error];
    int temp1[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < error; i++)
    {
        switch (M[i])
        {
            case 0: 
            {
                temp1[0] = -1;
                break;
            }
            case 1: 
            {
                temp1[1] = -1;
                break;
            }
            
            case 2: 
            {
                temp1[2] = -1;
                break;
            }
            case 3: 
            {
                temp1[3] = -1;
                break;
            }
            case 4: 
            {
                temp1[4] = -1;
                break;
            }
            case 5: 
            {
                temp1[5] = -1;
                break;
            }
            case 6: 
            {
                temp1[6] = -1;
                break;
            }
            case 7: 
            {
                temp1[7] = -1;
                break;
            }
            case 8: 
            {
                temp1[8] = -1;
                break;
            }
            case 9: 
            {
                temp1[9] = -1;
                break;
            }
        }
    }
    int j = 0;
    // button[i] 입력가능한 버튼 
    for (int i = 0; i < 10-error; i++)
    {
        if(temp1[j]==-1)
        {
            j++;
            continue;
        }
        else
        {
            button[i] = temp1[j];
            j++;
        }
    }

    int temp2 = N;
    int temp3 = N;
    int N_num = 0; // 목표 숫자 자릿수
    for (int i = 0; i < 6; i++)
    {
        temp2 = temp2 / 10;
        N_num++;
        if (temp2 == 0){
            break;
        }
    }

    int N_arr[N_num];
    for (int i = N_num-1; i >= 0; i--)
    {
        N_arr[i] = temp3 % 10;
        temp3 = temp3 / 10;
    }

    int temp4 = 0;
    int temp5 = 0;
    int temp6 = 0;
    int temp_N_num = N_num;
    for (int j = 0; j < N_num; j++)
    {
        for (int i = 10 - error - 1; i >= 0; i--)
        {
            if (N_arr[j] == button[i])
            {
                temp4 = button[i] * pow(10, temp_N_num-1);
                cnt++;
            }
            else
            {
                if (N_arr[j] > button[i])
                {
                    temp5 = button[i] * pow(10, temp_N_num-1); // 클때
                    cnt++;
                }
                else
                {
                    temp6 = button[i] * pow(10, temp_N_num-1); // 작을때
                    cnt++;
                    break;
                }
            }
        }
        temp_N_num--;
    }
    int cnt1, cnt2, cnt3;
    if (temp4 > N)
    {
        cnt1 = minusonly(temp4, N) + cnt;
    }
    else 
    {
        cnt1 = plusonly(temp4, N) + cnt;
    }

    if (temp5 > N)
    {
        cnt2 = minusonly(temp4, N) + cnt;
    }
    else 
    {
        cnt2 = plusonly(temp4, N) + cnt;
    }

    if (temp6 > N)
    {
        cnt3 = minusonly(temp4, N) + cnt;
    }
    else 
    {
        cnt3 = plusonly(temp4, N) + cnt;
    }


    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (cnt1 >= cnt2 && cnt1 >= cnt3){
            ans = cnt1;
        }
        else if (cnt2 >= cnt3 && cnt1 >= cnt1){
            ans = cnt2;
        }
        else{
            ans = cnt3;
        }
    }
    printf("%d", ans);
    return 0;
}