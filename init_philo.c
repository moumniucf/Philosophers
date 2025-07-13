/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:43:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/13 17:32:40 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	ft_arg_in(char **av, t_data **d)
{
	(*d)->number_of_philo = ft_atoi(av[1]);
	(*d)->time_todie = ft_atoi(av[2]);
	(*d)->time_toeat = ft_atoi(av[3]);
	(*d)->time_tosleep = ft_atoi(av[4]);
	if(av[5])
		(*d)->number_of_time_to_eat = ft_atoi(av[5]);
}

void	ft_fork_in(t_data *ph)
{
	int i = 0;
	ph->fork = malloc(ph->number_of_philo * sizeof(pthread_mutex_t));
	if(!ph->fork)
		return ;
	while(i < ph->number_of_philo)
	{
		pthread_mutex_init(&ph->fork[i], NULL);
		i++;
	}
}
void	*print_f(void *x)
{
	t_philo * ph = (t_philo *)x;
	printf("|%d|\n", ph->id);
	return NULL;
}

void	ft_philo_in(t_data *ph)
{
	int			i;
	
	i = 0;
	ph->philo = malloc(sizeof(t_philo) * ph->number_of_philo);
	if (!(ph->philo))
		return ;
	while (i < ph->number_of_philo)
	{
		ph->philo[i].id = i + 1;
		ph->philo[i].l_f = &ph->fork[i];
		ph->philo[i].r_f = &ph->fork[(i + 1) % ph->number_of_philo];
		ph->philo[i].last_meal = 0;
		ph->philo[i].meal_c = 0;
		i++;
	}
}
void ft_create_thread(t_data *ph)
{
	int i = 0;
	while(i < ph->number_of_philo)
	{
		pthread_create(&(ph->philo[i].ts), NULL, &ft_routine_philo, &ph->philo[i]);
		i++;
	}
}
void ft_join_thread(t_data *ph)
{
	int i = 0;
	while(i < ph->number_of_philo)
	{
		pthread_join(ph->philo[i].ts, NULL);
		i++;
	}
}