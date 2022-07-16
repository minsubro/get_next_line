/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:11:51 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/15 17:41:12 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>

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

int	LF_check(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*create_str(char **str)
{
	int		i;
	char	*save;
	
	i = 0;
	while (*str[i] != '\n')
		i++;
	save = (char *)malloc(i + 2);
	while (i >= 0)
	{
		save[i] = *str[i];
		i--;
	}
	return (save);
}

char	*ft_strjoin(char *s1, char *s2, int idx)
{
	char	*str;
	char	*temp;
	int		i;
	
	temp = s1;
	printf("\n\n%d\n\n", ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = idx;
	while (s1 && *s1)
	{
		str[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	if (!temp)
		free(temp);
	return (str);
}

char	*ft_new(char *str, int LF_idx)
{
	char	*save;
	int		i;

	save = (char *)malloc(ft_strlen(str) - LF_idx + 1);
	i = 0;
	while (str[LF_idx])
		save[i++] = str[LF_idx++]; 
	free(str);
	save[i] = 0;
	return (save);
}

char	*ft_make(char **str)
{
	//char	*temp;
	int		LF_idx;
	int		i;

	LF_idx = 0;
	i = 0;
	printf("%c", *str[8]);
	//while (*str[LF_idx] != '\n' && *str[LF_idx] != 0)
	//	LF_idx++;
	//printf("%d", LF_idx);
	/*if (*str[LF_idx] == '\n')
		LF_idx++;*/
	//temp = (char *)malloc(LF_idx + 1);
	//free (temp);
	//printf("요기?");
	return (NULL);
	/*while (i < LF_idx)
	{
		temp[i] = *str[i];
		i++;
	}
	*str = ft_strjoin(*str, 0, LF_idx);
	return (temp);*/
	
}

char	*get_next_line(int fd)
{
	static	char	*str;
	char			*save;

	save = (char *)malloc(BUFFER_SIZE + 1); // save 에버퍼 사이즈 + null 만큼 할당
	while (read(fd, save, BUFFER_SIZE) > 0)
	{
		save[BUFFER_SIZE] = 0;
		str = ft_strjoin(str, save, 0);
		//printf("%s", str);
		if (LF_check(str))
		{
			return (ft_make(&str));
		}
	}
	printf("요기?");
	if (ft_strlen(str))
	{
		printf("%d", ft_strlen(str));
		printf("%p", &str);
		return (ft_make(&str));
	}
	free(str);
	return (NULL);
}

int main(int ac, char **av)
{
	int fd;
	char *str;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == 0)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
}