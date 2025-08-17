/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initphilo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucfdev <ucfdev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:54:21 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/17 01:07:57 by ucfdev           ###   ########.fr       */
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

int	ft_seminit(t_data *da)
{
	sem_unlink("/fork");
	da->fork = sem_open("/fork", O_CREAT, 0664, da->number_of_philo);
	sem_unlink("/print");
	da->print = sem_open("/print", O_CREAT, 0664, 1);
	sem_unlink("/dead");
	da->dead = sem_open("/dead", O_CREAT, 0664, 1);
	sem_unlink("/meal");
	da->meal = sem_open("/meal", O_CREAT, 0664, 1);
	sem_unlink("/time");
	da->time = sem_open("/time", O_CREAT, 0664, 1);
	sem_unlink("/lock_meal");
	da->lock_meal = sem_open("/lock_meal", O_CREAT, 0664, 1);
	if (da->fork == SEM_FAILED || da->print == SEM_FAILED || \
			da->dead == SEM_FAILED || da->meal == SEM_FAILED || \
			da->time == SEM_FAILED || da->lock_meal == SEM_FAILED)
		return (1);
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int			i;
	long long	time;

	data->ph = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->ph)
		return (1);
	i = 0;
	time = ft_get_time();
	while (i < data->number_of_philo)
	{
		data->ph[i].id = i + 1;
		data->ph[i].meal_c = 0;
		data->ph[i].last_meal = time;
		data->ph[i].data = data;
		i++;
	}
	return (0);
}

int	ft_init_pfork(t_data *data)
{
	int	i;
	int	pid;

	i = 0;
	data->pid = malloc(sizeof(pid_t) * data->number_of_philo);
	if (!data->pid)
		return (1);
	while (i < data->number_of_philo)
	{
		pid = fork();
		if (pid == -1)
			return (1);
		data->pid[i] = pid;
		if (data->pid[i] == 0)
		{
			ft_routine_philo(&data->ph[i]);
			exit(0);
		}
		i++;
	}
	return (0);
}
