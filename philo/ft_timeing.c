/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucfdev <ucfdev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:30 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/16 21:55:29 by ucfdev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long ft_get_time(void)
{
	struct timeval time;
	long long x;

	gettimeofday(&time, NULL);
	x = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (x);
}

void ft_print(t_data *data, t_philo *ph, char *str)
{
	if (pthread_mutex_lock(&ph->data->print) != 0)
		return;
	// if (pthread_mutex_lock(&ph->data->dead) != 0)
		// return;
	if (pthread_mutex_lock(&ph->data->time) != 0)
		return;
	pthread_mutex_lock(&ph->data->finishing);
	if (ph->data->finish == 0)
	{
		printf("%lld\t%d\t%s\n",
		(ft_get_time() - ph->data->time_start), ph->id, str);
	}
	pthread_mutex_unlock(&ph->data->finishing);
	if (pthread_mutex_unlock(&ph->data->time) != 0)
		return;
	// if (pthread_mutex_unlock(&ph->data->dead) != 0)
		// return;
	if (pthread_mutex_unlock(&ph->data->print) != 0)
		return;
}

int ft_checkdead(t_data *data, int i)
{
	if (ft_is_dead(&data->ph[i]))
	{
		pthread_mutex_lock(&data->dead);
		data->is_dead = 1;
		pthread_mutex_lock(&data->finishing);
		data->finish = 1;
		pthread_mutex_unlock(&data->finishing);
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	return (0);
}

int ft_checkmeal(t_data *data)
{
	pthread_mutex_lock(&data->salinae);
	if (data->number_of_time_to_eat != -1 && data->salina == data->number_of_philo * data->number_of_time_to_eat)
	{
		pthread_mutex_lock(&data->meals);
		data->ph->meal_eat = 1;
		data->finish = 1;
		pthread_mutex_unlock(&data->meals);
		pthread_mutex_unlock(&data->salinae);
		return (1);
	}
	pthread_mutex_unlock(&data->salinae);
	return (0);
}

void *ft_monitoring(t_data *data)
{
	int i;

	while (data->finish == 0)
	{
		if (ft_checkmeal(data) == 1)
		{
			// break;
			return (NULL);
		}
		i = 0;
		while (i < data->number_of_philo)
		{
			if (ft_checkdead(data, i) == 1)
			{
				// break;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
