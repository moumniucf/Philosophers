/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucfdev <ucfdev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:35 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/13 23:31:32 by ucfdev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_help_time(t_philo *ph, long long time)
{
	long long t1;
	long long t2;
	long long last_m;

	pthread_mutex_lock(&ph->data->time);
	last_m = ph->last_meal;
	pthread_mutex_unlock(&ph->data->time);
	t1 = ft_get_time();
	while (1)
	{
		t2 = ft_get_time();
		pthread_mutex_lock(&ph->data->time);
		ph->current_time = t2;
		pthread_mutex_unlock(&ph->data->time);
		if (last_m && (ft_get_time() - last_m) >= ph->data->time_todie)
			break;
		if ((t2 - t1) >= time)
			break;
		usleep(50);
	}
}

void ft_help2(t_philo *ph)
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
	ft_help_time(ph, ph->data->time_toeat);
	pthread_mutex_unlock(ph->l_f);
	pthread_mutex_unlock(ph->r_f);
	ft_print(ph, "is sleeping");
	ft_print(ph, "is thinking");
	ft_help_time(ph, ph->data->time_tosleep);
}

void *ft_routine_help(t_philo *ph)
{
	int deads;

	while (1 && ph->data->is_dead != 1)
	{
		pthread_mutex_lock(&ph->data->dead);
		deads = ph->data->is_dead;
		pthread_mutex_unlock(&ph->data->dead);
		ft_help2(ph);
		if (ph->data->number_of_time_to_eat != -1)
		{
			if (ph->meal_c >= ph->data->number_of_time_to_eat &&
				!ft_is_dead(ph))
			{
				ph->meal_eat = 1;
				return (NULL);
			}
		}
	}
	return (NULL);
}

void cleanup(t_data *data)
{
	int j;

	j = 0;
	if (!data)
		return;
	while (j < data->number_of_philo)
	{
		if (pthread_mutex_destroy(&data->fork[j]) != 0)
			return;
		j++;
	}
	if (pthread_mutex_destroy(&data->dead) != 0)
		return;
	if (pthread_mutex_destroy(&data->print) != 0)
		return;
	if (pthread_mutex_destroy(&data->time) != 0)
		return;
	if (pthread_mutex_destroy(&data->meals))
		return;
	free(data->fork);
	free(data->ph);
	free(data);
}

void ft_help_main(t_data *data)
{
	char *monit;

	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->meals, NULL);
	data->time_start = ft_get_time();
	if (ft_fork_in(data) != 0)
	{
		cleanup(data);
		return;
	}
	if (ft_philo_in(data) != 0)
	{
		cleanup(data);
		return;
	}
	if (ft_create_thread(data) != 0)
	{
		cleanup(data);
		return;
	}
	monit = ft_monitoring(data);
	if (monit == NULL && data->ph->meal_eat != 1)
	{
		ft_join_thread(data);
		cleanup(data);
		return;
	}
	if (ft_join_thread(data) != 0)
	{
		cleanup(data);
		return;
	}
	cleanup(data);
}
