/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/22 18:12:30 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_oddph(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->data->number_of_philo)
	{
		if (ph[i].id % 2 == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->time);
	if (ph->last_meal && (ph->current_time - ph->last_meal) >= ph->data->time_todie)
	{
		pthread_mutex_lock(&ph->data->dead);
		printf("%lld %d died\n", ph->current_time - ph->data->time_start, ph->id);
		pthread_mutex_unlock(&ph->data->dead);	
		return (1);
	}
	pthread_mutex_unlock(&ph->data->time);
	return (0);
}

void	*ft_routine_philo(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	ph->current_time = ft_get_time();
	if (ph->data->number_of_philo == 1)
	{
		pthread_mutex_lock(ph->l_f);
		ft_print(ph, "has taken a fork");
		usleep(ph->data->time_todie * 1000);
		ft_print(ph, "died");
		pthread_mutex_unlock(ph->l_f);
		return (NULL);
	}
	if (ph->id % 2 != 0)
		usleep(1000);
	while (ph->data->is_dead == 0)
	{
		if (ph->data->is_dead == 1)
		{
			return (NULL);
			//break;
		}
		else
		{
			pthread_mutex_lock(ph->l_f);
			ft_print(ph, "has taken a fork");
			pthread_mutex_lock(ph->r_f);
			ft_print(ph, "has taken a fork");
			ph->last_meal = ft_get_time();
			ft_print(ph, "is eating");
			usleep(ph->data->time_toeat * 1000);
			ph->meal_c++;
			pthread_mutex_unlock(ph->l_f);
			pthread_mutex_unlock(ph->r_f);
			ft_print(ph, "is sleeping");
			usleep(ph->data->time_tosleep * 1000);
			ft_print(ph, "is thinking");
			if(ph->data->number_of_time_to_eat != -1)
			{
				if(ph->meal_c >= ph->data->number_of_time_to_eat)
				{
					//printf("LLLL\n");
					ph->meal_eat = 1;
					//break;
					return (NULL);
				}
			}
		}
	}
	return (NULL);
}
