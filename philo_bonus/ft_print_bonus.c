/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:24:56 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/01 18:51:38 by youmoumn         ###   ########.fr       */
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

void	ft_print(t_philo *ph, char *str)
{
	sem_wait(ph->data->time);
	sem_wait(ph->data->dead);
	sem_wait(ph->data->print);
	if (ph->data->is_dead == 0)
	{
		printf("%lld\t%d\t%s\n", \
		(ft_get_time() - ph->data->time_start), ph->id, str);
	}
	sem_post(ph->data->time);
	sem_post(ph->data->dead);
	sem_post(ph->data->print);
}
