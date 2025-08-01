/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:09:19 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/01 21:17:43 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	p->time_toeat < 0 || p->time_tosleep < 0 || p->time_tothink < 0)
		return (0);
	return (1);
}

void	ft_lk(void)
{
	system("leaks philo");
}

int	ft_check_args(int ac, char **av, t_data *data)
{
	int	i;

	if (ac < 5 || ac > 6 || data->number_of_philo > 200 || parss_2(data))
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!invalid_nuber(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_run_simulation(t_data *data)
{
	ft_init_philo(data);
	ft_seminit(data);
	data->time_start = ft_get_time();
	ft_init_pfork(data);
	ft_waitp(data);
	ft_close_sem(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_arg_in(av, data);
	if (!ft_check_args(ac, av, data))
	{
		printf("Error\n");
		free(data);
		return (1);
	}
	ft_run_simulation(data);
	free(data->pid);
	free(data->ph);
	free(data);
	return (0);
}
