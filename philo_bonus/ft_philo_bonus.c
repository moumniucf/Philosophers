/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:23:58 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/27 17:46:16 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
long long	ft_get_time(void)
{
	struct timeval	time;
	long long		x;

	gettimeofday(&time, NULL);
	x = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (x);
}

void	ft_help2(t_philo *ph)
{
	//pthread_mutex_lock(ph->l_f);
	ft_print(ph, "has taken a fork");
	//pthread_mutex_lock(ph->r_f);
	ft_print(ph, "has taken a fork");
	ft_print(ph, "is eating");
	//pthread_mutex_lock(&ph->data->time);
	ph->last_meal = ft_get_time();
	//pthread_mutex_unlock(&ph->data->time);
	//pthread_mutex_lock(&ph->data->meals);
	ph->meal_c++;
	//pthread_mutex_unlock(&ph->data->meals);
	ft_help_time(ph->data->time_toeat);
	//pthread_mutex_unlock(ph->l_f);
	//pthread_mutex_unlock(ph->r_f);
	ft_print(ph, "is sleeping");
	ft_help_time(ph->data->time_tosleep);
	ft_print(ph, "is thinking");
}

void	*ft_routine_help(t_philo *ph)
{
	int	deads;

	while (1)
	{
		//pthread_mutex_lock(&ph->data->dead);
		deads = ph->data->is_dead;
		//pthread_mutex_unlock(&ph->data->dead);
		if (deads == 1)
		{
			break ;
		}
		else
		{
			ft_help2(ph);
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
int	ft_is_dead(t_philo *ph)
{
	long long	last_m;

	//pthread_mutex_lock(&ph->data->time);
	last_m = ph->last_meal;
	//pthread_mutex_unlock(&ph->data->time);
	if (last_m && (ph->current_time - last_m) >= ph->data->time_todie)
	{
		//pthread_mutex_lock(&ph->data->dead);
		printf("%lld\t%d\tdied\n", \
		(ph->current_time - ph->data->time_start), ph->id);
		//pthread_mutex_unlock(&ph->data->dead);
		return (1);
	}
	return (0);
}
void	ft_help_time(long long time)
{
	long long	t1;
	long long	t2;

	t1 = ft_get_time();
	while (1)
	{
		t2 = ft_get_time();
		if ((t2 - t1) >= time)
		{
			break ;
		}
		usleep(50);
	}
}
void	*ft_routine_philo(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->data->number_of_philo == 1)
	{
		//pthread_mutex_lock(ph->l_f);
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
