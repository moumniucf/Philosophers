/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:30 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/23 22:44:35 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	time;
	long long		x;

	gettimeofday(&time, NULL);
	x = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (x);
}
void	ft_print(t_philo *ph, char *str)
{
	pthread_mutex_lock(&ph->data->print);
	pthread_mutex_lock(&ph->data->dead);
	pthread_mutex_lock(&ph->data->time);
	ph->current_time = ft_get_time() - ph->data->time_start;
	if(ph->data->is_dead == 0)
	{
		printf("%lld\t%d\t%s\n", ph->current_time, ph->id, str);
	}
	pthread_mutex_unlock(&ph->data->time);
	pthread_mutex_unlock(&ph->data->dead);
	pthread_mutex_unlock(&ph->data->print);
}

void	*ft_monitoring(t_data *data)
{
	int	i;

	while (1 && data->number_of_philo != 1)
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			if (ft_is_dead(&data->ph[i]))
			{
				pthread_mutex_lock(&data->dead);
				data->is_dead = 1;
				pthread_mutex_unlock(&data->dead);
				return (NULL);
			}
			if(data->number_of_time_to_eat != -1)
			{
				if(data->ph[i].meal_c == data->number_of_time_to_eat)
				{
					return (NULL);
				}
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

