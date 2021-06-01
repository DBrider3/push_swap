/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:49:29 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 16:56:59 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_stack(t_stack **s, int arr[], int len)
{
	int		i;

	if (!(*s = malloc(sizeof(t_stack))))
		exit_error();
	if (!((*s)->stack[A] = malloc(sizeof(t_dlist))))
		exit_error();
	if (!((*s)->stack[B] = malloc(sizeof(t_dlist))))
		exit_error();
	init_list((*s)->stack[A]);
	init_list((*s)->stack[B]);
	i = -1;
	while (++i < len)
		lstadd_back((*s)->stack[A], arr[i]);
	quick_sort(arr, 0, len - 1);
}

void	init_list(t_dlist *dlist)
{
	dlist->head = new_node(0);
	dlist->tail = new_node(0);
	dlist->head->flag = 0;
	dlist->tail->flag = 0;
	dlist->head->next = dlist->tail;
	dlist->tail->prev = dlist->head;
	dlist->list_cnt = 0;
}
