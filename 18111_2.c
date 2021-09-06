#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n, m, b;
	int time = 128000000;
	int count = 0;
	int min_level = 0;

	// 입력
	scanf("%d %d %d", &n, &m, &b);
	int ground[n][m];
	for (int i=0; i<n; i++) {
		for(int j=0; j<m; j++){
			scanf("%d", &ground[i][j]);
		}
	}

	// 필요한 블럭 갯수 세기
	for (int level = 0; level <= 256; level++){
		int level_temp = 0, del_temp = 0, add_temp = 0, block = 0;
		for (int i=0; i<n; i++) {
			for(int j=0; j<m; j++){
				level_temp = ground[i][j];
				if(level_temp - level > 0){del_temp += level_temp - level;}
				if(level - level_temp > 0){add_temp += level - level_temp;}
			}
		}
		int del = del_temp * 2;
		int add = add_temp;
		block = b + del_temp;
		if(block >= add){
			if(time >= del+add){
				time = del + add;
				min_level = level;
			}
		}
	}
	printf("%d %d", time, min_level);
	return 0;
}