#include "philo.h"

int	is_dead(t_philo *philo, int nb)
{
	pthread_mutex_lock(&philo->details->dead);
	if (nb)
		philo->details->alive_status = 1;
	if (philo->details->alive_status)
	{
		pthread_mutex_unlock(&philo->details->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->details->dead);
	return (0);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	sleep_mod(int sleep_time)
{
	long int	time;

	time = get_time();
	while (get_time() - time < sleep_time)
		usleep(sleep_time / 10);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&(philo->details->printer_lock));
	time = get_time() - philo->details->t_start;
	if (!philo->details->alive_status && time >= 0 \
			&& time <= INT_MAX && !is_dead(philo, 0))
		printf("%lld %d %s", get_time() - philo->details->t_start, philo->n, str);
	pthread_mutex_unlock(&(philo->details->printer_lock));
}
