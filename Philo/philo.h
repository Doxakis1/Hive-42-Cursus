#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				n;
	int				m_count;
	bool			is_eating;
	pthread_t		thread;
	long int		lastime_to_eat;
	struct s_details	*details;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}		t_philo;

typedef struct s_details
{
	int				philo_eat;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_eaten;
	int				alive_status;
	long int		t_start;
	t_philo			*philo;
	pthread_mutex_t	printer_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	dead;
}		t_details;

int			check_invalid_arguments(int argc,
			char **argv, long *inputarray);
int			print_args_error(void);
int			print_error(const char *str);
int			print_loner_error(void);
void		sleep_mod(int sleep_time);
int			initialize_philo(t_details *details);
void		*philo_loop(void *philo);
long long	get_time(void);
int			initialize_simulation(t_details *details, long *numbers);
void		print(t_philo *philo, char *str);
int			is_dead(t_philo *philo, int nb);

#endif
