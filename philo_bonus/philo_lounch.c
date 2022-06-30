/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lounch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:04:18 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 15:11:05 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	lounch(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
		else if (data->pid[i] > 0)
		// родительский поток, идем в main
		else (data->pid[i] == 0)
			philo_lounch(&data->philos[i]);
	}
	return (0);
}

void	philo_lounch(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		sem_wait(philo->forks);
		print("has taken a fork\n", philo);
		sem_wait(philo->forks);
		print("has taken a fork\n", philo);
		print("is eating\n", philo);
		sem_wait(philo->data->status);
		philo_sleep(philo->rules->time_to_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		sem_wait(philo->data->status);
		philo->count_eat += 1;
		sem_post(philo->data->status);
		print("is sleeping\n", philo);
		philo_sleep(philo->rules->time_to_sleep);
		print("is thinking\n", philo);
	}
}

long long	get_time()
{
	struct timeval	time;
	long long		ml_sec;

	gettimeofday(&time, NULL);
	ml_sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ml_sec);
}

void	philo_sleep(long long time)
{
	long long	start_time;

	start_time = get_time();
	usleep(time * 800);
	while (get_time() - start_time <= time)
	{
		usleep(200);
	}
}
