/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/18 23:54:26 by youmoumn         ###   ########.fr       */
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
	ph->current_time = ft_get_time();
	if (ph->current_time - ph->last_meal >= ph->data->time_todie)
	{
		ph->data->is_dead = 1;
		printf("%lld %d died\n", ph->current_time, ph->id);

	}
}

void	*ft_routine_philo(void *arg)
{
	t_philo *ph = (t_philo *)arg;
	printf("1|%d|\n", ph->data->time_start);
	printf("2|%lld|\n", ph->current_time);
	//ph->data->time_start = ft_get_time();
	//ft_is_dead(ph);
	if(ph->id % 2 != 0)
		usleep(1000);
	while(1)
	{
		//printf("LLLL\n");
		pthread_mutex_lock(ph->l_f);
		printf("%lld %d has taken a fork\n", ft_get_time() - ph->data->time_start, ph->id);
		pthread_mutex_lock(ph->r_f);
		printf("%lld %d has taken a fork\n", ft_get_time() - ph->data->time_start, ph->id);
		ph->last_meal = ft_get_time();
		printf("%lld %d is eating\n", ft_get_time() - ph->data->time_start, ph->id);
		usleep(ph->data->time_toeat * 1000);
		ph->meal_c++;
		pthread_mutex_unlock(ph->l_f);
		pthread_mutex_unlock(ph->r_f);
		printf("%lld %d is sleeping\n", ft_get_time() - ph->data->time_start, ph->id);
		usleep(ph->data->time_tosleep * 1000);
		printf("%lld %d is thinking\n", ft_get_time() - ph->data->time_start, ph->id);
		//ft_is_dead(ph);
	}
	return (NULL);
}

