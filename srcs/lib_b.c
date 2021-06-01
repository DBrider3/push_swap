/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:42:23 by dcho              #+#    #+#             */
/*   Updated: 2021/05/31 23:12:01 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_one(t_dlist *dlist, int flag)
{
	if (dlist->head->next->flag)
	{
		lstadd_back(dlist, dlist->head->next->data);
		lstminus_front(dlist);
	}
	if (flag == B)
		write(1, "rb\n", 3);
	else if (flag == A)
		write(1, "ra\n", 3);
}

void	rotation_all(t_stack *s)
{
	rotation_one(s->stack[A], ALL);
	rotation_one(s->stack[B], ALL);
	write(1, "rr\n", 3);
}

void	rev_rotation_one(t_dlist *dlist, int flag)
{
	if (dlist->tail->prev->flag)
	{
		lstadd_front(dlist, dlist->tail->prev->data);
		lstminus_back(dlist);
	}
	if (flag == B)
		write(1, "rrb\n", 4);
	else if (flag == A)
		write(1, "rra\n", 4);
}

void	rev_rotation_all(t_stack *s)
{
	rev_rotation_one(s->stack[A], ALL);
	rev_rotation_one(s->stack[B], ALL);
	write(1, "rrr\n", 4);
}
