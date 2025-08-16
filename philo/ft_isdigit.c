/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:13:35 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/16 11:04:15 by youmoumn         ###   ########.fr       */
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
		cleanup(data);
		return ;
	}
	if (ft_philo_in(data) != 0)
	{
		cleanup(data);
		return ;
	}
	if (ft_create_thread(data) != 0)
	{
		cleanup(data);
		return ;
	}
}
