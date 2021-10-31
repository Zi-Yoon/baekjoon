/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5525.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:56:17 by byan              #+#    #+#             */
/*   Updated: 2021/10/31 12:33:21 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/* IOIOI */

// N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.

// P1 IOI
// P2 IOIOI
// P3 IOIOIOI
// PN IOIOI...OI (O가 N개)
// I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, 
// S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
int N_num, M_len, N_len;

void cnt_P(int i, char *str_P, char *str_S)
{
	int j = i;
	int k = 0;
	if(str_S[j] == '\0')
		return ;
	while (str_S[j] == 'O')
	{
		i++;
		j++;
	}
	while (str_P[k] == str_S[j] && str_P[k] != '\0' && k < N_len)
	{
		k++;
		j++;
	}
	if (k == N_len)
	{
		cnt++;
		i++;
	}
	i++;
	cnt_P(i, str_P, str_S);
}

int main()
{
	char	*str_S; // S 문자열
	char	*str_P; // Pn 문자열
	int		i = -1;
	scanf("%d", &N_num);
	N_len = N_num * 2 + 1 ;
	str_P = (char *)calloc(N_len + 1, sizeof(char));
	while(++i < N_len)
	{
		if(i % 2 == 0)
			str_P[i] = 'I';
		else
			str_P[i] = 'O';
	}
	scanf("%d", &M_len);
	str_S = (char *)calloc(M_len + 1, sizeof(char));
	str_S[M_len] = '\0';
	scanf("%s", str_S);
	cnt_P(0, str_P, str_S);
	printf("%d", cnt);
}