/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:53:04 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 05:38:49 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# define ALIVE 0
# define NOT_ALIVE 1
# define TOOK_FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4
# define HALT 0
# define RESUME 1 

typedef struct s_parameters{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_eaten;
	long long	time_last_ate;
}t_parameters;

typedef struct s_fork{
	pthread_mutex_t	fork_lock;
	int				fork_ownership;
}t_fork;

typedef struct s_printer{
	pthread_mutex_t	printer_lock;
	long long		time_since_start;
	long long		current_time;
	short			alive;
	char			print_states[5][50];
}t_printer;

typedef struct s_philo{
	t_parameters	parameters;
	t_fork			*fork_two;
	t_fork			*fork_one;
	t_printer		*printer;
	pthread_mutex_t death_lock;
	pthread_mutex_t eaten_lock;
	int				id;
	short			alive;
}t_philo;

typedef struct s_monitor{
	int				philo_counter;
	int				times_eaten_done;
	pthread_t		*philo_threads;
	t_fork			*forks;
	t_printer		printer;
}t_monitor;

// ft_atou_to_dest.c
int				ft_atou_to_dest(const char *str, long *dst, int sign);

// print_errors.c
int				print_args_error(void);
int				print_monitor_error(void);
int				print_philo_creation_error(void);
int				print_loner_error(void);

// check_invalid_arguments.c
int				check_invalid_arguments(int argc, char const *argv[],
					long *inputarray);

// get_time.c
long long		get_time(void);

// initialize_monitor.c
int				initialize_monitor(t_monitor *monitor, long philo_count, int times_to_eat);

// initialize_print_states.c  
int				initialize_print_states(char print_states[5][50]);

// initialize_philo_threads.c 
pthread_t		*initialize_philo_threads(const int philo_count);

// initialize_forks.c
t_fork			*initialize_forks(const int fork_count);
int				destroy_forks(t_fork	*forks, int index);

// initialize_philo_threads.c
pthread_t		*initialize_philo_threads(const int philo_count);
int				free_philo_threads(pthread_t	*philo_threads);

// initialize_philos.c
int				initialize_philos(long array[5], t_monitor *monitor,
					t_philo **philos);

// simulation.c
void			start_simulation(t_monitor *monitor, t_philo *philos);

// philo_loop.c
void			*philo_loop(void *data);

//philo_loop_helpers.c
int				check_death(t_philo *my_data);
void			sleep_mod(t_philo *my_data, long long time_to_sleep);

#endif