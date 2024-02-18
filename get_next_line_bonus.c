/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:59:18 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/26 11:59:20 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	create_nodes(t_list **lst, int fd)
{
	char	*buffer;
	int		bytes_read;

	if (!lst)
		return (0);
	while (!check_newline(*lst))
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[bytes_read] = '\0';
		ft_lstadd_back(lst, buffer);
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	return (1);
}

char	*take_line(t_list *line)
{
	int		len;
	char	*buffer;
	int		i;

	len = len_to_newline(line);
	if (len <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (len + 2));
	if (!buffer)
		return (NULL);
	len = 0;
	while (line)
	{
		i = 0;
		while (line->content[i] && line->content[i] != '\n')
			buffer[len++] = line->content[i++];
		if (line->content[i] == '\n')
		{
			buffer[len++] = '\n';
			break ;
		}
		line = line->next;
	}
	buffer[len] = '\0';
	return (buffer);
}

char	*allocate_after_newline(t_list *list)
{
	int		i;
	t_list	*last;
	char	*temp;

	temp = NULL;
	while (list != NULL)
	{
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	last = list;
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
		{
			temp = strdup(last->content + i + 1);
			return (temp);
		}
		i++;
	}
	return (temp);
}

t_list	*read_input(t_list *head, int fd, char **arr_fd)
{
	if (read(fd, &head->content, 0) < 0)
	{
		if (arr_fd[fd])
		{
			free(arr_fd[fd]);
			arr_fd[fd] = NULL;
		}
		return (NULL);
	}
	if (!arr_fd[fd])
	{
		if (!create_nodes(&head, fd))
		{
			ft_lstclear(&head);
			return (NULL);
		}
	}
	else
		ft_lstadd_back(&head, arr_fd[fd]);
	if (!create_nodes(&head, fd))
	{
		ft_lstclear(&head);
		return (NULL);
	}
	return (head);
}

char	*get_next_line(int fd)
{
	static char	*arr_fd[1024];
	t_list		*head;
	char		*line;
	char		*last;

	head = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	head = read_input(head, fd, arr_fd);
	if (!head)
		return (NULL);
	line = take_line(head);
	if (!line)
	{
		ft_lstclear(&head);
		return (NULL);
	}
	last = allocate_after_newline(head);
	ft_lstclear(&head);
	arr_fd[fd] = last;
	return (line);
}
