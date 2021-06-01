/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:07:27 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 16:57:14 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node		*new_node(int data)
{
	t_node		*res;

	if (!(res = malloc(sizeof(t_node))))
		exit_error();
	res->data = data;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void		del_node(t_node *node)
{
	node->prev = NULL;
	node->next = NULL;
	free(node);
}
