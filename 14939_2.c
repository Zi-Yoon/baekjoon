/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14939_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:07:54 by byan              #+#    #+#             */
/*   Updated: 2021/11/10 00:07:54 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int bulb[12][12]; // 원본
char temp_c;
int ans = 0;
int min = 1000, sum = 0;

void push_wise(int bulb[][12])
{
	int i = 1;
	int j = 1;
	while (i <= 9)
	{
		j = 1;
		while (j <= 10)
		{
			if (bulb[i][j] == 1)
			{
				bulb[i][j] *= -1; // 위
				bulb[i + 2][j] *= -1; // 아래
				bulb[i + 1][j - 1] *= -1; // 왼
				bulb[i + 1][j + 1] *= -1; // 오
				bulb[i + 1][j] *= -1; // 중간
				ans++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (++i <= 10)
	{
		j = 0;
		while (++j <= 10)
			sum += bulb[i][j];
	}
	
}

void push(int bulb[][12])
{
	int temp[12][12];
	ans = 0;

	memcpy(temp, bulb, 12 * 12 * sizeof(int));
	int i = 0;
	int j = 1;
	while (i <= 9)
	{
		j = 1;
		while (j <= 10)
		{
			ans++;
			temp[i][j] *= -1;		  // 위
			temp[i + 1][j - 1] *= -1; // 왼
			temp[i + 1][j + 1] *= -1; // 오
			temp[i + 1][j] *= -1;	  // 중간
			if (i != 10)
				temp[i + 2][j] *= -1;	  // 아래
			j++;
		}
		i++;
	}
	i = 0;
	while (++i <= 10)
	{
		j = 0;
		while (++j <= 10)
			sum += temp[i][j];
	}
	
}

int main() 
{
	int	i = 1;
	int	j = 1;
	int a = 0;
	int bulb[12][12];
	int temp[12][12];

	memset(bulb, 0, 12 * 12 * sizeof(int));
	while (i <= 10)
	{
		j = 1;
		while (j <= 10)
		{
			scanf("%c", &temp_c);
			if (temp_c == '\n')
				j--;
			else if (temp_c == '#')
				bulb[i][j] = -1;
			else if (temp_c == 'O')
				bulb[i][j] = 1;
			j++;
		}
		i++;
	}
	memcpy(temp, bulb, 12 * 12 * sizeof(int));
	push_wise(temp);
	if (sum == -100)
	{
		a++;
		min = ans;
	}
	memcpy(temp, bulb, 12 * 12 * sizeof(int));
	sum = 0;
	push(temp);
	if (min < ans)
		ans = min;
	if(sum != -100 && a == 0)
        printf("%d", -1);
    else
        printf("%d", ans);
    return 0;
}

