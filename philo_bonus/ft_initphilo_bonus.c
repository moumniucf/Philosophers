/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initphilo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:54:21 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/22 09:57:23 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_arg_in(char **av, t_data *da)
{
	if (!da)
		return ;
	(da)->number_of_philo = ft_atoi(av[1]);
	(da)->time_todie = ft_atoi(av[2]);
	(da)->time_toeat = ft_atoi(av[3]);
	(da)->time_tosleep = ft_atoi(av[4]);
	if (av[5])
		(da)->number_of_time_to_eat = ft_atoi(av[5]);
	else
		(da)->number_of_time_to_eat = -1;
}