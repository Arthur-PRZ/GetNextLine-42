/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:34:59 by artperez          #+#    #+#             */
/*   Updated: 2025/01/23 12:27:23 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keysym, t_mlx_data *ptr)
{
	ptr->map.width = ft_strlen(ptr->map.grid[0]);
	check_map_goodway_playerpos(&ptr->map, &ptr->playerpos);
	if (keysym == XK_Escape)
		clean_exit(ptr);
	if (keysym == 97)
		left(ptr);
	if (keysym == 115)
		down(ptr);
	if (keysym == 100)
		right(ptr);
	if (keysym == 119 )
		up(ptr);
	ft_printf("%i\n", keysym);
	return (0);
}

void	left(t_mlx_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width - 1] == 'E'
		&& check_map_goodway_items_number(&ptr->map) == ptr->playerpos.item)
		clean_exit(ptr);
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width - 1] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width - 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = 'E';
		display(ptr, &ptr->textures, &ptr->map);
		ptr->playerpos.exit = 0;
	}
	else if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width - 1] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width - 1] == 'E')
			ptr->playerpos.exit = 1;
		if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width - 1] == 'E')
			ptr->playerpos.item++;
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width - 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = '0';
		display(ptr, &ptr->textures, &ptr->map);
	}
}

void	right(t_mlx_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width + 1] == 'E'
		&& check_map_goodway_items_number(&ptr->map) == ptr->playerpos.item)
		clean_exit(ptr);
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width + 1] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width + 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = 'E';
		display(ptr, &ptr->textures, &ptr->map);
		ptr->playerpos.exit = 0;
	}	
	else if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width + 1] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width + 1] == 'E')
			ptr->playerpos.exit = 1;
		if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width + 1] == 'C')
			ptr->playerpos.item++;
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width + 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = '0';
		display(ptr, &ptr->textures, &ptr->map);
	}
}
void	up(t_mlx_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.width] == 'E'
		&& check_map_goodway_items_number(&ptr->map) == ptr->playerpos.item)
		clean_exit(ptr);
	if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.width] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.width] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = 'E';
		display(ptr, &ptr->textures, &ptr->map);
		ptr->playerpos.exit = 0;
	}	
	else if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.width] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.width] == 'E')
			ptr->playerpos.exit = 1;
		if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.width] == 'C')
			ptr->playerpos.item++;
	 	ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.width] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = '0';
		display(ptr, &ptr->textures, &ptr->map);
	}
}

void	down(t_mlx_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.width] == 'E'
		&& check_map_goodway_items_number(&ptr->map) == ptr->playerpos.item)
		clean_exit(ptr);
	if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.width] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.width] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = 'E';
		display(ptr, &ptr->textures, &ptr->map);
		ptr->playerpos.exit = 0;
	}
	else if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.width] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.width] == 'E')
			ptr->playerpos.exit = 1;
		if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.width] == 'C')
			ptr->playerpos.item++;
		ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.width] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.width] = '0';
			display(ptr, &ptr->textures, &ptr->map);
	}
}

int	clean_exit(t_mlx_data *ptr)
{
	mlx_destroy_window(ptr->mlx_start, ptr->mlx_window);
	mlx_destroy_display(ptr->mlx_start);
	free(ptr->mlx_start);
	exit(0);
}

// int	count_height()
// {
// 	char	*line;
// 	int		height;
// 	int		file;
	
// 	hesight = 0;
// 	file = open("/map/map.ber", O_RDONLY);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(file);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 		height++;
// 	}
// 	if (height < 3)
// 	{
// 		free(line);
// 		close(file);
// 		return (-1);
// 	}
// 	close(file);
// 	return (height);
// }

size_t	count_height(char *map_name)
{
	int		readbytes;
	char	*buf;
	size_t		height;
	int		file;
	
	height = 1;
	readbytes = 1;
	buf = malloc(sizeof(char) * 3);	
	if (buf == NULL)
		return (0);
	buf[2] = '\0';
	file = open(map_name, O_RDONLY);
	if (file == -1)
		return (0);
	while (readbytes != 0)
	{
		readbytes = read(file, buf, 2);
		if (readbytes == -1)
			return (free(buf), close(file), 0);
		if (ft_strchr_gnl(buf, '\n') == 1)
			height++;
	}
	free(buf);
	close (file);
	return (height);
}

char	*ft_strjoin0(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	free((char *)s1);
	while (s2[a] != '\0')
	{
		str[i] = s2[a];
		i++;
		a++;
	}
	if (str[i - 1] == '\n')
		str[i - 1] = '\0'; 
	str[i] = '\0';
	return (str);
}
void	get_map(t_map *ptrptr, char *map_name)
{
	char	*line;
	int		file;
	int		i;

	i = 0;
	file = open(map_name, O_RDONLY);
	if (file == -1)
		return ;
	while (i < ptrptr->height)
	{
		ptrptr->grid[i] = calloc(1, sizeof(char));
		line = get_next_line(file);
		ptrptr->grid[i] = ft_strjoin0(ptrptr->grid[i], line);
		i++;
		free(line);
	}
	close(file);
}

void	taking_map(char *map_name, t_map *ptr)
{
	ptr->height = count_height(map_name);
	ptr->grid = malloc(sizeof(char *) * ptr->height);
	get_map(ptr, map_name);
	// while (line !=)
	// {
	// 	line = get_next_line("/map/map.ber")
	// 	map[i] = line;
	// 	i++;
	// }
	// if (map == NULL)
	return ;	
	
}
int	check_map_name(char *map_name)
{
	int	i;
	int	len;
	
	i = ft_strlen(map_name);
	len = ft_strlen(map_name);
	while (i > 0)
	{
		if (map_name[i] == '.')
		{
			if (ft_strncmp(ft_strnstr(map_name + i, ".ber", 5), ".ber", len) == 0)
				return (0);
		}
		i--;
	}
	return (1);
}

int	check_map_size(t_map *ptr)
{
	int		i;
	size_t	len;
	
	i = 0;
	len = ft_strlen(ptr->grid[i]);
	while (i != ptr->height)
	{
		if (len != ft_strlen(ptr->grid[i]))
			return (1);
		i++;
	}
	ptr->width = len;
	return (0);
}

int check_map_close_mid(t_map *ptr)
{
	int	i;
	
	i = 1;
	while (i < ptr->height - 1)
	{
		if (ptr->grid[i][0] != '1' || ptr->grid[i][ptr->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
int	check_map_close(t_map *ptr)
{
	int	i;
	
	i = 0;
	while (i < ptr->width)
	{
		if (ptr->grid[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < ptr->width)
	{
		if (ptr->grid[ptr->height - 1][i] != '1')
			return (1);
		i++;
	}
	if (check_map_close_mid(ptr) == 1)
		return (1);
	return (0);
}
int	check_map_goodway_playerpos(t_map *ptr, t_playerpos *pos)
{
	int	i;
	int	a;
	
	i = 0;
	a = 0;
	while(ptr->grid[a][i] != 'P')
	{
		i++;
		if (i > ptr->width)
		{
			i = 0;
			a++;
		}
	}
	pos->width = i;
	pos->height = a;
	pos->item = 0;
	return (0);
}

int	check_map_allelement(t_map *ptr, t_playerpos *variables)
{
	int	i;
	int	a;
	
	i = 0;
	a = 0;
	variables->exit = 0;
	variables->pos = 0;
	while(a < ptr->height)
	{
		if (ptr->grid[a][i] == 'E')
			variables->exit++;
		if (ptr->grid[a][i] == 'C')
			variables->item = 1;
		if (ptr->grid[a][i] == 'P')
			variables->pos++;
		i++;
		if(i == ptr->width - 1)
		{
			i = 0;
			a++;
		}
	}
	if (variables->exit == 1 && variables->item == 1 && variables->pos == 1)
		return (0);
	return (1);
}

int	check_map_goodelement(t_map *ptr)
{
	int i;
	int	a;
	
	i = 0;
	a = 0;
	while (a < ptr->height)
	{
		if (ptr->grid[a][i] != '1' && ptr->grid[a][i] != '0' 
		&& ptr->grid[a][i] != 'E' && ptr->grid[a][i] != 'C' 
		&& ptr->grid[a][i] != 'P')
			return (1);
		i++;
		if(i == ptr->width - 1)
		{
			i = 0;
			a++;
		}
	}
	return (0);
}

int	check_map_goodway_items_number(t_map *ptr)
{
	int	i;
	int	a;
	int	items_number;
	
	items_number = 0;
	i = 0;
	a = 0;
	while (a < ptr->height - 1)
	{
		if (ptr->grid[a][i] == 'C')
			items_number++;
		if (i > ptr->width - 1)
		{
			a++;
			i = 0;
		}
		i++;
	}
	return (items_number);
}
void	check_map_goodway(t_map *ptr, int height, int width, t_playerpos *pos)
{
	if (height < 0 || height >= ptr->height || width < 0 || width >= ptr->width)
		return ;
	if (ptr->grid[height][width] == '1' || ptr->grid[height][width] == 'V')
		return ;
	if (ptr->grid[height][width] == 'E')
		pos->exit = 1;
	if (pos->exit == 1 && pos->item == check_map_goodway_items_number(ptr))
    	return ;
	if (ptr->grid[height][width] == 'C')
		pos->item++;
	ptr->grid[height][width] = 'V';
	check_map_goodway(ptr, height + 1, width, pos);
	check_map_goodway(ptr, height - 1, width, pos);
	check_map_goodway(ptr, height, width + 1, pos);
	check_map_goodway(ptr, height, width - 1, pos);
}

int	check_map(t_map *ptr, t_playerpos *pos)
{
	int	items_number;
	
	if (check_map_size(ptr) == 1)
		return (1);
	items_number = check_map_goodway_items_number(ptr);
	if (ptr->height == ptr->width)
		return (1);
	if (check_map_close(ptr) == 1)
		return (1);
	if (check_map_goodelement(ptr) == 1)
		return (1);
	if (check_map_allelement(ptr, pos) == 1)
		return (1);
	pos->exit = 0;
	check_map_goodway_playerpos(ptr, pos);
	check_map_goodway(ptr, pos->height, pos->width, pos);
	if (pos->exit != 1 || pos->item != items_number)
		return (1);
	return (0);
}

void	free_map(t_map *map)
{
	int	i;
	
	i = map->height - 1;
	while(i != -1)
	{
		free(map->grid[i]);
		i--;
	}
	free(map->grid);
}
int	createWindow(t_mlx_data	*mlx_data, t_map *map)
{
	mlx_data->mlx_start = mlx_init();
	if (mlx_data->mlx_start == NULL)
		return (1);
	
	mlx_data->mlx_window = mlx_new_window(mlx_data->mlx_start, map->width * 42, map->height * 42, "SIUUU");
	if (mlx_data->mlx_window == NULL)
	{
		mlx_destroy_display(mlx_data->mlx_start);
		free(mlx_data->mlx_start);
		return (1);
	}
	return (0);
}

void	display(t_mlx_data *mlx_data, t_textures *textures, t_map *map)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (a < map->height)
	{
		if (map->grid[a][i] == '1')
			mlx_put_image_to_window(mlx_data->mlx_start, mlx_data->mlx_window, textures->wall, i * 42, a * 42);
		else if (map->grid[a][i] == '0')
			mlx_put_image_to_window(mlx_data->mlx_start, mlx_data->mlx_window, textures->floor, i * 42, a * 42);	
		else if (map->grid[a][i] == 'E')
			mlx_put_image_to_window(mlx_data->mlx_start, mlx_data->mlx_window, textures->exit, i * 42, a * 42);
		else if (map->grid[a][i] == 'P')
			mlx_put_image_to_window(mlx_data->mlx_start, mlx_data->mlx_window, textures->player, i * 42, a * 42);
		else if (map->grid[a][i] == 'C')
			mlx_put_image_to_window(mlx_data->mlx_start, mlx_data->mlx_window, textures->collectible, i * 42, a * 42);
		i++;
		if (i > map->width - 1)
		{
			a++;
			i = 0;
		}
	}
}

void	free_textures(t_textures *textures, t_mlx_data *mlx_data)
{
	if (textures->player)
		mlx_destroy_image(mlx_data->mlx_start, textures->player);
	if (textures->exit)
		mlx_destroy_image(mlx_data->mlx_start, textures->exit);
	if (textures->collectible)
		mlx_destroy_image(mlx_data->mlx_start, textures->collectible);
	if (textures->floor)
		mlx_destroy_image(mlx_data->mlx_start, textures->floor);
	if (textures->wall)
		mlx_destroy_image(mlx_data->mlx_start, textures->wall);
	
}

void	map_giving(t_map *rmap, t_map *map)
{
	int i;
	int	a;
	
	i = 0;
	a = 0;
	rmap->grid = malloc(map->height * sizeof(char *));
	while (i < map->height)
	{
		rmap->grid[i] = malloc(ft_strlen(map->grid[0]) * sizeof(char));
		i++;
	}
	i = 0;
	while (a < map->height)
	{
		if (i == 0)
			rmap->grid[a] = malloc(ft_strlen(map->grid[0]) * sizeof(char));
		rmap->grid[a][i] = map->grid[a][i];
		i++;
		if (i > (int)ft_strlen(map->grid[0]))
		{
			i = 0;
			rmap->grid[a][ft_strlen(map->grid[0])] = '\0';
			a++;
		}
	}
}
void initTextures(t_textures *textures, t_map *map, t_mlx_data *mlx_data)
{
    textures->x = 42;
    textures->y = 42;

    textures->player = mlx_xpm_file_to_image(mlx_data->mlx_start, 
        "textures/NewP.xpm", &textures->x, &textures->y);
    textures->floor = mlx_xpm_file_to_image(mlx_data->mlx_start, 
        "textures/floor.xpm", &textures->x, &textures->y);
    textures->exit = mlx_xpm_file_to_image(mlx_data->mlx_start, 
        "textures/NewE.xpm", &textures->x, &textures->y);
    textures->wall = mlx_xpm_file_to_image(mlx_data->mlx_start, 
        "textures/wall.xpm", &textures->x, &textures->y);
    textures->collectible = mlx_xpm_file_to_image(mlx_data->mlx_start, 
        "textures/NewC.xpm", &textures->x, &textures->y);

    if (textures->player == NULL || textures->exit == NULL || 
        textures->collectible == NULL || textures->floor == NULL || 
        textures->wall == NULL)
    {
        ft_printf("Error: Failed to load one or more textures\n");
        free_map(map);
        free_textures(textures, mlx_data);
        clean_exit(mlx_data);
    }
}
// void	move(t_mlx_data *mlx_data, t_playerpos *playerpos)
// {
	
	
// }

int	main(int argc, char **argv)
{
	t_map 		map;
	t_textures	textures;
	t_map		map_check;
	t_mlx_data	mlx_data;
	t_playerpos	pos;
	
	if (argc != 2)
	{
		ft_printf("Number of argument invalid");
		exit (0);
	}
	if (check_map_name(argv[1]) == 1)
	{
		ft_printf("Map name invalid");
		exit (0);
	}
	taking_map(argv[1], &map);
	if (map.grid == NULL)
	{
		ft_printf("Map not found");
		exit (0);
	}
	mlx_data.map = map;
	map_check.height = map.height;
	map_giving(&map_check, &map);
	if (check_map(&map_check, &pos) == 1)
	{
		ft_printf("Map invalid");
		free_map(&map);
		exit (0);
	}
	mlx_data.playerpos = pos;
	map.width = map_check.width;
	if (createWindow(&mlx_data, &map_check) == 1)
	{
		free_map(&map);
		// free_textures(&textures, &mlx_data);
		exit (0);
	}
	initTextures(&textures, &map, &mlx_data);
	// if (createWindow(&mlx_data) == 1)
	// {
	// 	free_map(&map);
	// 	free_textures(&textures, &mlx_data);
	// 	exit (0);
	// }
	// move(&mlx_data, &pos)
	mlx_key_hook(mlx_data.mlx_window, handle_input, &mlx_data);
	display(&mlx_data, &textures, &map);
	mlx_data.textures = textures;
	ft_printf("good");
	mlx_data.playerpos.exit = 0;
	mlx_data.playerpos.item = 0;
	mlx_hook(mlx_data.mlx_window, 17, 0, clean_exit, &mlx_data);
	mlx_loop(mlx_data.mlx_start);
	return (0);
}