/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:26:31 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 16:57:17 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int		*find_pivot(t_dlist *dlist, int r)
{
	int		*arr;
	int		*pivot;
	int		index;
	t_node	*node;

	if (!dlist->head->next->flag)
		exit_error();
	if (!(pivot = malloc(sizeof(int) * 2)))
		exit_error();
	node = dlist->head->next;
	if (!(arr = malloc(sizeof(int) * r)))
		exit_error();
	index = -1;
	while (++index < r && node->flag)
	{
		arr[index] = node->data;
		node = node->next;
	}
	quick_sort(arr, 0, r - 1);
	pivot[0] = arr[r / 3];
	pivot[1] = arr[r * 2 / 3];
	free(arr);
	return (pivot);
}
