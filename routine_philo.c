/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:50:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/14 11:39:25 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_data *da)
{
	if(da->time_toeat > da->time_tosleep)
		return (1);
	return (0);
}

void	*ft_routine_philo(void *arg)
{
	//int i = 0;
	t_data *data = (t_data *)arg;
	//(void)data;
	printf("+%d+\n", data->number_of_philo);
	printf("-%d-\n", is_dead(data));
	//while(i < data->number_of_philo)
	//{
	//	i++;
	//}
	return NULL;
}