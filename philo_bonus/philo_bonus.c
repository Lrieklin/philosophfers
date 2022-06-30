/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:18:32 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 23:29:39 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_eat(void *d)
{
	t_data	*data;
	int		i;

	data = (t_data *)d;
	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		sem_wait(data->eat);
		i++;
	}
	kill_all(data->pid, i);
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->status);
	sem_close(data->eat);
	unlink("philo_forks110");
	unlink("philo_print110");
	unlink("philo_status110");
	unlink("philo_eat110");
	exit(i);
	return (NULL);
}

t_data	*init_data(int argc, char **argv)
{
	t_data		*data;

	data = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->rules = NULL;
	data->rules = (t_rules *)malloc(sizeof(t_rules));
	if (!data->rules)
		return (1);
	create_rules(argv, data->rules, argc);
	create_data(data);
	init_philo(data);
	return (data);
}

int	main(int argc, char **argv)
{
	long long	time;
	t_data		*data;

	if (argc != 5 && argc != 6)
	{
		write(1, "Not enough input parametrs\n", 28);
		return (1);
	}
	data = init_data(argc, argv);
	time = get_time();
	launch(data);
	pthread_create(&data->thread, NULL, check_eat, (void *)data);
	pthread_detach(data->thread);
	wait(NULL);
	kill_all(data->pid, data->rules->number_of_philosophers);
	exit(0);
}
