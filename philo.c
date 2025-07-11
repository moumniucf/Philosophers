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
pthread_mutex_t g22;

int invalid_nuber(char *s)
{
	int i;
	i = 0;
	if(s[i] == '+')
		i++;
	if(!s[i])
		return (0);
	while(s[i])
	{
		if(!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
int arg_parss(t_data *p)
{
	if(!p || p->number_of_philo <= 0 || p->time_todie < 0 || p->time_toeat < 0 || p->time_tosleep < 0\
	|| p->time_tothink < 0)
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	int i;
	i = 1;
	t_data *d;
	d = ft_arg_in(av, d);
	struct timeval p;
	if((ac - 1) > 5)
	{
		printf("Error\n");
		return (1);
	}
	while(i < ac)
	{
		if(!invalid_nuber(av[i]))
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	ft_fork_in(d);
	ft_philo_in(d);
	printf("---%d\n", d->number_of_philo);
	printf("---%d\n", gettimeofday(&p, NULL));
}
