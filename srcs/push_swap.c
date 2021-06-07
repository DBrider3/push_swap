/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:47:37 by dcho              #+#    #+#             */
/*   Updated: 2021/06/07 22:00:25 by dcho             ###   ########.fr       */
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

/*
초기 push_swap 함수
바로 quick sort 재귀로 들어가지 않는 이유는 맨 처음 rrr, rra, rrb 의 불필요를 제거하기 위해서

피벗큰게 P 작은게 p 라고 가정한다.
push_swap
{
	push_swap 첫번째 로직은

	if (a stack top 이 P 보다 크거나 같으면):
		ra를 해준다.
	else if (a stack top 이 P 보다 작으면):
		pb를 해준다.
			if (넘어간 b stack top 이  p 보다 작으면):
				rb를 해준다.
	a_to_b(ra_cnt); // 제일 큰 그룹을 정렬하기 위해서
	b_to_a(pb_cnt - rb_cnt); // 중간 그룹을 정렬하기 위해서
	b_to_a(rb_cnt); // 제일 작은 그룹을 정렬하기 위해서
}
 */
void		push_swap(t_stack *s, int r)
{
	t_cnt	c;
	int		*pivot;

	printf("push_swap <r : %d>\n", r);
	list_print(s->stack[A], A);
	if (r < 4)
	{
		if (r == 2)
		{
			if (s->stack[A]->head->next->data > \
			s->stack[A]->head->next->next->data)
				swap_one(s->stack[A], A);
		}
		// 초반에만 r == 3 에 대한 예외처리를 해주면 된다.
		if (r == 3)
			sort_three(s->stack[A], A);
		return ;
	}
	ft_bzero(&c, sizeof(t_cnt));
	pivot = find_pivot(s->stack[A], r);
	pivot_print(pivot);
	push_swap_core(s, &c, r, pivot);
	free(pivot);
	// quick sort
	printf("ra_cnt : %d\npb_cnt - rb_cnt : %d\nrb_cnt : %d\n",c.ra_cnt,c.pb_cnt - c.rb_cnt, c.rb_cnt);
	a_to_b(s, c.ra_cnt);
	b_to_a(s, c.pb_cnt - c.rb_cnt);
	b_to_a(s, c.rb_cnt);
}
