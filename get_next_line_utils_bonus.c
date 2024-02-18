/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:08:13 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/25 16:08:14 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	len_to_newline(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			len++;
			if (list->content[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	ptr = (char *)malloc((1 + len) * sizeof(char));
	if (!ptr)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_lstadd_back(t_list **lst, char *content)
{
	t_list	*crnt;
	t_list	*prev;
	t_list	*creat;

	if (!lst || !content)
		return (0);
	creat = (t_list *)malloc(sizeof(t_list));
	if (!creat)
		return (0);
	creat->content = content;
	creat->next = NULL;
	if (!*lst)
	{
		*lst = creat;
		return (1);
	}
	crnt = *lst;
	while (crnt)
	{
		prev = crnt;
		crnt = crnt->next;
	}
	prev->next = creat;
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	check_newline(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}
