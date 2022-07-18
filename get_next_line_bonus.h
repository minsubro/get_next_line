/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:08:25 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/18 16:06:21 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	int				fd;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
t_list	*lstnew(int fd);
t_list	*find_list(t_list **head, int fd);
void	lstdel(t_list **head, int fd);
t_list	*lstiter(t_list *head, int fd);
int		ft_strlen(char *str);
int		lf_check(char *str);
char	*ft_strjoin(char *s1, char *s2, int idx);
char	*ft_make(char **str);
char	*make_str(t_list *lst, int *len);

#endif