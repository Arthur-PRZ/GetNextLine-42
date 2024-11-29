/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:09 by artperez          #+#    #+#             */
/*   Updated: 2024/11/29 13:53:13 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char *buffer)
{
	char		*temp_buf;
	ssize_t		readbytes;
	//char		*tmp;

	readbytes = 1;
	//tmp = NULL;
	temp_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (temp_buf == NULL)
		return (NULL);
	if (!buffer)
	{	
		buffer = ft_calloc(1, sizeof(char));
		if (buffer == NULL)
		{
			free(temp_buf);
			return (NULL);
		}
	}
	while (readbytes > 0)
	{
		readbytes = read(fd, temp_buf, BUFFER_SIZE);
		if (readbytes < 0)
		{
			free(temp_buf);
			free(buffer);
			return (NULL);
		}
		else if (readbytes == 0)
		{	
			free(temp_buf);
			return (buffer);
		}
		//tmp = buffer;
		buffer = ft_free(buffer, temp_buf);
		//free(tmp);
		if (!buffer)
		{
    		free(temp_buf);
    		return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp_buf);
	return (buffer);
}

char	*ft_free(char *buffer, char *temp_buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, temp_buf);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (temp);
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
		return (NULL);
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
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	new_buffer = ft_calloc((ft_strlen(buffer + i + 1, 1) + 2), sizeof(char));
	if (new_buffer == NULL)
		return (NULL);
	i++;
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_getline(fd, buffer);
	if (buffer == NULL || ft_strlen(buffer, 0) == 0)
		return (NULL);
	line = ft_getline_n(buffer);
	if (line == NULL)
	{	
		free(buffer);
		buffer = NULL;;
		return (NULL);
	}
	buffer = update_buffer(buffer);
	return (line);
}

int	main()
{
	int	file;
	char *str;
	int	i = 0;
	
	//file = open("/home/Arthur/42/Exo42/gnl/test.txt", O_RDONLY);
	file = open("/home/artperez/Stud/exercices/get_next_line/test.txt", O_RDONLY);
	if (file == -1)
	{
		printf("t'as pas reussi a ouvrir le fichier nullos");
		return (0);
	}
	str = malloc(10000 * sizeof(char));
	while (i < 2)
	{
		str = get_next_line(file);
		printf("%s", str);
		i++;
	}
	//str = get_next_line(file);
	//printf("%s", str);
	//str = get_next_line(file);
	//printf("%s", str);
	free(str);
	close(file);
}
