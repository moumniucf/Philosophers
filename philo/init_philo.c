/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:43:40 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/31 20:31:38 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_arg_in(char **av, t_data *da)
{
	if (!da)
		return ;
	da->number_of_philo = ft_atoi(av[1]);
	da->time_todie = ft_atoi(av[2]);
	da->time_toeat = ft_atoi(av[3]);
	da->time_tosleep = ft_atoi(av[4]);
	if (av[5])
		da->number_of_time_to_eat = ft_atoi(av[5]);
	else
		da->number_of_time_to_eat = -1;
}

//void	ft_fork_in(t_data *data)
//{
//	int	i;

//	data->fork = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
//	if (!data->fork)
//		return ;
//	i = 0;
//	while (i < data->number_of_philo)
//	{
//		pthread_mutex_init(&data->fork[i], NULL);
//		i++;
//	}
//}

void	ft_philo_in(t_data *data)
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
		data->ph[i].l_f = &data->fork[i];
		data->ph[i].r_f = &data->fork[(i + 1) % data->number_of_philo];
		data->ph[i].data = data;
		i++;
	}
}

void	ft_create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&data->ph[i].ts, NULL, &ft_routine_philo, &data->ph[i]);
		i++;
	}
}

void	ft_join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_join(data->ph[i].ts, NULL) != 0)
			printf("Error\n");
		i++;
	}
}
