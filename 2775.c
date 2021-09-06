#include <stdio.h>
#include <stdlib.h>

int main() {

    int room[15][15];
    for (int i = 0; i < 15; i++)
    {
        room[i][0] = 1;
        room[0][i] = i+1;
    }
    for (int i = 1; i < 15; i++)
    {
        for (int j = 1; j < 15; j++)
        {
            room[i][j] = room[i - 1][j] + room[i][j-1];
        }
    }

    int T;
    scanf("%d", &T);
    int k[T]; // 
    int n[T]; //
    for (int i = 0; i < T; i++){
        scanf("%d", &k[i]);
        scanf("%d", &n[i]);
        n[i]--;
    }
    
    
    
    for (int i = 0; i < T; i++){
        printf("%d\n", room[k[i]][n[i]]);
    }
    return 0;
} 