/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/24 23:47:05 by youmoumn         ###   ########.fr       */
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
	int		deads;

	ph = (t_philo *)arg;
	if (ph->data->number_of_philo == 1)
	{
		pthread_mutex_lock(ph->l_f);
		ft_print(ph, "has taken a fork");
		usleep(ph->data->time_todie * 1000);
		ft_print(ph, "died");
		free(ph);
		return (NULL);
	}
	if (ph->id % 2 != 0)
		usleep(1000);
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
