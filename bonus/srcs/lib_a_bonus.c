/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_a_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:57:57 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 20:11:24 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_one(t_dlist *dlist)
{
	if (dlist->head->next->next)
		swap(&dlist->head->next->data, &dlist->head->next->next->data);
}

void	swap_all(t_stack *s)
{
	swap_one(s->stack[A]);
	swap_one(s->stack[B]);
}

void	push_a(t_stack *s)
{
	if (s->stack[B]->head->next->flag)
	{
		lstadd_front(s->stack[A], s->stack[B]->head->next->data);
		lstminus_front(s->stack[B]);
	}
}

void	push_b(t_stack *s)
{
	if (s->stack[A]->head->next->flag)
	{
		lstadd_front(s->stack[B], s->stack[A]->head->next->data);
		lstminus_front(s->stack[A]);
	}
}
