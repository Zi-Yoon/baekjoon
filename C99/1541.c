/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1541.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:12:42 by byan              #+#    #+#             */
/*   Updated: 2021/10/31 23:11:02 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int index = 0;
int i_minus = 0;
int i_plus = 0;
int end = 0;
int num_num = 1;
char str[1000000];

void find_end()
{
	while (str[end])
	{
		if (str[end] == '-' || str[end] == '+')
			num_num++;
		end++;
	}
}

void find_minus() // - 를 찾는다
{
	while (str[i_minus] != '-' && str[i_minus])
		i_minus++;
	i_minus++;
}

void find_plus() // - 다음에 나오는 + 를 찾는다
{
	while (str[i_plus] != '-' && str[i_plus])
		i_plus++;
	while (str[i_plus] != '+' && str[i_plus])
		i_plus++;
}

int find_num() // 숫자를 찾는다
{
	int num = 0;
	while ((str[index] >= '0' && str[index] <= '9') && str[i_minus])
	{
		num = num * 10 + (str[index] - 48);
		index++;
	}
	return (num);
}

int main()
{
	int plus_temp = 0;
	int minus_temp = 0;
	int ans = 0;
	int i = 0;
	scanf("%s", str);

	find_end();
	while (i < num_num)
	{
		plus_temp = 0;
		minus_temp = 0;
		find_minus();
		while (index < i_minus && i < num_num)
		{
			plus_temp += find_num();
			i++;
		}
		find_minus();
		while (index < i_minus && i < num_num)
		{
			minus_temp += find_num();
			i++;
		}
		ans += plus_temp - minus_temp;
	}
	printf("%d", ans);
	return 0;
}