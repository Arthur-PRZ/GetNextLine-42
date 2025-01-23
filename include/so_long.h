/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:32:58 by artperez          #+#    #+#             */
/*   Updated: 2025/01/23 12:23:03 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <X11/keysym.h>
#include <fcntl.h>

typedef struct s_map
{
    char    **grid;
    int     height;
    int     width;
}   t_map;

typedef struct s_playerpos
{
    int height;
    int width;
    int exit;
    int item;
    int pos;
} t_playerpos;

typedef struct s_textures
{
    int   *player;
    int   *exit;
    int   *collectible;
    void   *wall;
    char   *floor;
    int     x;
    int     y;
} t_textures;

typedef struct s_mlx_data
{
    void        *mlx_start;
    void        *mlx_window;
    t_map       map;
    t_playerpos playerpos;
    t_textures  textures;
}   t_mlx_data;

#define HEIGHT 800
#define WIDTH 800

int	ft_strchr_gnl(char *str, char c);
int	handle_input(int keysym, t_mlx_data *ptr);
int	clean_exit(t_mlx_data *ptr);
size_t	count_height();
char	*ft_strjoin0(char const *s1, char const *s2);
void	get_map(t_map *ptrptr, char *map_name);
void	taking_map(char *map_name, t_map *ptr);
int	check_map(t_map *ptr, t_playerpos *pos);
int check_map_close_mid(t_map *ptr);
int	check_map_close(t_map *ptr);
void	check_map_goodway(t_map *ptr, int height, int width, t_playerpos *pos);
int	check_map_size(t_map *ptr);
int	check_map_allelement(t_map *ptr, t_playerpos *variables);
int	check_map_goodelement(t_map *ptr);
void	free_map(t_map *map);
void	free_textures(t_textures *textures, t_mlx_data *mlx_data);
int	createWindow(t_mlx_data	*mlx_data, t_map *map_check);
void	initTextures(t_textures *textures, t_map *map, t_mlx_data *mlx_data);
void	display(t_mlx_data *mlx_data,  t_textures *textures, t_map *map);
void	map_giving(t_map *rmap, t_map *map);
int	check_map_goodway_playerpos(t_map *ptr, t_playerpos *pos);
void	left(t_mlx_data *ptr);
void	right(t_mlx_data *ptr);
void	up(t_mlx_data *ptr);
void	down(t_mlx_data *ptr);
int	    check_map_goodway_items_number(t_map *ptr);






#endif