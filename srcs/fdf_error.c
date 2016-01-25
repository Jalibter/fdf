/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:32:13 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/20 18:17:53 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				arg_error(void)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("Nombre d'argument invalide.\n", 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}

void				malloc_error(void)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("Une erreur est survenue lors d'une allocation memoire.\n", 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}

void				open_error(char *file)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("Une erreur est survenue lors de l'ouverture du fichier ", 2);
	ft_putstr_fd("\033[33m", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(".", 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}

void				map_error(void)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("Une erreur est survenue lors de la lecture d'une map.\n", 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}
