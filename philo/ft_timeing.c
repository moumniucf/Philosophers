/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:30 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/16 18:19:31 by youmoumn         ###   ########.fr       */
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
	if (pthread_mutex_lock(&ph->data->print) != 0)
		return ;
	if (pthread_mutex_lock(&ph->data->dead) != 0)
		return ;
	if (pthread_mutex_lock(&ph->data->time) != 0)
		return ;
	if (ph->data->is_dead == 0)
	{
		printf("%lld\t%d\t%s\n", \
		(ft_get_time() - ph->data->time_start), ph->id, str);
	}
	if (pthread_mutex_unlock(&ph->data->time) != 0)
		return ;
	if (pthread_mutex_unlock(&ph->data->dead) != 0)
		return ;
	if (pthread_mutex_unlock(&ph->data->print) != 0)
		return ;
}

int	ft_checkdead(t_data *data, int i)
{
	if (ft_is_dead(&data->ph[i]))
	{
		pthread_mutex_lock(&data->dead);
		data->is_dead = 1;
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	return (0);
}

int	ft_checkmeal(t_data *data, int i)
{
	int	eats;

	if (data->number_of_time_to_eat != -1)
	{
		pthread_mutex_lock(&data->meals);
		eats = data->ph[i].meal_c;
		pthread_mutex_unlock(&data->meals);
		if (eats == data->number_of_time_to_eat)
		{
			data->ph->meal_eat = 1;
			return (1);
		}
	}
	return (0);
}

void	*ft_monitoring(t_data *data)
{
	int			i;
	long long	help;

	while (1 && data->number_of_philo != 1)
	{
		i = 0;
		pthread_mutex_lock(&data->time);
		help = data->ph->current_time;
		pthread_mutex_unlock(&data->time);
		help = ft_get_time();
		while (i < data->number_of_philo)
		{
			if (ft_checkdead(data, i) == 1)
				return (NULL);
			if (ft_checkmeal(data, i) == 1)
			{
				printf("ph: [%d]|id: [%d]\n", data->ph[i].id, data->ph[i].meal_c);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
