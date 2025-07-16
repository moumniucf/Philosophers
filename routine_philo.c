/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/16 13:01:04 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int is_oddph(t_philo *ph)
{
	int i = 0;
	while(i < ph->data->number_of_philo)
	{
		if(ph[i].id % 2 == 0)
			return (1);
		i++;
	}
	return (0);
}

//int is_dead(t_data *da)
//{
//	if(da->time_toeat > da->time_tosleep)
//		return (1);
//	return (0);
//}

void	*ft_routine_philo(void *arg)
{
	int i = 0;
	t_philo *ph = (t_philo *)arg;
	while(i < ph->data->number_of_philo)
	{
		printf("[%d]\n", ph->id);
		i++;
	}
	if(ph->id % 2 != 0)
		usleep(1000);
	printf("llllll\n");
	//pthread_mutex_lock(data->philo->l_f);
	//pthread_mutex_lock(data->philo->r_f);
	return NULL;
}
