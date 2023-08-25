/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:53:04 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 05:04:36 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
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
	int			times_to_eat;
	int			times_eaten;
	int			time_last_ate;
	long long	time_last_checked;
}t_parameters;

typedef struct s_fork{
	pthread_mutex_t	fork_lock;
	int				fork_ownership;
}t_fork;

typedef struct s_printer{
	pthread_mutex_t	fork_lock;
	long long		time_since_start;
	long long		current_time;
	char			print_states[5][50];
}t_printer;

typedef struct s_death_state{
	pthread_mutex_t	death_lock;
	int				death;
}t_death_state;

typedef struct s_philo{
	t_parameters	parameters;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_death_state	*death_state;
	t_printer		*printer;
	int				id;
}t_philo;

typedef struct s_monitor{
	int				philo_counter;
	pthread_t		*philo_threads;
	t_fork			*forks;
	t_death_state	*death_state;
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

// intialize_monitor.c
int				initialize_monitor(t_monitor *monitor, long philo_count);

// initialize_philo_threads.c
pthread_t		*initialize_philo_threads(const int philo_count);
int				free_philo_threads(pthread_t *philo_threads);

// initialize_print_states.c
int				initialize_print_states(char print_states[5][50]);

// initialize_forks.c
t_fork			*initialize_forks(const int fork_count);
int				destroy_forks(t_fork	*forks, int index);

// initialize_death_state.c
t_death_state	*initialize_death_state(void);
int				destroy_death_state(t_death_state *death_state);

// initialize_philos.c
int				initialize_philos(long array[5], t_monitor *monitor,
					t_philo **philos);

// retrieve_and_modify.c
void			retrieve_value(pthread_mutex_t *lock, int *value, int *pointer);
void			update_value(pthread_mutex_t *lock, int *old_value,
					int new_value);

// lock_and_unlock_forks.c
void			lock_fork(pthread_mutex_t *lock, int *value, int *id,
					int *ret_value);
void			unlock_fork(pthread_mutex_t *lock, int *value);

// update_time.c
void			update_time(long long *last_time, int *time_last_ate);
void			get_time(long long *dst);

// simulation.c
void			start_simulation(t_monitor *monitor, t_philo **philos);

// philo_loop.c
void			philo_loop(void *data);
void			state_thinking(t_philo *my_data, int *check_death);
void			update_death(t_philo *my_data, int *check_death);

// printing_simulation.c  
void			simulation_printer(int id, int state, t_printer *printer);
void			print_last_message(t_monitor *monitor, int check);

// eating_functions.c
int				get_the_forks(t_philo *my_data, int *check_death);
void			start_eating(t_philo *my_data, int *check_death);

#endif