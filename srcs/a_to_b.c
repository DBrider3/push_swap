/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:28:00 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 15:34:56 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		a_to_b_core(t_stack *s, t_cnt *c, int r, int *pivot)
{
	int		i;

	i = -1;
	while (++i < r)
	{
		if (s->stack[A]->head->next->data >= pivot[1])
		{
			rotation_one(s->stack[A], A);
			c->ra_cnt++;
		}
		else
		{
			push_b(s);
			c->pb_cnt++;
			if (s->stack[B]->head->next->data >= pivot[0])
			{
				rotation_one(s->stack[B], B);
				c->rb_cnt++;
			}
		}
	}
}

void		a_to_b(t_stack *s, int r)
{
	t_cnt	c;
	int		*pivot;

	if (r < 3)
	{
		if (r == 2)
		{
			if (s->stack[A]->head->next->data > \
			s->stack[A]->head->next->next->data)
				swap_one(s->stack[A], A);
		}
		return ;
	}
	ft_bzero(&c, sizeof(t_cnt));
	pivot = find_pivot(s->stack[A], r);
	a_to_b_core(s, &c, r, pivot);
	free(pivot);
	rev_rotation_exec(s, &c);
	a_to_b(s, c.ra_cnt);
	b_to_a(s, c.rb_cnt);
	b_to_a(s, c.pb_cnt - c.rb_cnt);
}
