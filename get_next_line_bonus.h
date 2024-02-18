/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:02:54 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/27 14:28:04 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# if BUFFER_SIZE > 2147483645
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0

# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0

# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int					len_to_newline(t_list *list);
char				*get_next_line(int fd);
char				*ft_strdup(const char *src);
int					ft_lstadd_back(t_list **lst, char *content);
void				ft_lstclear(t_list **lst);
int					check_newline(t_list *list);
t_list				*ft_lstlast(t_list *lst);
char				*ft_strchr(const char *s, int c);

#endif
