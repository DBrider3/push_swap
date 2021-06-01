/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_b_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:42:23 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 20:11:40 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotation_one(t_dlist *dlist)
{
	if (dlist->head->next->flag)
	{
		lstadd_back(dlist, dlist->head->next->data);
		lstminus_front(dlist);
	}
}

void	rotation_all(t_stack *s)
{
	rotation_one(s->stack[A]);
	rotation_one(s->stack[B]);
}

void	rev_rotation_one(t_dlist *dlist)
{
	if (dlist->tail->prev->flag)
	{
		lstadd_front(dlist, dlist->tail->prev->data);
		lstminus_back(dlist);
	}
}

void	rev_rotation_all(t_stack *s)
{
	rev_rotation_one(s->stack[A]);
	rev_rotation_one(s->stack[B]);
}
