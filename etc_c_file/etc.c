/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:24:27 by dcho              #+#    #+#             */
/*   Updated: 2021/06/07 21:29:34 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void list_print(t_dlist *dlist, int flag)
{
	t_node *tmp;

	tmp = dlist->head->next;
	if (flag == A)
	{
		printf("A stack : ");
		while (tmp->flag)
		{
			printf("[%d] ", tmp->data);
			tmp = tmp->next;
		}
	}
	else if (flag == B)
	{
		printf("B stack : ");
		while (tmp->flag)
		{
			printf("[%d] ", tmp->data);
			tmp = tmp->next;
		}

	}
	printf("\n");
}

void pivot_print(int pivot[])
{
	printf("pivot big: %d \npivot small: %d\n", pivot[1], pivot[0]);
}
