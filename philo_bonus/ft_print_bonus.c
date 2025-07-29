/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:24:56 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/29 10:03:32 by youmoumn         ###   ########.fr       */
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
	if (ph->data->is_dead == 0)
	{
		printf("%lld\t%d\t%s\n", \
		(ft_get_time() - ph->data->time_start), ph->id, str);
	}
}