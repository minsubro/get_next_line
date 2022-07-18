/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:06:26 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/18 15:43:53 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*lstnew(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->str = NULL;
	return (new);
}

t_list	*find_list(t_list **head, int fd)
{
	t_list	*find;

	find = lstiter(*head, fd);
	if (!find)
	{
		find = lstnew(fd);
		if (!find)
			return (NULL);
		find->next = *head;
		*head = find;
	}
	return (find);
}

void	lstdel(t_list **head, int fd)
{
	t_list	*save;
	t_list	*temp;

	if ((*head)->fd == fd)
	{
		save = (*head)->next;
		free((void *)(*head));
		*head = save;
	}
	else
	{
		save = (*head);
		while (save->next)
		{
			if (save->next->fd == fd)
			{
				temp = save->next;
				save->next = save->next->next;
				free(temp);
				break ;
			}
			save = save->next;
		}
	}
}

t_list	*lstiter(t_list *head, int fd)
{
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}
