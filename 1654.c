#include <stdio.h>

int main() {
	int have, need; // 입력
	int max = 1; // 나누는수
	scanf("%d %d", &have, &need);
	int lan[10000];
	int temp1;
	int temp2[10000];

	for (int i = 0; i < have; i++) {
		scanf("%d", &lan[i]);
	}

	while (1) {
		int num = 0;
		int temp3 = 0;

		for (int i = 0; i < have; i++) {
			temp2[i] = lan[i] / max;
			num += temp2[i]; // 나눌수 있는 횟수 저장
		}
		if (num == need) {
			for (int i = 0; i < have; i++) {
				if (temp2[i] != lan[i] / (max + 1)) {
					printf("%d", max);
					return 0;
				}
			}
		}
		if (num < need) {
			max--;
			printf("%d", max);
			return 0;
		}
		max++;	
	}
}
