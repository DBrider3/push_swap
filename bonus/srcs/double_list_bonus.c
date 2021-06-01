/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:51:51 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 16:56:52 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	lstadd_back(t_dlist *dlist, int data)
{
	t_node	*new;

	new = new_node(data);
	new->flag = 1;
	new->next = dlist->tail;
	new->prev = dlist->tail->prev;
	dlist->tail->prev->next = new;
	dlist->tail->prev = new;
	dlist->list_cnt++;
}

void	lstadd_front(t_dlist *dlist, int data)
{
	t_node	*new;

	new = new_node(data);
	new->flag = 1;
	new->prev = dlist->head;
	new->next = dlist->head->next;
	dlist->head->next->prev = new;
	dlist->head->next = new;
	dlist->list_cnt++;
}

void	lstminus_front(t_dlist *dlist)
{
	t_node	*del;

	del = dlist->head->next;
	dlist->head->next->next->prev = dlist->head;
	dlist->head->next = dlist->head->next->next;
	dlist->list_cnt--;
	del_node(del);
}

void	lstminus_back(t_dlist *dlist)
{
	t_node	*del;

	del = dlist->tail->prev;
	dlist->tail->prev->prev->next = dlist->tail;
	dlist->tail->prev = dlist->tail->prev->prev;
	dlist->list_cnt--;
	del_node(del);
}
