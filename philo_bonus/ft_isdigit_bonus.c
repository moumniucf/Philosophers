/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:11:47 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/14 11:32:36 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_run_simulation(t_data *data)
{
	if (ft_init_philo(data) != 0)
	{
		free(data->pid);
		free(data->ph);
		free(data);
		return (1);
	}
	if (ft_seminit(data) != 0)
	{
		free(data->pid);
		free(data->ph);
		free(data);
		return (1);
	}
	data->time_start = ft_get_time();
	if (ft_init_pfork(data) != 0)
	{
		free(data->pid);
		free(data->ph);
		free(data);
		return (1);
	}
	ft_waitp(data);
	ft_close_sem(data);
	return (0);
}
