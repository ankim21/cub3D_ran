/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:57:41 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 12:56:55 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

//General
# define FAIL_MAL "Memory allocation went wrong\n"

//Arguments errors
# define NB_ARGS "Wrong number of arguments\n"
# define EXT "Wrong file name\n"
# define MAP_OPEN "Cannot open map file\n"

//Map erros
# define EMPTY_FILE "The file is empty\n"
# define NO_MAP "The map is missing\n"
# define SIZ_MAP "Map size is incorrect\n"
# define NO_PATH "Texture path is missing\n"
# define W_PATH "Texture path is wrong somehow\n"
# define CODE_COL "Color code is wrong somehow\n"
# define MISSING_INFO "Someting is missing\n"
# define INV_PARAM "Invalid settings in file\n"
# define DOUBLE "Some infos are doubled\n"
# define GARB "There is some garbage in your file\n"
# define PLAYER "There is not exactly one player\n"
# define MISS_WALLS "This map isn't enclosed by wall\n"
# define EMPTY_LINE "There shouldn't be empty lines in your map\n"

//MLX
# define MLX_INIT "Couldn't launch the mlx\n"
# define MLX_WIN "Couldn't open the window\n"
# define ERR_IMG_LOAD "Couldn't load the image\n"

#endif