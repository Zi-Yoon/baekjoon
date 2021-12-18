/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:16:33 by byan              #+#    #+#             */
/*   Updated: 2021/10/23 18:43:18 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g_board[15];
int g_count = 0;

int ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int ft_tracking_queens(int index)
{
	int i;

	i = -1;
	while (++i < index)
		if (g_board[index] == g_board[i] ||
		index - i == ft_abs(g_board[index] - g_board[i]))
			return (0);
	return (1);
}

void ft_re_queens(int index, int size)
{
	if (index == size)
	{
		g_count++;
	}
	for (int i = 0; i < size; i++)
	{
		g_board[index] = i;
		if (ft_tracking_queens(index))
			ft_re_queens(index + 1, size);
	}
}

int main()
{
	int size;
	scanf("%d", &size);
	ft_re_queens(0, size);
	printf("%d", g_count);
	return 0;
}