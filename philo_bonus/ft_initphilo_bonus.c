/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initphilo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:54:21 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/27 18:34:10 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_arg_in(char **av, t_data *da)
{
	if (!da)
		return ;
	(da)->number_of_philo = ft_atoi(av[1]);
	(da)->time_todie = ft_atoi(av[2]);
	(da)->time_toeat = ft_atoi(av[3]);
	(da)->time_tosleep = ft_atoi(av[4]);
	if (av[5])
		(da)->number_of_time_to_eat = ft_atoi(av[5]);
	else
		(da)->number_of_time_to_eat = -1;
}

void	ft_seminit(t_data *da)
{
	sem_unlink("/fork");
	da->fork =  sem_open("/fork", O_CREAT , 0664, da->number_of_philo);
	if(da->fork == SEM_FAILED)
		return;
	sem_unlink("/print");
	da->print =  sem_open("/print", O_CREAT , 0664, 1);
	if(da->print == SEM_FAILED)
		return;
}

void ft_init_fork(t_data *da)
{
	int i = 0;
	da->pid = fork();
	while(i < da->number_of_philo)
	{
		//printf(".....[%d]...|{%d}|\n", da->pid, i);
		i++;
	}
}