/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:49:48 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 14:50:25 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->data->print);
	printf("%lld %d %s", get_time() - philo->data->time_start, philo->id, str);
	pthread_mutex_unlock(philo->data->print);
}