/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:35 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/01 23:25:55 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_help_time(long long time)
{
	long long	t1;
	long long	t2;

	t1 = ft_get_time();
	while (1)
	{
		t2 = ft_get_time();
		if ((t2 - t1) >= time)
		{
			break ;
		}
		usleep(50);
	}
}

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
	ft_help_time(ph->data->time_toeat);
	pthread_mutex_unlock(ph->l_f);
	pthread_mutex_unlock(ph->r_f);
	ft_print(ph, "is sleeping");
	ft_help_time(ph->data->time_tosleep);
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
	ft_monitoring(data);
	ft_join_thread(data);
	cleanup(data);
}
