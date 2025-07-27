/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:52:42 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/27 23:52:31 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>

typedef struct s_data
{
	long long			time_todie;
	long long			time_toeat;
	long long			time_tosleep;
	long long			time_tothink;
	int					is_dead;
	int					one;
	//pthread_mutex_t		dead;
	sem_t				*fork;
	sem_t				*print;
	//pthread_mutex_t		print;
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
	long long			last_meal;
	long long			current_time;
	//pthread_mutex_t		*l_f;
	//pthread_mutex_t		*r_f;
	pthread_t			ts;
	t_data				*data;
}	t_philo;

int	ft_atoi(char *str);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
void	ft_arg_in(char **av, t_data *da);
void	ft_print(t_philo *ph, char *str);
void	ft_help_time(long long time);
void	ft_init_philo(t_data *da);
void	ft_seminit(t_data *da);
void	*ft_routine_philo(void *arg);
void	ft_init_pfork(t_data *data);
#endif