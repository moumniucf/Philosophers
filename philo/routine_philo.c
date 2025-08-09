/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/09 17:23:16 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_philo *ph)
{
	long long	last_m;

	pthread_mutex_lock(&ph->data->time);
	last_m = ph->last_meal;
	pthread_mutex_unlock(&ph->data->time);
	if (last_m && (ft_get_time() - last_m) >= ph->data->time_todie)
	{
		pthread_mutex_lock(&ph->data->dead);
		ph->data->is_dead = 1;
		printf("%lld\t%d\tdied\n", \
		(ft_get_time() - ph->data->time_start), ph->id);
		pthread_mutex_unlock(&ph->data->dead);
		return (1);
	}
	return (0);
}

void	*ft_routine_philo(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
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
		ft_help_time(ph, 50);
	ft_routine_help(ph);
	return (NULL);
}
