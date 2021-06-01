/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:54:32 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 16:56:56 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	list_clean(t_dlist *dlist)
{
	while (dlist->list_cnt)
		lstminus_back(dlist);
	del_node(dlist->head);
	del_node(dlist->tail);
}

void		free_all(t_stack *s, int *arr)
{
	list_clean(s->stack[A]);
	list_clean(s->stack[B]);
	free(s->stack[A]);
	free(s->stack[B]);
	free(s);
	free(arr);
}
