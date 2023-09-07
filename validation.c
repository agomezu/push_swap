/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:46:07 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/05 19:52:07 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
					return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	validate_input(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		// printf("Validation input: %s\n", argv[i]);
		if (!is_integer(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	// printf("Checking for duplicates...\n");
	if (has_duplicates(argc, argv))
		return (0);
	// printf("Validation successful.\n");
	return (1);
}
