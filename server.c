/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:01:07 by jannabel          #+#    #+#             */
/*   Updated: 2021/12/22 21:15:02 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	ft_sighandler(int signum, siginfo_t *sig, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		g_data.char_th += g_data.bit_cnt;
	else
		g_data.char_th += 0;
	g_data.bit_cnt /= 2;
	if (g_data.bit_cnt < 1)
	{
		ft_putchar_fd((unsigned char)g_data.char_th, 1);
		g_data.bit_cnt = 128;
		g_data.char_th = 0;
		kill(sig->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sigact;

	g_data.bit_cnt = 128;
	g_data.char_th = 0;
	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigact.sa_sigaction = ft_sighandler;
	sigact.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sigact, 0);
		sigaction(SIGUSR2, &sigact, 0);
	}
}
