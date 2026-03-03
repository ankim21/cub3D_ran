/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_file_infos_colors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:16 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 14:24:48 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	get_color(char *s)
{
	int	i;
	int	res;

	i = 0;
	while (s && s[i])
	{
		if (!ft_isdigit(s[i]))
			return (-1);
		i++;
	}
	res = ft_atoi(s);
	if (res > 255 || res < 0)
		return (-1);
	return (res);
}

static bool	check_valid_splitted_color(char **split_color, int *color)
{
	int	i;

	i = 0;
	if (!split_color || !split_color[i])
		return (FALSE);
	while (split_color[i])
		i++;
	if (i != 3)
		return (FALSE);
	i = 0;
	while (i < 3)
	{
		color[i] = get_color(split_color[i]);
		if (color[i] == -1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_comas(char **split_copy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (split_copy && split_copy[1] && split_copy[1][i])
	{
		if (split_copy[1][i] == ',')
		{
			j++;
			split_copy[1][i] = ' ';
		}
		i++;
	}
	return (j);
}

static bool	check_valid_color(char **split_copy, int *color)
{
	int		coma;
	char	*str_color;
	char	**split_color;

	coma = 0;
	if (split_copy && !split_copy[1])
		return (FALSE);
	coma = check_comas(split_copy);
	if (coma != 2)
		return (FALSE);
	if (!split_copy[0] || split_copy[2])
		return (FALSE);
	str_color = ft_strdup(split_copy[1]);
	if (!str_color)
		return (print_error(FAIL_MAL), FALSE);
	split_color = ft_split(str_color);
	free(str_color);
	if (!check_valid_splitted_color(split_color, color))
		return (free_2d_array(split_color), FALSE);
	return (free_2d_array(split_color), TRUE);
}

bool	check_color_line(char **split_copy, t_game *game)
{
	int	i;

	i = 0;
	while (split_copy && split_copy[1] && split_copy[1][i])
	{
		if (!ft_isdigit(split_copy[1][i]) && split_copy[1][i] != ',')
			return (print_error(CODE_COL), FALSE);
		i++;
	}
	if (!ft_strcmp(split_copy[0], "C"))
	{
		if (!check_valid_color(split_copy, game->assets.ceiling))
			return (print_error(CODE_COL), FALSE);
		game->assets.ceiling_flag = 1;
	}
	if (!ft_strcmp(split_copy[0], "F"))
	{
		if (!check_valid_color(split_copy, game->assets.floor))
			return (print_error(CODE_COL), FALSE);
		game->assets.floor_flag = 1;
	}
	return (TRUE);
}
