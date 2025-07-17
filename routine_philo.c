/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/17 18:14:10 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int is_oddph(t_philo *ph)
{
	int i = 0;
	while(i < ph->data->number_of_philo)
	{
		if(ph[i].id % 2 == 0)
			return (1);
		i++;
	}
	return (0);
}

void ft_is_dead(t_philo *ph)
{
	ph->last_meal = ft_get_time();
	if(ph->current_time - ph->last_meal >= ph->data->time_toeat)
	{
		ph->data->is_dead = 1;
	}
}

void	*ft_routine_philo(void *arg)
{
	t_philo *ph = (t_philo *)arg;
	ph->current_time = ft_get_time();
	printf("-->(%lld)\n", ph->last_meal);
	
	while(ph->data->is_dead)
	{
		if(ph->id % 2 != 0)
			usleep(1000);
		else
		{
			printf("%ld %d has taken a fork\n", ft_get_time() - ph->current_time, ph->id);
			pthread_mutex_lock(ph->l_f);
			pthread_mutex_lock(ph->r_f);
			ph->meal_c++;
			printf("%ld %d is eating\n", ft_get_time() - ph->current_time, ph->id);
			ph->last_meal = ft_get_time();
			//usleep(ph->data->time_toeat);
			printf("%ld %d is thinking\n", ft_get_time() - ph->current_time, ph->id);
			//usleep(ph->data->time_tothink);
		}
	}
	return (NULL);
}
