/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:34:36 by dcho              #+#    #+#             */
/*   Updated: 2021/06/07 21:26:15 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		list_check(t_dlist *dlist, int arr[])
{
	t_node		*tmp;
	int			i;

	i = -1;
	tmp = dlist->head->next;
	while (tmp->flag)
	{
		if (arr[++i] != tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		argument_check(char *argv)
{
	long long	num;

	if ((!(num = ft_atoi(argv)) && ft_strncmp(argv, "0\0", 2)) ||
	num >= 2147483647 || num <= -2147483648)
		exit_error();
	return ((int)num);
}

static void		duplicate_check(int *arr, int len)
{
	int			i;
	int			j;
	int			cnt;

	i = -1;
	while (++i < len)
	{
		j = -1;
		cnt = 0;
		while (++j < len)
		{
			if (arr[i] == arr[j])
			{
				if (i > j)
					break ;
				cnt++;
				if (cnt == 2)
					exit_error();
			}
		}
	}
}

int				main(int argc, char *argv[])
{
	t_stack		*s;
	int			*arr;
	int			i;
	int			index;

	if (!(arr = ft_calloc(argc - 1, sizeof(int))))
		exit_error();
	i = 0;
	index = 0;
	while (++i < argc)
		arr[index++] = argument_check(argv[i]);
	duplicate_check(arr, argc - 1);
	init_stack(&s, arr, argc - 1);
	list_print(s->stack[A], A);
	if (!list_check(s->stack[A], arr))
		push_swap(s, s->stack[A]->list_cnt);
	free_all(s, arr);
    system("leaks push_swap 1>&2");
	return (0);
}
