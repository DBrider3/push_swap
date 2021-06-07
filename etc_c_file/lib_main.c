/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:58:34 by dcho              #+#    #+#             */
/*   Updated: 2021/05/26 17:23:58 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		operation(char *line)
{
	if (!(ft_strncmp(line, "sa\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "sb\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "ss\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "pa\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "pb\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "ra\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "rb\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "rr\0", 3)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "rra\0", 4)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "rrb\0", 4)))
			printf("search!\n");
	else if (!(ft_strncmp(line, "rrr\0", 4)))
			printf("search!\n");
	else
		exit_error();
}

void	game_main(t_dlist *dlist)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		operation(line);
		free(line);
	}
	free(line);
}
