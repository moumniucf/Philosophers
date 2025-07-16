/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:43:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/16 13:01:20 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	ft_arg_in(char **av, t_philo **d)
{
	if(!(*d) || !d)
		return ;
	(*d)->data->number_of_philo = ft_atoi(av[1]);
	(*d)->data->time_todie = ft_atoi(av[2]);
	(*d)->data->time_toeat = ft_atoi(av[3]);
	(*d)->data->time_tosleep = ft_atoi(av[4]);
	if(av[5])
		(*d)->data->number_of_time_to_eat = ft_atoi(av[5]);
	else
		(*d)->data->number_of_time_to_eat = -1;
}

void	ft_fork_in(t_philo *ph)
{
	int i = 0;
	ph->fork = malloc(ph->data->number_of_philo * sizeof(pthread_mutex_t));
	if(!ph->fork)
		return ;
	while(i < ph->data->number_of_philo)
	{
		pthread_mutex_init(&ph->fork[i], NULL);
		i++;
	}
}
void	*print_f(void *x)
{
	t_philo * ph = (t_philo *)x;
	printf("-|%d|-\n", ph->id);
	return NULL;
}

void	ft_philo_in(t_philo *philo, t_data *data)
{
	int			i;
	
	philo = malloc(sizeof(t_philo) * (data->number_of_philo));
	if (!philo)
		return ;
	i = 0;
	while (i < data->number_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].l_f = &philo->fork[i];
		philo[i].r_f = &philo->fork[(i + 1) % data->number_of_philo];
		philo[i].last_meal = 0;
		philo[i].meal_c = 0;
		i++;
	}
}
void ft_create_thread(t_philo *ph)
{
	int i = 0;
	while(i < ph->data->number_of_philo)
	{
		pthread_create(&(ph[i].ts), NULL, &ft_routine_philo, &ph[i]);
		i++;
	}
}
void ft_join_thread(t_philo *ph, t_data *data)
{
	int i = 0;
	while(i < data->number_of_philo)
	{
		pthread_join((ph->ts), NULL);
		i++;
	}
}