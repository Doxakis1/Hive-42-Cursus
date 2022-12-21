/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:05:38 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/21 02:13:07 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		count_split_strings(char const *str, char d, size_t len);
static char		**final1(char **final, const char *str, char c, size_t counter);
static size_t	find_next_length(size_t *num, const char *str, char d);
static char		*n_str(char *final, const char *str, size_t *num, size_t len );

char	**ft_split(char const *s, char c)
{
	size_t	string_len;
	char	**final;
	size_t	string_count;

	string_len = ft_strlen(s);
	string_count = count_split_strings(s, c, string_len);
	final = (char **)malloc(string_count * sizeof(char *) + 1);
	if (final == NULL)
		return (NULL);
	final = final1(final, s, c, string_count);
	return (final);
}

static	int	count_split_strings(char const *str, char delimeter, size_t len)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (len == 0)
		return (count);
	while (i < len)
	{
		while (str[i] == delimeter && i < len)
			i++;
		if (count == 0 && i == len)
			return (0);
		if (count != 0 && i == len)
			count--;
		while (str[i] != delimeter && i < len)
			i++;
		count++;
	}
	return (count);
}

static	char	**final1(char **final, const char *str, char d, size_t counter)
{
	size_t	*buf;
	size_t	j;
	size_t	loop;

	buf = malloc(1);
	loop = 0;
	(*buf) = 0;
	while (loop < counter)
	{
		j = find_next_length(buf, str, d);
		final[loop] = (char *)malloc(j + 1);
		if (!final[loop])
		{
			while (loop > 0)
				free(final[loop--]);
			free(final[0]);
			free(buf);
			return (NULL);
		}
		final[loop] = n_str(final[loop], str, buf, j);
		loop++;
	}
	free(&buf);
	final[loop] = NULL;
	return (final);
}

static	size_t	find_next_length(size_t *num, const char *str, char d)
{
	size_t	final;

	final = 0;
	while (str[(*num)] == d && str[(*num)] != '\0')
	{
		(*num)++;
	}
	if (str[(*num)] == '\0')
		(*num)--;
	while (str[(*num) + final] != d && str[(*num) + final] != '\0')
		final++;
	if (str[(*num) + final - 1] == '\0')
	{
		final--;
	}
	return (final);
}

static	char	*n_str(char *final, const char *str, size_t *num, size_t len)
{	
	size_t	i;

	i = 0;
	while (i < len)
	{
		final[i] = str[(*num) + i];
		i++;
	}
	final[i] = '\0';
	(*num) = (*num) + i;
	return (final);
}
