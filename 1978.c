#include <stdio.h>
#include <math.h>

int main() {
	int a;
	scanf("%d", &a);
    int b[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &b[i]);
    }
    int cnt = 0;
    for (int j = 0; j < a; j++)
    {
        int temp1 = sqrt(b[j]);
        if (temp1 <= 1 && b[j] != 1)
        {
            cnt++;
        }
        else
        {
            for (int k = temp1; k > 1; k--)
            {
                if (b[j] % k == 0)
                {
                    break;
                }
                else
                {
                    if (k == 2)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}