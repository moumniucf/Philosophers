/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/29 10:06:56 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_philo *ph)
{
	long long	last_m;

	pthread_mutex_lock(&ph->data->time);
	last_m = ph->last_meal;
	pthread_mutex_unlock(&ph->data->time);
	if (last_m && (ph->current_time - last_m) >= ph->data->time_todie)
	{
		pthread_mutex_lock(&ph->data->dead);
		printf("%lld\t%d\tdied\n", \
		(ph->current_time - ph->data->time_start), ph->id);
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
		pthread_mutex_lock(ph->l_f);
		ft_print(ph, "has taken a fork");
		ft_help_time(ph->data->time_todie);
		ft_print(ph, "died");
		return (NULL);
	}
	if (ph->id % 2 != 0)
		ft_help_time(50);
	ft_routine_help(ph);
	return (NULL);
}
