/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:28:58 by dcho              #+#    #+#             */
/*   Updated: 2021/06/07 22:20:52 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			rotation_one(s->stack[B], B);
			c->rb_cnt++;
		}
		else
		{
			push_a(s);
			c->pa_cnt++;
			if (b_top < pivot[1])
			{
				rotation_one(s->stack[A], A);
				c->ra_cnt++;
			}
		}
	}
}

/*
b_to_a
{
	b_to_a 로직은

	b_top = 저장;
	if (b_top 저장 해놓은게 p 보다 작으면):
		rb를 해준다.
	else if (b_top 저장 해놓은게 p 보다 크거나 같으면):
		pa를 해준다.
			if (b_top 저장 해둔게[넘어간] P 보다 작으면):
				ra를 해준다.
	a_to_b(pa_cnt - ra_cnt); // 제일 큰거
	reverse_rotation;
	a_to_b(ra_cnt); // 중간꺼
	b_to_a(rb_cnt); // 작은거
}
*/
void		b_to_a(t_stack *s, int r)
{
	t_cnt	c;
	int		*pivot;

	printf("b_to_a <r : %d>\n", r);
	list_print(s->stack[A], A);
	list_print(s->stack[B], B);
	if (r < 3)
	{
		if (r == 1)
			push_a(s);
		else if (r == 2)
		{
			if (s->stack[B]->head->next->data < \
			s->stack[B]->head->next->next->data)
				swap_one(s->stack[B], B);
			push_a(s);
			push_a(s);
		}
		return ;
	}
	ft_bzero(&c, sizeof(t_cnt));
	pivot = find_pivot(s->stack[B], r);
	pivot_print(pivot);
	b_to_a_core(s, &c, r, pivot);
	free(pivot);
	printf("pa_cnt - ra_cnt : %d\nra_cnt : %d\nrb_cnt : %d\n", c.pa_cnt - c.ra_cnt ,c.ra_cnt, c.rb_cnt);
	a_to_b(s, c.pa_cnt - c.ra_cnt);
	rev_rotation_exec(s, &c);
	a_to_b(s, c.ra_cnt);
	b_to_a(s, c.rb_cnt);
}
