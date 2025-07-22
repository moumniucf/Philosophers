/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:59:02 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/22 09:59:10 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

void	ft_atoihelp(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = x * -1;
		i++;
	}
}

int	ft_atoi(char *str)
{
	int				i;
	int				x;
	long			rst;

	i = 0;
	x = 1;
	rst = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	ft_atoihelp(str);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		rst = rst * 10 + str[i] - 48;
		if ((size_t)rst > LLONG_MAX && x == -1)
			return (0);
		if ((size_t)rst > LLONG_MAX)
			return (-1);
		i++;
	}
	return (rst * x);
}
