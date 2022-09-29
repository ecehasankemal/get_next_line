/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:26:12 by hece              #+#    #+#             */
/*   Updated: 2022/09/29 11:26:19 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Bonus olmayan projede biraz anlattım ama burda devam edeyim
// get_next_line fonksiyonunu aldıgı int fd değeri arkadaşlar
// bir sistem çağrısıdır arkadaşlar o çağrıyı ifade eden dosya
// işlem görür işletim sisteminizdeki tüm dosyaların bu çagrısı
// vardır terminale ls -i yazarsanız arkadaşlar dosyalrın yanında
// çağrı kodlarını görürsünüz..
// bu bonusda ise normale göre olan şey attıgımız farklı
// çağrılarınının hepsini stringimize atmamız için peki bu nasıl oluyor
// bunun için fonksiyonumuza çift boyutlu adres olusturuyoruz
// ben *str[] olarak olusturdum. bu nasıl işler havuzda hatırlarsanız
// argümanlarda ./a.out "hece" "her" "daim" "harika" dersem, av[3][3]
// dersem arkadaşlar harikadaki i harfini ifade etmiş olurum
// ama av[3] dersem harikayı ifade etmiş olurum bu sebepten gelen
// fd dosya cagrılarını cift boyutlu bir adrese atıyoruz olayı
// ve farkı bu arkadaşlar vesselam...

char	*ft_get_line(char *str)
{
	int		index;
	char	*array;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
			index++;
	array = malloc(sizeof(char) * (index + 2));
	if (!array)
		return (NULL);
	index = -1;
	while (str[++index] && str[index] != '\n')
			array[index] = str[index];
	if (str[index] == '\n')
	{
			array[index] = str[index];
			index++;
	}
	array[index] = '\0';
	return (array);
}

char	*ft_create(char *str)
{
	int		index;
	int		jndex;
	char	*array;

	index = 0;
	while (str[index] && str[index] != '\n')
			index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	array = malloc(sizeof(char) * (ft_strlen(str) - index + 1));
	if (!array)
		return (NULL);
	index++;
	jndex = 0;
	while (str[index])
			array[jndex++] = str[index++];
	array[jndex] = '\0';
	free(str);
	return (array);
}

char	*ft_read_and_create(int fd, char *str)
{
	char	*buff;
	int		rc;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rc = 1;
	while (!ft_strchr(str) && rc != 0)
	{
		rc = read(fd, buff, BUFFER_SIZE);
		if (rc == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rc] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_and_create(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_create(str[fd]);
	return (line);
}
