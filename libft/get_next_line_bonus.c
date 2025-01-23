/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:09 by artperez          #+#    #+#             */
/*   Updated: 2025/01/14 10:32:27 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readline(int fd, char *buffer)
{
	char		*temp_buf;
	ssize_t		readbytes;

	readbytes = 1;
	temp_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (temp_buf == NULL)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (buffer == NULL)
			return (free(temp_buf), free(buffer), NULL);
	}
	while (readbytes > 0)
	{
		readbytes = read(fd, temp_buf, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(buffer), free(temp_buf), NULL);
		temp_buf[readbytes] = '\0';
		buffer = ft_free(buffer, temp_buf);
		if (!buffer || ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(temp_buf);
	return (buffer);
}

char	*ft_free(char *buffer, char *temp_buf)
{
	char	*temp;

	temp = ft_strjoin_gnl(buffer, temp_buf);
	if (!temp)
	{
		free(buffer);
		free(temp_buf);
		return (NULL);
	}
	free(buffer);
	return (temp);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = ft_calloc((ft_strlen_gnl(buffer + i, 1) + 2), sizeof(char));
	if (new_buffer == NULL)
		return (NULL);
	i++;
	while (buffer[i + j])
	{
		new_buffer[j] = buffer[i + j];
		j++;
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_readline(fd, buffer[fd]);
	if (ft_strlen_gnl(buffer[fd], 0) == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_getline(buffer[fd]);
	if (line == NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
/*
int	main()
{
	int	file;
	char *str;
	int	i = 98;
	
	//file = open("/home/Arthur/42/Exo/get_next_line/test.txt", O_RDONLY);
	if (file == -1)
	{
		printf("t'as pas reussi a ouvrir le fichier nullos");
		return (0);
	}
	while (i < 100)
	{
		str = get_next_line(file);
		printf("%s", str);
		free(str);
		i++;
	}
//	free(str);
//	str = get_next_line(file);
//	printf("%s", str);
//	free(str);
	close(file);
}*/
