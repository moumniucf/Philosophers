/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:23:58 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/29 18:39:00 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_help2(t_philo *ph)
{
	ft_print(ph, "has taken a fork");
	ft_print(ph, "has taken a fork");
	ft_print(ph, "is eating");
	ph->last_meal = ft_get_time();
	ph->meal_c++;
	ft_help_time(ph->data->time_toeat);
	ft_print(ph, "is sleeping");
	ft_help_time(ph->data->time_tosleep);
	ft_print(ph, "is thinking");
}


int	ft_is_dead(t_philo *ph)
{
	long long	last_m;

	last_m = ph->last_meal;
	if (last_m && (ph->current_time - last_m) >= ph->data->time_todie)
	{
		printf("%lld\t%d\tdied\n", \
		(ph->current_time - ph->data->time_start), ph->id);
		exit(1);
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
void	*ft_routine_help(t_philo *ph)
{
	int	deads;
	long long	last_m;

	while (1)
	{
		deads = ph->data->is_dead;
		if (deads == 1)
		{
			break ;
		}
		else
		{
			ft_help2(ph);

			last_m = ph->last_meal;
			ph->current_time = ft_get_time();
			if (last_m && (ph->current_time - last_m) >= ph->data->time_todie)
			{
				printf("%lld\t%d\tdied\n", \
				(ph->current_time - ph->data->time_start), ph->id);
				exit(1);
			}
			if (ph->data->number_of_time_to_eat != -1)
			{
				if (ph->meal_c >= ph->data->number_of_time_to_eat)
				{
					ph->meal_eat = 1;
					exit(0);
				}
			}
		}
	}
	return (NULL);
}
void	*ft_routine_philo(t_philo	*ph)
{
	if (ph->data->number_of_philo == 1)
	{
		ft_print(ph, "has taken a fork");
		ft_help_time(ph->data->time_todie);
		ft_print(ph, "died");
		//return (NULL);
		exit(1);
	}
	if (ph->id % 2 != 0)
		ft_help_time(50);
	//pthread_create(&ph->ts, NULL, &ft_monitoring, (void *)ph);
	ft_routine_help(ph);
	//pthread_join(ph->ts, NULL);
	return (NULL);
}