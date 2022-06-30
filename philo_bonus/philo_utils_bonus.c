/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:23:36 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 23:25:24 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(pid_t *pid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
}

int	philo_sleep(long long time, t_philo *philo)
{
	long long	start_time;

	(void) philo;
	start_time = get_time();
	usleep(time * 820);
	while (get_time() - start_time < time)
	{
		usleep(200);
	}
	return (0);
}
