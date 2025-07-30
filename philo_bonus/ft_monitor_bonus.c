/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:18:13 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/30 16:06:27 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


int	ft_checkdead(t_data *data, int i)
{
	if (ft_is_dead(&data->ph[i]))
	{
		printf("{{%d}}\n", data->number_of_philo);
		data->is_dead = 1;
		return (1);
	}
	return (0);
}

int	ft_checkmeal(t_data *data, int i)
{
	int	eats;

	if (data->number_of_time_to_eat != -1)
	{
		eats = data->ph[i].meal_c;
		if (eats == data->number_of_time_to_eat)
		{
			return (1);
		}
	}
	return (0);
}
//void	*ft_monitoring(void *arg)
//{
//	t_data *data = (t_data *)arg;
//	int	i;
//	while (1 && data->number_of_philo != 1)
//	{
//		i = 0;
//		data->ph->current_time = ft_get_time();
//		while (i < data->number_of_philo)
//		{
//			if (ft_checkdead(data, i) == 1)
//				return (NULL);
//			if (ft_checkmeal(data, i) == 1)
//				return (NULL);
//			i++;
//		}
//		ft_help_time(50);
//	}
//	return (NULL);
//}


void	ft_close_sem(t_data *data)
{
	sem_close(data->print);
	sem_close(data->fork);
}
void ft_kill_all(t_data *data)
{
	int i = 0;
	while(i < data->number_of_philo)
	{
		kill(data->pid[i], SIGKILL);
		i++;
	}
}
void	ft_waitp(t_data *da)
{
	int status;
	
	int i = 0;
	status  = 0;
	while(i < da->number_of_philo)
	{
		waitpid(-1, &status, 0);
		//|| WEXITSTATUS(status) == 0
		if(WEXITSTATUS(status) == 1)
		{
			ft_kill_all(da);
		}
		i++;
	}
}