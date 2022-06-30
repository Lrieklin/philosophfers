/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:16:23 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 23:41:30 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init(int argc, char **argv)
{
	t_data		*data;
	long long	time;

	if (argc != 5 && argc != 6)
	{
		write(1, "Not enough input parametrs\n", 28);
		return (1);
	}
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
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	long long	time;

	data = init(argc, argv);
	create_data(data);
	create_philo(data);
	init_mutex(data);
	time = get_time();
	start_threads(data);
	factor(data, argc);
	free_struct(data);
	free_thread(data);
	free(data);
	data = NULL;
}
