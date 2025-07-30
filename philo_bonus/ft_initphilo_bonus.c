/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initphilo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:54:21 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/30 12:57:43 by youmoumn         ###   ########.fr       */
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
	sem_unlink("/print");
	sem_unlink("/dead");
	da->fork =  sem_open("/fork", O_CREAT , 0664, da->number_of_philo);
	da->print =  sem_open("/dead", O_CREAT , 0664, 1);
	da->print =  sem_open("/print", O_CREAT , 0664, 1);
	if(da->fork == SEM_FAILED || da->print == SEM_FAILED || da->dead == SEM_FAILED)
		return;
}

void	ft_init_philo(t_data *data)
{
	int	i;

	data->ph = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->ph)
		return ;
	i = 0;
	while (i < data->number_of_philo)
	{
		data->ph[i].id = i + 1;
		data->ph[i].meal_c = 0;
		data->ph[i].last_meal = 0;
		data->ph[i].data = data;
		i++;
	}
}

void	ft_init_pfork(t_data *data)
{
	int i = 0;
	data->pid = malloc(sizeof(pid_t) * data->number_of_philo);
	if(!data->pid)
		return ;
	while(i < data->number_of_philo)
	{
		data->pid[i] = fork();
		if(data->pid[i] == 0)
		{
			ft_routine_philo(&data->ph[i]);
			exit(0);
		}
		i++;
	}
}
