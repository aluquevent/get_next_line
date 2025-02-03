/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:02:23 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/03 16:33:37 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **stack)
{
	char	*line;
	char	*new_stack;
	size_t	len;

	len = 0;
	while ((*stack)[len] && (*stack)[len] != '\n')
		len++;
	if ((*stack)[len] == '\n')
	{
		line = ft_substr(*stack, 0, len + 1);
		new_stack = ft_strdup(*stack + len + 1);
	}
	else
	{
		line = ft_strdup(*stack);
		new_stack = NULL;
	}
	free(*stack);
	*stack = new_stack;
	return (line);
}

char	*read_fd(int fd, char **stack)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(*stack, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(*stack);
			free(buffer);
			stack = NULL;
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(*stack, buffer);
		free(*stack);
		*stack = temp;
	}
	free(buffer);
	return (*stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stack)
		stack = ft_strdup("");
	stack = read_fd(fd, &stack);
	if (!stack || *stack == '\0')
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	return (extract_line(&stack));
}
/*
#include <stdio.h>
int main(void)
{
	int		fd;
	const char	*path = "text1.txt";
	char		*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error al abrir el archivo.\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
