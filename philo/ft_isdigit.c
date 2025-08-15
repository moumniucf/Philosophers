/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucfdev <ucfdev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:13:35 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/15 20:36:29 by ucfdev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_help_norm_main(t_data *data)
{
	if (ft_fork_in(data) != 0)
	{
		cleanup(data, 1);
		return ;
	}
	if (ft_philo_in(data) != 0)
	{
		cleanup(data, 2);
		return ;
	}
	if (ft_create_thread(data) != 0)
	{
		cleanup(data, 0);
		return ;
	}
}
