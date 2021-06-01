/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:47:37 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 15:36:12 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap_core(t_stack *s, t_cnt *c, int r, int *pivot)
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
			if (s->stack[B]->head->next->data < pivot[0])
			{
				rotation_one(s->stack[B], B);
				c->rb_cnt++;
			}
		}
	}
}

void		rev_rotation_exec(t_stack *s, t_cnt *c)
{
	int		i;

	c->ra_rb_gap = c->ra_cnt > c->rb_cnt ? c->rb_cnt : c->ra_cnt;
	i = -1;
	while (++i < c->ra_rb_gap)
		rev_rotation_all(s);
	if (c->ra_cnt > c->rb_cnt)
	{
		i = -1;
		while (++i < c->ra_cnt - c->rb_cnt)
			rev_rotation_one(s->stack[A], A);
	}
	else if (c->rb_cnt > c->ra_cnt)
	{
		i = -1;
		while (++i < c->rb_cnt - c->ra_cnt)
			rev_rotation_one(s->stack[B], B);
	}
}

void		push_swap(t_stack *s, int r)
{
	t_cnt	c;
	int		*pivot;

	if (r < 4)
	{
		if (r == 2)
		{
			if (s->stack[A]->head->next->data > \
			s->stack[A]->head->next->next->data)
				swap_one(s->stack[A], A);
		}
		if (r == 3)
			sort_three(s->stack[A], A);
		return ;
	}
	ft_bzero(&c, sizeof(t_cnt));
	pivot = find_pivot(s->stack[A], r);
	push_swap_core(s, &c, r, pivot);
	free(pivot);
	a_to_b(s, c.ra_cnt);
	b_to_a(s, c.pb_cnt - c.rb_cnt);
	b_to_a(s, c.rb_cnt);
}
