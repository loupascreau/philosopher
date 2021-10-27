/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:50:28 by lpascrea          #+#    #+#             */
/*   Updated: 2021/10/27 17:14:36 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    struct timeval  tv;
    (void)argv;
    (void)argc;

    gettimeofday(&tv, NULL);
    printf("sec = %ld, usec = %ld\n", tv.tv_sec, tv.tv_usec);
    return (0);
}