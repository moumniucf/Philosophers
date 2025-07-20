/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:30:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/20 13:45:26 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_data
{
	long long time_todie;
	long long time_toeat;
	long long time_tosleep;
	long long time_tothink;
	int is_dead;
	pthread_mutex_t dead;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	long long time_start;
	int number_of_philo;
	int number_of_time_to_eat;
	struct s_philo *ph;
}	t_data;

typedef struct s_philo
{
	int id;
	int meal_c;
	long long last_meal;
	long long current_time;
	pthread_mutex_t *l_f;
	pthread_mutex_t *r_f;
	pthread_t		ts;
	t_data			*data;
} 	t_philo;

int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_arg_in(char **av, t_data *da);
int		ft_atoi(char *str);
void	ft_fork_in(t_data *data);
void	ft_philo_in(t_data *data);
void 	ft_create_thread(t_data *data);
void 	ft_join_thread(t_data *data);
void	*ft_routine_philo(void *arg);
long long	ft_get_time(void);
//void  ft_is_dead(t_philo *ph);
int  ft_is_dead(t_philo *ph);
void	*ft_monitoring(void *arg);
void	ft_print(t_philo *ph, char *str);
int 	is_dead2(t_philo *ph, int x);
