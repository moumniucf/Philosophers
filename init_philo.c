/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:43:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/11 18:40:22 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
t_data	*ft_arg_in(char **av, t_data *p)
{
	t_data	*d;
	d = p;
	
	d = malloc(sizeof(t_data));
	if(!d)
		return (NULL);
	d->number_of_philo = ft_atoi(av[1]);
	d->time_todie = ft_atoi(av[2]);
	d->time_toeat = ft_atoi(av[3]);
	d->time_tosleep = ft_atoi(av[4]);
	if(av[5])
		d->number_of_time_to_eat = ft_atoi(av[5]);
	return (d);
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

void	ft_philo_in(t_data *ph)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = malloc(sizeof(t_philo) * ph->number_of_philo);
	if (!philo)
		return ;
	while (i < ph->number_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].l_f = &ph->fork[i];
		philo[i].r_f = &ph->fork[(i + 1) % ph->number_of_philo];
		philo[i].last_meal = 0;
		philo[i].meal_c = 0;
		printf("Philo[%d]: left = %p, right = %p\n", philo[i].id, philo[i].l_f, philo[i].r_f);
		i++;
	}
}
