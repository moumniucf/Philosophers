/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:35 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/25 19:50:27 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_help2(t_philo *ph)
{
	pthread_mutex_lock(ph->l_f);
	ft_print(ph, "has taken a fork");
	pthread_mutex_lock(ph->r_f);
	ft_print(ph, "has taken a fork");
	ft_print(ph, "is eating");
	pthread_mutex_lock(&ph->data->time);
	ph->last_meal = ft_get_time();
	pthread_mutex_unlock(&ph->data->time);
	pthread_mutex_lock(&ph->data->meals);
	ph->meal_c++;
	pthread_mutex_unlock(&ph->data->meals);
	usleep(ph->data->time_toeat * 1000);
	pthread_mutex_unlock(ph->l_f);
	pthread_mutex_unlock(ph->r_f);
	ft_print(ph, "is sleeping");
	usleep(ph->data->time_tosleep * 1000);
	ft_print(ph, "is thinking");
}

void	*ft_routine_help(t_philo *ph)
{
	int	deads;

	while (1)
	{
		pthread_mutex_lock(&ph->data->dead);
		deads = ph->data->is_dead;
		pthread_mutex_unlock(&ph->data->dead);
		if (deads == 1)
		{
			break ;
		}
		else
		{
			ft_help2(ph);
			if (ph->data->number_of_time_to_eat != -1)
			{
				if (ph->meal_c >= ph->data->number_of_time_to_eat)
				{
					ph->meal_eat = 1;
					return (NULL);
				}
			}
		}
	}
	return (NULL);
}

void	cleanup(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->fork[j]);
		j++;
	}
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->meals);
	free(data->fork);
	free(data->ph);
	free(data);
}

void	ft_help_main(t_data *data)
{
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->meals, NULL);
	data->time_start = ft_get_time();
	ft_fork_in(data);
	ft_philo_in(data);
	ft_create_thread(data);
	if (ft_monitoring(data) == NULL && data->number_of_philo != 1)
		return ;
	ft_join_thread(data);
	cleanup(data);
}
