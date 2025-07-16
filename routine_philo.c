/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/16 18:05:46 by youmoumn         ###   ########.fr       */
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
//int ft_is_diad(t_data *data)
//{
//	if(data.t)
//}
void	*ft_routine_philo(void *arg)
{
	t_philo *ph = (t_philo *)arg;
	if(ph->id % 2 != 0)
		usleep(1000);
	else
	{
		printf("%d has taken a fork\n", ph->id);
		pthread_mutex_lock(ph->l_f);
		pthread_mutex_lock(ph->r_f);
		printf("%d is eating\n", ph->id);
		usleep(ph->data->time_toeat);
		printf("%d is thinking\n", ph->id);
		usleep(ph->data->time_tothink);
	}
	return NULL;
}
