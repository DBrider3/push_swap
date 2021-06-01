/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:01:03 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 20:13:40 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int			*dlist_contents(t_dlist *dlist)
{
	t_node			*tmp;
	int				*arr;
	int				index;

	if (!(arr = malloc(sizeof(int) * 3)))
		exit_error();
	index = -1;
	tmp = dlist->head->next;
	while (++index < 3)
	{
		arr[index] = tmp->data;
		tmp = tmp->next;
	}
	return (arr);
}

static char			*ft_strcpy(char *dest, const char *src)
{
	int				i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}

static char			*get_order(t_dlist *dlist)
{
	static char		buf[4];
	int				*values;

	values = dlist_contents(dlist);
	ft_strcpy(buf, "111");
	if (values[0] > values[1])
		buf[0]++;
	if (values[0] > values[2])
		buf[0]++;
	if (values[1] > values[0])
		buf[1]++;
	if (values[1] > values[2])
		buf[1]++;
	if (values[2] > values[0])
		buf[2]++;
	if (values[2] > values[1])
		buf[2]++;
	free(values);
	return (&buf[0]);
}

void				sort_three(t_dlist *dlist)
{
	char			*order;

	order = get_order(dlist);
	if (ft_strncmp(order, "132", 3) == 0)
	{
		rev_rotation_one(dlist);
		swap_one(dlist);
	}
	else if (ft_strncmp(order, "213", 3) == 0)
		swap_one(dlist);
	else if (ft_strncmp(order, "231", 3) == 0)
		rev_rotation_one(dlist);
	else if (ft_strncmp(order, "312", 3) == 0)
		rotation_one(dlist);
	else if (ft_strncmp(order, "321", 3) == 0)
	{
		rotation_one(dlist);
		swap_one(dlist);
	}
}
