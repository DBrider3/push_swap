/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:58:34 by dcho              #+#    #+#             */
/*   Updated: 2021/06/01 20:12:40 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void		operation(t_stack *s, char *line)
{
	if (!(ft_strncmp(line, "sa\0", 3)))
		swap_one(s->stack[A]);
	else if (!(ft_strncmp(line, "sb\0", 3)))
		swap_one(s->stack[A]);
	else if (!(ft_strncmp(line, "ss\0", 3)))
		swap_all(s);
	else if (!(ft_strncmp(line, "pa\0", 3)))
		push_a(s);
	else if (!(ft_strncmp(line, "pb\0", 3)))
		push_b(s);
	else if (!(ft_strncmp(line, "ra\0", 3)))
		rotation_one(s->stack[A]);
	else if (!(ft_strncmp(line, "rb\0", 3)))
		rotation_one(s->stack[B]);
	else if (!(ft_strncmp(line, "rr\0", 3)))
		rotation_all(s);
	else if (!(ft_strncmp(line, "rra\0", 4)))
		rev_rotation_one(s->stack[A]);
	else if (!(ft_strncmp(line, "rrb\0", 4)))
		rev_rotation_one(s->stack[B]);
	else if (!(ft_strncmp(line, "rrr\0", 4)))
		rev_rotation_all(s);
	else
		exit_error();
}

void			checker_main(t_stack *s)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		operation(s, line);
		free(line);
	}
	free(line);
}
