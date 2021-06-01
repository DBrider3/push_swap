/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:22:57 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 16:11:46 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

# define A 0
# define B 1
# define ALL -1

typedef struct	s_node
{
	int				data;
	int				flag;
	struct s_node	*prev;
	struct s_node	*next;

}				t_node;

typedef struct	s_dlist
{
	t_node			*head;
	t_node			*tail;
	int				list_cnt;
}				t_dlist;

typedef struct	s_stack
{
	t_dlist		*stack[2];
}				t_stack;

typedef struct	s_cnt
{
	int			ra_cnt;
	int			rb_cnt;
	int			pa_cnt;
	int			pb_cnt;
	int			ra_rb_gap;
}				t_cnt;

/*
** init part
*/
void			init_stack(t_stack **s, int arr[], int len);
void			init_list(t_dlist *dlist);
/*
** double Linked List
*/
t_node			*new_node(int data);
void			del_node(t_node *node);

void			lstadd_back(t_dlist *dlist, int data);
void			lstadd_front(t_dlist *dlist, int data);
void			lstminus_front(t_dlist *dlist);
void			lstminus_back(t_dlist *dlist);
/*
** push_swap Algorithm
*/
void			swap(int *number_a, int *number_b);
void			quick_sort(int arr[], int l, int r);
int				*find_pivot(t_dlist *dlist, int r);
void			push_swap(t_stack *s, int r);
void			a_to_b(t_stack *s, int r);
void			b_to_a(t_stack *s, int r);
void			rev_rotation_exec(t_stack *s, t_cnt *c);
void			sort_three(t_dlist *dlist, int flag);
/*
** push_swap Library
*/
void			swap_one(t_dlist *dlist, int flag);
void			swap_all(t_stack *s);
void			push_a(t_stack	*s);
void			push_b(t_stack	*s);
void			rotation_one(t_dlist *dlist, int flag);
void			rotation_all(t_stack *s);
void			rev_rotation_one(t_dlist *dlist, int flag);
void			rev_rotation_all(t_stack *s);
/*
** error
*/
void			exit_error(void);
/*
** free part
*/
void			free_all(t_stack *s, int *arr);
#endif
