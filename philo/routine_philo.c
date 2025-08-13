/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucfdev <ucfdev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/13 22:44:02 by ucfdev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_is_dead(t_philo *ph)
{
	long long last_m;

	pthread_mutex_lock(&ph->data->time);
	last_m = ph->last_meal;
	pthread_mutex_unlock(&ph->data->time);
	if (last_m && (ft_get_time() - last_m) >= ph->data->time_todie)
	{
		if (ph->data->is_dead != 1)
		{
			pthread_mutex_lock(&ph->data->dead);
			printf("%lld\t%d\tdied\n",
				   (ft_get_time() - ph->data->time_start), ph->id);
			ph->data->is_dead = 1;
			pthread_mutex_unlock(&ph->data->dead);
			return (1);
		}
	}
	return (0);
}

void *ft_routine_philo(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	if (!arg)
		return (NULL);
	if (ph->data->number_of_philo == 1)
	{
		if (pthread_mutex_lock(ph->l_f) != 0)
			return (NULL);
		ft_print(ph, "has taken a fork");
		ft_help_time(ph, ph->data->time_todie);
		ft_print(ph, "died");
		return (NULL);
	}
	if (ph->id % 2 != 0)
		ft_help_time(ph, ph->data->time_toeat);
	ft_routine_help(ph);
	return (NULL);
}
