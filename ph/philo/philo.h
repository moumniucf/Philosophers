/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:30:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/17 10:08:35 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_data
{
	long long		time_todie;
	long long		time_toeat;
	long long		time_tosleep;
	_Atomic int		is_dead;
	pthread_mutex_t	dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	meals;
	pthread_mutex_t	time;
	pthread_mutex_t	finishing;
	pthread_mutex_t	salinae;
	long long		time_start;
	int				number_of_philo;
	int				finish;
	int				number_of_time_to_eat;
	int				salina;
	struct s_philo	*ph;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meal_c;
	_Atomic int		meal_eat;
	long long		last_meal;
	long long		current_time;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
	pthread_t		ts;
	t_data			*data;
}	t_philo;

int			ft_isdigit(int c);
int			ft_isalpha(int c);
void		ft_arg_in(char **av, t_data *da);
int			ft_atoi(char *str);
int			ft_fork_in(t_data *data);
int			ft_philo_in(t_data *data);
int			ft_create_thread(t_data *data);
int			ft_join_thread(t_data *data);
void		*ft_routine_philo(void *arg);
long long	ft_get_time(void);
int			ft_is_dead(t_philo *ph);
void		*ft_monitoring(t_data *data);
void		ft_print(t_data *data, t_philo *ph, char *str);
void		*ft_routine_help(t_philo *ph, t_data *data);
void		ft_help_main(t_data *data);
void		ft_help_time(t_philo *ph, long long time);
void		ft_help_norm_main(t_data *data);
void		cleanup(t_data *data);

#endif