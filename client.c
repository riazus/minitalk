/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:53:34 by jannabel          #+#    #+#             */
/*   Updated: 2021/12/22 21:00:56 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_sig(int pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		write(1, "Error!\n", 8);
		exit (0);
	}
}

void	ft_check_sig(int pid, char ch)
{
	int	i;

	i = 128;
	while (i)
	{
		if (i & ch)
			ft_send_sig(pid, SIGUSR1);
		else
			ft_send_sig(pid, SIGUSR2);
		i /= 2;
		usleep (200);
	}
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

void	ft_sighandler(int sig)
{
	if (sig == SIGUSR2)
		write(1, "Signal receivd!\n", 17);
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc != 3)
	{
		write(1, "Please, write PID and signal!\n", 31);
		exit (0);
	}
	if (!(ft_isdigit_str(argv[1])))
	{
		write(1, "PID should contain only numbers\n", 32);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR2, ft_sighandler);
	while (argv[2][i])
		ft_check_sig(pid, argv[2][i++]);
	ft_check_sig(pid, 10);
}
