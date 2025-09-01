/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:18:13 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/17 09:19:22 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_close_sem(t_data *data)
{
	sem_close(data->print);
	sem_close(data->time);
	sem_close(data->fork);
	sem_close(data->dead);
	sem_close(data->meal);
	sem_close(data->lock_meal);
}

void	ft_kill_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		kill(data->pid[i], SIGINT);
		i++;
	}
}

void	ft_waitp(t_data *da)
{
	int	status;
	int	i;

	i = 0;
	while (i < da->number_of_philo)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			ft_kill_all(da);
			break ;
		}
		i++;
	}
}
