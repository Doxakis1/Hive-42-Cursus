#include "philo.h"

void	*death_thread(void *philo_details)
{
	t_philo	*philo;

	philo = (t_philo *)philo_details;
	sleep_mod(philo->details->time_to_die + 1);
	pthread_mutex_lock(&philo->details->eat_lock);
	pthread_mutex_lock(&philo->details->death_lock);
	if (!is_dead(philo, 0) && get_time() - \
			philo->lastime_to_eat >= (long)(philo->details->time_to_die))
	{
		pthread_mutex_unlock(&philo->details->eat_lock);
		pthread_mutex_unlock(&philo->details->death_lock);
		print(philo, " died\n");
		is_dead(philo, 1);
	}
	pthread_mutex_unlock(&philo->details->eat_lock);
	pthread_mutex_unlock(&philo->details->death_lock);
	return (NULL);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	print(philo, " has taken a fork\n");
	if (philo->details->philo_count == 1)
	{
		sleep_mod(philo->details->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock((philo->fork_r));
	print(philo, " has taken a fork\n");
}

void	philo_eat(t_philo *philo)
{
	print(philo, " is eating\n");
	pthread_mutex_lock(&(philo->details->eat_lock));
	philo->lastime_to_eat = get_time();
	philo->m_count++;
	pthread_mutex_unlock(&(philo->details->eat_lock));
	sleep_mod(philo->details->time_to_eat);
	pthread_mutex_unlock((philo->fork_r));
	pthread_mutex_unlock(&(philo->fork_l));
	print(philo, " is sleeping\n");
	sleep_mod(philo->details->time_to_sleep);
	print(philo, " is thinking\n");
}

void	*philo_loop(void *phi)
{
	t_philo		*philo;
	pthread_t	t;

	philo = (t_philo *)phi;
	if (philo->n % 2 == 0)
		sleep_mod(philo->details->time_to_eat / 10);
	while (!is_dead(philo, 0))
	{
		pthread_create(&t, NULL, death_thread, phi);
		take_fork(philo);
		philo_eat(philo);
		pthread_detach(t);
		if (philo->m_count == philo->details->times_eaten)
		{
			pthread_mutex_lock(&philo->details->death_lock);
			if (++philo->details->philo_eat == philo->details->philo_count)
			{
				pthread_mutex_unlock(&philo->details->death_lock);
				is_dead(philo, 2);
			}
			pthread_mutex_unlock(&philo->details->death_lock);
			return (NULL);
		}
	}
	return (NULL);
}
