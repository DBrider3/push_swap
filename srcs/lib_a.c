/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:57:57 by dcho              #+#    #+#             */
/*   Updated: 2021/05/31 23:16:54 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one(t_dlist *dlist, int flag)
{
	if (dlist->head->next->next)
		swap(&dlist->head->next->data, &dlist->head->next->next->data);
	if (flag == B)
		write(1, "sb\n", 3);
	else if (flag == A)
		write(1, "sa\n", 3);
}

void	swap_all(t_stack *s)
{
	swap_one(s->stack[A], ALL);
	swap_one(s->stack[B], ALL);
	write(1, "ss\n", 3);
}

void	push_a(t_stack *s)
{
	if (s->stack[B]->head->next->flag)
	{
		lstadd_front(s->stack[A], s->stack[B]->head->next->data);
		lstminus_front(s->stack[B]);
	}
	write(1, "pa\n", 3);
}

void	push_b(t_stack *s)
{
	if (s->stack[A]->head->next->flag)
	{
		lstadd_front(s->stack[B], s->stack[A]->head->next->data);
		lstminus_front(s->stack[A]);
	}
	write(1, "pb\n", 3);
}
