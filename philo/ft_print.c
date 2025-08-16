/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucfdev <ucfdev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:35 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/17 00:06:41 by ucfdev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_help_time(t_philo *ph, long long time)
{
	long long	t1;
	long long	t2;
	long long	last_m;

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
		if ((last_m && (ft_get_time() - last_m) >= ph->data->time_todie))
			break ;
		if ((t2 - t1) >= time)
			break ;
		usleep(50);
	}
}

void	ft_help2(t_philo *ph, t_data *data)
{
	pthread_mutex_lock(ph->l_f);
	ft_print(data, ph, "has taken a fork");
	pthread_mutex_lock(ph->r_f);
	ft_print(data, ph, "has taken a fork");
	ft_print(data, ph, "is eating");
	pthread_mutex_lock(&ph->data->time);
	ph->last_meal = ft_get_time();
	pthread_mutex_unlock(&ph->data->time);
	pthread_mutex_lock(&ph->data->meals);
	ph->meal_c++;
	pthread_mutex_unlock(&ph->data->meals);
	pthread_mutex_lock(&ph->data->salinae);	
	ph->data->salina++;
	pthread_mutex_unlock(&ph->data->salinae);	
	ft_help_time(ph, ph->data->time_toeat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(ph->l_f);
	ft_print(data, ph, "is sleeping");
	ft_help_time(ph, ph->data->time_tosleep);
	ft_print(data, ph, "is thinking");
}

void	*ft_routine_help(t_philo *ph, t_data *data)
{
	while (1 && ph->data->is_dead != 1)
	{
		if (ph->data->finish == 1)
			break ;
		pthread_mutex_lock(&ph->data->dead);
		pthread_mutex_unlock(&ph->data->dead);
		ft_help2(ph, data);
		if (ph->data->number_of_time_to_eat != -1)
		{
			if (ph->meal_c >= ph->data->number_of_time_to_eat && \
			!ft_is_dead(ph))
			{
				ph->meal_eat = 1;
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	cleanup(t_data *data)
{
	int	j;

	j = 0;
	if (!data)
		return ;
	while (j < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->fork[j]);
		j++;
	}
	if (pthread_mutex_destroy(&data->dead) != 0)
		return ;
	if (pthread_mutex_destroy(&data->print) != 0)
		return ;
	if (pthread_mutex_destroy(&data->time) != 0)
		return ;
	if (pthread_mutex_destroy(&data->meals))
		return ;
	if (pthread_mutex_destroy(&data->finishing))
		return ;
	if (pthread_mutex_destroy(&data->salinae))
		return ;
	free(data->fork);
	free(data->ph);
	free(data);
}

void	ft_help_main(t_data *data)
{
	char	*monit;

	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->meals, NULL);
	pthread_mutex_init(&data->finishing, NULL);
	pthread_mutex_init(&data->salinae, NULL);
	data->time_start = ft_get_time();
	ft_help_norm_main(data);
	monit = ft_monitoring(data);
	if (monit == NULL)
	{
		ft_join_thread(data);
		cleanup(data);
		return ;
	}
	if (ft_join_thread(data) != 0)
	{
		cleanup(data);
		return ;
	}
	cleanup(data);
}
