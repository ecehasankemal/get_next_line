/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:30:31 by hece              #+#    #+#             */
/*   Updated: 2022/09/29 11:30:33 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_strchr(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

size_t	ft_strcpy(char	*dest,	const char *src, size_t destsize)
{
	size_t	index;

	index = 0;
	while (src[index] && index < destsize)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (0);
}

char	*ft_strjoin(char *string, char *buff)
{
	size_t	index;
	size_t	jndex;
	char	*str;

	if (!string)
	{
		string = (char *)malloc(1 * sizeof(char));
		string[0] = '\0';
	}
	if (!string || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(string) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	index = -1;
	jndex = 0;
	if (string)
		while (string[++index] != '\0')
			str[index] = string[index];
	while (buff[jndex] != '\0')
		str[index++] = buff[jndex++];
	str[ft_strlen(string) + ft_strlen(buff)] = '\0';
	free(string);
	return (str);
}
