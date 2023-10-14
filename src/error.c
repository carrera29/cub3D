/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:35:28 by pollo             #+#    #+#             */
/*   Updated: 2023/10/15 01:48:45 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	error(char *msg, int perror_function)
{
	ft_putstr_fd("[ERROR]\n", STDERR_FILENO);
	if (!perror_function)
		(ft_putstr_fd(msg, STDERR_FILENO), ft_putchar_fd('\n', STDERR_FILENO));
	else
		perror(msg);
	exit(EXIT_FAILURE);
}

int	check_perror(int code, char *name)
{
	if (code == -1)
		perror(name);
	return (code);
}