/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:04:05 by lpascrea          #+#    #+#             */
/*   Updated: 2021/11/09 16:05:52 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_digit(char *arg)
{
	int		i;
	int		nb;

	i = 0;
	nb = ft_atoi(arg);
	if (nb <= 0)
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(char **argv, int argc)
{
	int		i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (ft_argc_error(argc));
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (ft_invalid_arg(argv[i]));
		i++;
	}
	return (1);
}
