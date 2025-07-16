/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:30:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/16 00:34:26 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_philo
{
	int id;
	int meal_c;
	int last_meal;
	pthread_mutex_t *l_f;
	pthread_mutex_t *r_f;
	pthread_t ts;
} 	t_philo;

typedef struct s_data
{
	int time_todie;
	int time_toeat;
	int time_tosleep;
	int time_tothink;
	int is_dead;
	int number_of_philo;
	int number_of_time_to_eat;
	pthread_mutex_t *fork;
	t_philo *philo;
}	t_data;

int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_arg_in(char **av, t_data **p);
int		ft_atoi(char *str);
void	ft_fork_in(t_data *ph);
void	ft_philo_in(t_data *ph);
void 	ft_create_thread(t_data *ph);
void 	ft_join_thread(t_data *ph);
void	*ft_routine_philo(void *arg);
void 	ft_monitoring(t_data *d);
