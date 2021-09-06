#include <stdio.h>
#include <stdlib.h>

int main(){
    int natural;
    scanf("%d",&natural);
    int cnt = 1; // 자릿수
    int temp_natrual = natural;
	int real_natural = natural;
	
	if (natural < 10) 
	{
		printf("%d",0);
		return 0;
	}
	
    // 자릿수 구하기
    for (int j = 0 ; j < 7; j++){
        temp_natrual = temp_natrual / 10;
        if (temp_natrual > 0){
            cnt++;
        }
    }
	
	int natural_sep[cnt];
    int seperate[cnt];
	int temp1_natural = natural;
	
	for (int j = 0 ; j < cnt; j++){
        natural_sep[j] = temp1_natural % 10;
		temp1_natural = temp1_natural / 10;
    }
    
    int max_num = cnt * 9;
    natural = natural - max_num;
	int max = natural;
	
	for (int h = 0; h < max; h++)
	{
		int temp_natural = natural;
		int sum = 0;

		for (int i = 0; i < cnt; i++)
		{
			seperate[i] = temp_natural % 10;
			temp_natural = temp_natural / 10;
			sum += seperate[i];
		}
		if((sum+natural) == real_natural)
		{
			printf("%d",natural);
			return 0;
		} 
		else
		{
			natural++;
			max_num--;
		}
	}
	printf("%d",0);
	return 0;
}
