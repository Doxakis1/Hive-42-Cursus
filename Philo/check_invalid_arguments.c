#include "philo.h"

static int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

static int	ft_atou_to_dest(const char *str, long *dst, int sign)
{
	int	i;

	i = 0;
	*(dst) = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9'
			&& *(dst) <= 2147483648)
			*(dst) = *(dst) * 10 + str[i] - '0';
		if (!ft_isdigit(str[i]) || (*(dst) >= 2147483648) || sign < 1)
		{
			*(dst) = 2147483648;
			return (1);
		}
		i++;
	}
	if (*(dst) == 0)
		return (1);
	return (0);
}

int	check_invalid_arguments(int argc, char *argv[], long *inputarray)
{
	int	loop_counter;

	loop_counter = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (argc == 5)
		inputarray[4] = -1;
	while (++loop_counter < argc)
	{
		if (ft_atou_to_dest(argv[loop_counter], &inputarray[loop_counter - 1],
				1))
			return (1);
	}
	return (0);
}
