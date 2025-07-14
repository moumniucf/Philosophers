/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:30 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/14 17:28:03 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void ft_monitoring(t_data *d)
//{
//	(void)d;
//	struct timeval x;
//	printf("|%d|\n", gettimeofday(&x, NULL));
//}
#include <sys/time.h>
#include <stdio.h>

long	get_current_time_ms(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_monitoring(t_data *d)
{
	(void)d;
	printf("|%ld|\n", get_current_time_ms());
}
