#include <stdio.h>
#include <stdlib.h>

int n, m, time;
int arr[8];
int sum = 1, run = 0, temp = 0;
int time_temp, n_temp , m_temp, start = 0;
int temp_num[8];

void print_all(int x)
{
    m_temp = m;
    // 1개 일때 예외처리
    if (m_temp == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        return;
    }

    for (int i = 0; i < temp_num[start]; i++)
    {
        temp++;
        run++;
        if(i==temp) // 좌표가 같으면 넘김
        {
            continue;
        } 
        printf("%d ", arr[i]);
        if (run >= m_temp)
        {
            printf("\n");
            temp = 0;
            run = 0;
        }
        start++;
    }
    start = 0;
    print_all(temp);   // 다시 호출 -> 옆에 print
}

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if(num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    // nPm = sum
    for (int i = n; i > n-m; i--)
    {
        sum *= i;
    }
    time = sum / n;
    time_temp = time;
    n_temp = n;
    m_temp = m;
    for (int i = 0; i < m; i++)
    {
        m_temp--;
        temp_num[i] = time_temp;
        if(m_temp>0)
        {
            time_temp = time_temp / m_temp;
        }
    }
    print_all(0);
}
