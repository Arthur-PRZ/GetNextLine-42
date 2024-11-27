/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:09 by artperez          #+#    #+#             */
/*   Updated: 2024/11/27 13:16:24 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char *buffer)
{
	char		*temp_buf;
	ssize_t		readbytes;
	char		*tmp;

	readbytes = 1;
	tmp = NULL;
	temp_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (temp_buf == NULL)
		return (NULL);
	if (!buffer)
	{	
		buffer = ft_calloc(1, sizeof(char)); //pas free
		if (buffer == NULL)
		{
			free(temp_buf);
			return (NULL);
		}
	}
	while (readbytes > 0)
	{
		readbytes = read(fd, temp_buf, BUFFER_SIZE);
		if (readbytes < 1)
		{
			free(temp_buf);
			return (NULL);
		}
		tmp = buffer;
		buffer = ft_strjoin(buffer, temp_buf);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp_buf);
	return (buffer);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == 0)
	{
		tab = NULL;
		return (tab);
	}
	while (i < nmemb * size)
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_getline_n(char *buffer)
{
	char	*line;
	
	line = ft_calloc((ft_strlen(buffer, 0) + 1), sizeof(char));
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	line = ft_strcpy(line, buffer);
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
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer + i + 1, 0) + 1), sizeof(char));
	if (new_buffer == NULL)
		return (NULL);
	i++;
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer = NULL;
	char			*old_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	old_buffer = buffer;
	if (buffer != NULL)
		buffer = update_buffer(buffer);
	buffer = ft_getline(fd, buffer);
	if (buffer == NULL)
	{	
		free(old_buffer);
		return (NULL);
	}
	line = ft_getline_n(buffer);
	free(old_buffer);
	return (line);
}

int	main()
{
	int	file;
	char *str;
	
	//file = open("/home/Arthur/42/Exo42/gnl/test.txt", O_RDONLY);
	file = open("/home/artperez/Stud/exercices/get_next_line/test.txt", O_RDONLY);
	if (file == -1)
	{
		printf("t'as pas reussi a ouvrir le fichier nullos");
		return (0);
	}
	str = malloc(10000 * sizeof(char));
	str = get_next_line(file);
	printf("%s", str);
	str = get_next_line(file);
	printf("%s", str);
	//str = get_next_line(file);
	//printf("%s", str);
	//str = get_next_line(file);
	//printf("%s", str);
	free(str);
	close(file);
}