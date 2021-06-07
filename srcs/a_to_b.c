/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:28:00 by dcho              #+#    #+#             */
/*   Updated: 2021/06/07 22:11:24 by dcho             ###   ########.fr       */
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
/*
a_to_b
{
	a_to_b 로직은

	if (a stack top 이 P 보다 크거나 같으면):
		ra를 해준다.
	else if (a stack top 이 P 보다 작으면):
		pb를 해준다.
			if (넘어간 b stack top 이  p 보다 크거나 같으면):
				rb를 해준다.
	reverse_rotation;
	a_to_b(ra_cnt); // 제일 큰 그룹 정렬
	b_to_a(rb_cnt); // 중간 그룹 정렬
	b_to_a(pb_cnt - rb_cnt); // 제일 작은 그룹 정렬
}
*/
void		a_to_b(t_stack *s, int r)
{
	t_cnt	c;
	int		*pivot;

	printf("a_to_b <r : %d>\n", r);
	list_print(s->stack[A], A);
	list_print(s->stack[B], B);
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
	pivot_print(pivot);
	a_to_b_core(s, &c, r, pivot);
	free(pivot);
	rev_rotation_exec(s, &c);
	printf("ra_cnt : %d\nrb_cnt : %d\npb_cnt - rb_cnt : %d\n",c.ra_cnt, c.rb_cnt, c.pb_cnt - c.rb_cnt);
	a_to_b(s, c.ra_cnt);
	b_to_a(s, c.rb_cnt);
	b_to_a(s, c.pb_cnt - c.rb_cnt);
}
