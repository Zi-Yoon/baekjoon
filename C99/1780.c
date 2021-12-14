/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1780.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:55 by byan              #+#    #+#             */
/*   Updated: 2021/10/31 13:07:55 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void check_box(int size, int **paper);
void cut_box(int size, int **paper);

int **box;
int num_minus = 0, num_zero = 0, num_plus = 0;

void cut_box(int size, int **paper)
{
	int i = 0, j = 0, num = 0;
	int cut_size = size / 3;
	int **arr[9];
	while (num < 9)
	{
		arr[num] = (int **)calloc(cut_size, sizeof(int *));
		i = 0;
		while (i < cut_size)
		{
			arr[num][i] = (int *)calloc(cut_size, sizeof(int));
			i++;
		}
		num++;
	}
	i = 0; // for real size
	j = 0; 
	num = 0;
	int k = 0, l = 0; // for small size
	while (num < 9)
	{
		k = 0;
		while (k < cut_size)
		{
			l = 0;
			while (l < cut_size)
			{
				arr[num][k][l] = paper[i][j];
				l++;
				j++;
				if(j % cut_size == 0)
					j = j - cut_size;
			}
			k++;
			i++;
			if (i % cut_size == 0)
			{
				i = i - cut_size;
				j = j + cut_size;
			}
		}
		num++;
		if (num % 3 == 0)
		{
			i = i + cut_size;
			j = 0;
		}
			
	}
	num = -1;
	while (++num < 9)
	{
		check_box(cut_size, arr[num]);
		i = 0;
		while (i < cut_size)
		{
			free(arr[num][i]);
			i++;
		}
		free(arr[num]);
	}
}

void check_box(int size, int **paper)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int out = 0;

	x = paper[0][0];

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (paper[i][j] != x)
			{
				out = 1;
				break ;
			}
			j++;
		}
		if (out == 1)
			break;
		i++;
	}
	if (i == size && j == size)
	{
		if (x == 0)
			num_zero++;
		else if (x == 1)
			num_plus++;
		else if (x == -1)
			num_minus++;
	}
	else
		cut_box(size, paper);
}


int main()
{
	int size;
	
	int i = -1;
	int j = 0;
	scanf("%d", &size);
	box = (int **)calloc(size, sizeof(int*));
	while (++i < size)
		box[i] = (int *)calloc(size, sizeof(int));
	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			scanf("%d", &box[i][j]);
			j++;
		}
		i++;
	}
	check_box(size, box);
	i = -1;
	while (++i < size)
		free(box[i]);
	free(box);
	printf("%d\n", num_minus);
	printf("%d\n", num_zero);
	printf("%d", num_plus);
	return 0;
}