/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:52:42 by youmoumn          #+#    #+#             */
/*   Updated: 2025/08/09 15:56:06 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>

typedef struct s_data
{
	long long			time_todie;
	long long			time_toeat;
	long long			time_tosleep;
	int					is_dead;
	sem_t				*dead;
	sem_t				*fork;
	sem_t				*print;
	sem_t				*meal;
	sem_t				*time;
	sem_t				*lock_meal;
	long long			time_start;
	pid_t				*pid;
	int					number_of_philo;
	int					number_of_time_to_eat;
	struct s_philo		*ph;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					meal_c;
	int					meal_eat;
	_Atomic long long	last_meal;
	long long			current_time;
	pthread_t			ts;
	t_data				*data;
}	t_philo;

int			ft_atoi(char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
void		ft_arg_in(char **av, t_data *da);
void		ft_print(t_philo *ph, char *str);
//void		ft_help_time(long long time);
void	ft_help_time(t_philo *ph, long long time);
void		ft_init_philo(t_data *da);
void		ft_seminit(t_data *da);
void		*ft_routine_philo(t_philo *ph);
void		ft_init_pfork(t_data *data);
void		*ft_routine_help(t_philo *ph);
long long	ft_get_time(void);
int			ft_is_dead(t_philo *ph);
void		*ft_monitoring(void *arg);
void		ft_print(t_philo *ph, char *str);
void		ft_close_sem(t_data *data);
void		ft_waitp(t_data *da);
int			ft_run_simulation(t_data *data);
void		ft_kill_all(t_data *data);
#endif