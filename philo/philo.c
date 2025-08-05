/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:30:18 by youmoumn          #+#    #+#             */
/*   Updated: 2025/06/28 12:19:52 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	invalid_nuber(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parss_2(t_data *da)
{
	if (da->time_todie < 60 || da->time_toeat < 60 || da->time_tosleep < 60)
		return (1);
	return (0);
}

int	arg_parss(t_data *p)
{
	if (!p || p->number_of_philo <= 0 || p->time_todie < 0 || \
	p->time_toeat < 0 || p->time_tosleep < 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = 1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_arg_in(av, data);
	if (ac < 5 || ac > 6 || data->number_of_philo > 200 || \
	parss_2(data) || data->number_of_time_to_eat == 0 || \
	data->number_of_philo == 0 || (av[5] && ft_atoi(av[5]) <= 0))
	{
		return (printf("Error\n"), free(data), 1);
	}
	while (i < ac)
	{
		if (invalid_nuber(av[i]) == 0)
		{
			return (printf("Error\n"), free(data), 1);
		}
		i++;
	}
	ft_help_main(data);
	return (0);
}
