/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:30 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/19 22:09:25 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long ft_get_time(void)
{
	struct timeval time;
	long long x;
	gettimeofday(&time, NULL);
	x = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (x);
}
//void	ft_print(t_philo *ph, char *str)
//{
//	ph->current_time = ft_get_time() - ph->data->time_start;
//	pthread_mutex_lock(&ph->data->print);
//	if(!ft_is_dead(ph))
//		printf("%lld %d %s\n", ph->current_time, ph->id, str);
//	pthread_mutex_unlock(&ph->data->print);
//}

void	*ft_monitoring(void *arg)
{
	int i;
	t_philo *ph = (t_philo *)arg;
	while(1)
	{
		i = 0;
		while(i < ph->data->number_of_philo)
		{
			if(ft_is_dead(&ph[i]))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
}
