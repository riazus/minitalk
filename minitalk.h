/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:09:12 by jannabel          #+#    #+#             */
/*   Updated: 2021/12/22 21:12:46 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);

typedef struct g_data
{
	int	bit_cnt;
	int	char_th;
}	t_data;

#endif
