/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:43:57 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 16:57:22 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	partition(int arr[], int l, int r)
{
	int		pivot;
	int		i;
	int		j;

	pivot = arr[r];
	i = l - 1;
	j = l - 1;
	while (++j < r)
	{
		if (arr[j] <= pivot)
			swap(&arr[++i], &arr[j]);
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void		swap(int *number_a, int *number_b)
{
	int		tmp;

	tmp = *number_a;
	*number_a = *number_b;
	*number_b = tmp;
}

void		quick_sort(int arr[], int l, int r)
{
	int		p;

	if (l < r)
	{
		p = partition(arr, l, r);
		quick_sort(arr, l, p - 1);
		quick_sort(arr, p + 1, r);
	}
}
