/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:28:58 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 20:14:53 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void		b_to_a_core(t_stack *s, t_cnt *c, int r, int *pivot)
{
	int		b_top;
	int		i;

	i = -1;
	while (++i < r)
	{
		b_top = s->stack[B]->head->next->data;
		if (b_top < pivot[0])
		{
			rotation_one(s->stack[B]);
			c->rb_cnt++;
		}
		else
		{
			push_a(s);
			c->pa_cnt++;
			if (b_top < pivot[1])
			{
				rotation_one(s->stack[A]);
				c->ra_cnt++;
			}
		}
	}
}

void		b_to_a(t_stack *s, int r)
{
	t_cnt	c;
	int		*pivot;

	if (r < 3)
	{
		if (r == 1)
			push_a(s);
		else if (r == 2)
		{
			if (s->stack[B]->head->next->data < \
			s->stack[B]->head->next->next->data)
				swap_one(s->stack[B]);
			push_a(s);
			push_a(s);
		}
		return ;
	}
	ft_bzero(&c, sizeof(t_cnt));
	pivot = find_pivot(s->stack[B], r);
	b_to_a_core(s, &c, r, pivot);
	free(pivot);
	a_to_b(s, c.pa_cnt - c.ra_cnt);
	rev_rotation_exec(s, &c);
	a_to_b(s, c.ra_cnt);
	b_to_a(s, c.rb_cnt);
}
