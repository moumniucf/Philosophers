/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:30 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/18 23:27:20 by youmoumn         ###   ########.fr       */
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
