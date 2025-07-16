/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/16 00:58:27 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int is_oddph(t_data *da)
{
	int i = 0;
	while(i < da->number_of_philo)
	{
		if(da->philo[i].id % 2 == 0)
			return (1);
		i++;
	}
	return (0);
}

int is_dead(t_data *da)
{
	if(da->time_toeat > da->time_tosleep)
		return (1);
	return (0);
}

void	*ft_routine_philo(void *arg)
{
	t_philo *ph = (t_philo *)arg;
	//while(1)
	{
		printf("[%d]\n", ph->id);
		if(ph->id % 2 != 0)
			usleep(1000);
		printf("llllll\n");
		//pthread_mutex_lock(data->philo->l_f);
		//pthread_mutex_lock(data->philo->r_f);
	}
	return NULL;
}
