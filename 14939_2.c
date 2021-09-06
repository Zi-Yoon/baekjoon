#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Bulb[12][12]; // 원본
int temp[12][12]; // test case
char real[10]; // 2진수 표현용
long binary= 0;
char temp_c[1];
int min = 1000, ans = 0, cnt = 0;

void reset();
int mk_bin(int a);
void First();
void start_first(int x);
void start_second(int x, int y);
void Push(int x, int y);
void check();

int main() 
{
    memset(Bulb, 0, sizeof(Bulb));
    memset(temp, 0, sizeof(temp));
    memset(real, 0, sizeof(real));
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            scanf("%c", temp_c);
            if(temp_c[0] == '\n')
            {
                j--;
                continue;
            }
            if(temp_c[0] == '#')
            {
                Bulb[i][j] = -1;
            }
            if(temp_c[0] == 'O')
            {
                Bulb[i][j] = 1;
            }
        }
    }
    First();
    if(min == 1000)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", min);
    }
    return 0;
}

// 리셋
void reset()
{
    memmove(temp, Bulb, sizeof(Bulb));
    memset(real, 0, sizeof(real));
    cnt = 0;
    ans = 0;
    binary = 0;
}

// 2진수 만들기
int mk_bin(int a)
{
    for (int i = 0; i < 10; i++)
    {
        int tmi = a % 2;
        if (tmi == 1)
        {
            binary += pow(10, i);
        }
        a = a / 2;
    }
    return binary;
}

// 시작
void First()
{
    for (int j = 0; j < 1024; j++)
    {
        reset();
        binary = mk_bin(j);
        sprintf(real, "%d", binary);
        for (int i = 1; i <= 10; i++)
        {
            if (real[10-i] == '1')
            {
                start_first(i);
            }
        }
        start_second(1, 2);
        check();
    }
}

// 첫줄만 세팅해주는 함수
void start_first(int x)
{
    int y = 1;
    temp[x][y] = Bulb[x][y] * -1;
    temp[x+1][y] = Bulb[x+1][y] * -1;
    temp[x][y+1] = Bulb[x][y+1] * -1;
    temp[x-1][y] = Bulb[x-1][y] * -1;
}

// 둘째줄부터 마지막줄까지 처리
void start_second(int x, int y)
{
    if(temp[x][y-1] == 1)
    {
        Push(x, y);
        ans++;
    }
    if(x < 10)
    {
        start_second(x + 1, y);
    }
    else if (x == 10 && y != 10)
    {
        start_second(1, y + 1);
    }
    return;
}


// + 모양으로 전원 on-off
void Push(int x, int y)
{
    temp[x][y] *= -1;
    temp[x+1][y] *= -1;
    temp[x][y+1] *= -1;
    temp[x-1][y] *= -1;
    temp[x][y-1] *= -1;
}

void check()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cnt += temp[i][j];
        }
    }
    if(cnt == -100)
    {
        if(ans < min)
        {
            min = ans;
        }
    }
}