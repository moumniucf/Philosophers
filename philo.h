/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:30:04 by youmoumn          #+#    #+#             */
/*   Updated: 2025/07/11 13:01:59 by youmoumn         ###   ########.fr       */
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
	int time_todie;
	int time_toeat;
	int time_tosleep;
	int time_tothink;
	int number_of_philo;
	int number_of_time_to_eat;
	pthread_mutex_t *fork;
}	t_data;

typedef struct s_philo
{
	int id;
	int meal_c;
	int last_meal;
	pthread_mutex_t *l_f;
	pthread_mutex_t *r_f;
	t_data *data;
} 	t_philo;

int		ft_isdigit(int c);
int		ft_isalpha(int c);
t_data	*ft_arg_in(char **av, t_data *p);
int		ft_atoi(char *str);
void	ft_fork_in(t_data *ph);
void	*routine_philo();
void	ft_philo_in(t_data *ph);