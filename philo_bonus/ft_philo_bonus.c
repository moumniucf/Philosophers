/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:23:58 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/09 17:05:41 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_help_time(t_philo *ph, long long time)
{
	long long	t1;
	long long	t2;
	long long	last_m;

	last_m = ph->last_meal;
	t1 = ft_get_time();
	while (1)
	{
		t2 = ft_get_time();
		ph->current_time = t2;
		if (last_m && (ph->current_time - last_m) >= ph->data->time_todie)
			break ;
		if ((t2 - t1) >= time)
			break ;
		usleep(50);
	}
}

void	*ft_monitoring(void *arg)
{
	t_philo		*ph;
	long long	meals;

	ph = (t_philo *)arg;
	while (1)
	{
		sem_wait(ph->data->lock_meal);
		meals = ph->last_meal;
		sem_post(ph->data->lock_meal);
		if (meals && (ft_get_time() - meals) >= ph->data->time_todie)
		{
			sem_wait(ph->data->print);
			printf("%lld\t%d\tdied\n", \
			(ft_get_time() - ph->data->time_start), ph->id);
			exit(1);
		}
		ft_help_time(ph, 50);
	}
	return (NULL);
}

void	ft_help2(t_philo *ph)
{
	sem_wait(ph->data->meal);
	sem_post(ph->data->meal);
	sem_wait(ph->data->fork);
	ft_print(ph, "has taken a fork");
	sem_wait(ph->data->fork);
	ft_print(ph, "has taken a fork");
	ft_print(ph, "is eating");
	sem_wait(ph->data->lock_meal);
	ph->last_meal = ft_get_time();
	sem_post(ph->data->lock_meal);
	sem_wait(ph->data->meal);
	ph->meal_c++;
	sem_post(ph->data->meal);
	ft_help_time(ph, ph->data->time_toeat);
	sem_post(ph->data->fork);
	sem_post(ph->data->fork);
	ft_print(ph, "is sleeping");
	ft_help_time(ph, ph->data->time_tosleep);
	ft_print(ph, "is thinking");
}

void	*ft_routine_help(t_philo *ph)
{
	while (1)
	{
		ft_help2(ph);
		if (ph->data->number_of_time_to_eat != -1)
		{
			if (ph->meal_c >= ph->data->number_of_time_to_eat)
			{
				exit(0);
			}
		}
	}
	return (NULL);
}

void	*ft_routine_philo(t_philo	*ph)
{
	ph->current_time = ft_get_time();
	if (ph->data->number_of_philo == 1)
	{
		ft_print(ph, "has taken a fork");
		ft_help_time(ph, ph->data->time_todie);
		ft_print(ph, "died");
		exit(1);
	}
	if (pthread_create(&ph->ts, NULL, ft_monitoring, ph) != 0)
		return (NULL);
	sem_post(ph->data->lock_meal);
	if (ph->id % 2 != 0)
		ft_help_time(ph, 100);
	ft_routine_help(ph);
	pthread_join(ph->ts, NULL);
	return (NULL);
}
