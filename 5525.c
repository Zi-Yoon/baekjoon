/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5525.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:56:17 by byan              #+#    #+#             */
/*   Updated: 2021/10/31 02:18:21 by byan             ###   ########seoul.kr  */
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

int main()
{
	int		N_num, M_len;
	char	*str_S;
	int		*str_P;
	scanf("%d", &N_num);
	str_P = (char *)calloc(N_num * 2 + 2, sizeof(int));
	str_P[N_num * 2 + 1] = '\0';
	scanf("%d", &M_len);
	str_S = (char *)calloc(M_len + 1, sizeof(char));
	str_S[M_len] = '\0';
	scanf("%s", &str_S);

}