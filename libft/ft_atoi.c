/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:29:24 by dcho              #+#    #+#             */
/*   Updated: 2021/05/26 21:34:07 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *str)
{
	long long	result;
	int			minus_chk;

	minus_chk = 1;
	result = 0;
	while (ft_strchr("\t\n\v\f\r ", *str))
		str++;
	if (*str == '-' || *str == '+')
	{
		*str == '-' ? minus_chk *= -1 : minus_chk;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			result += (*str - '0');
			if (ft_isdigit(*(str + 1)))
				result *= 10;
		}
		else
			return (0);
		str++;
	}
	return (result * minus_chk);
}
