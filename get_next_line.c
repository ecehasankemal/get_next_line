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

#include "get_next_line.h"

// get_next_line fonksiyonunda bir string ve bir de satır oluşturuyoruz
// ben string için str değişkeni satır için ise line değişkeni oluşturdum

// daha sonra her hangi bir main dosyasında open komutu ile açılan bir 
// içeriği tutan fd değerini str nin içine atmamız gerekiyor bunu yapmak içinde
// ft_read_and_create fonksiyonunu kullandım burda görevin bize verdiği
// BUFFER_SIZE kadar read komutu ile okuyoruz ve okuduktan sonra ft_strjoin ile 
// döngü içinde str nin son durumuna buff ı ekliyoruz en son buff değişkenini 
// free ile boşalıtyoruz ve str mizi dolu bir şekilde döndüryoruz

// daha sonra ft_get_line ile strminizin içindeki ilk new line karakterine
// kadar olan kısmı bir adrese koyuyoruz ben burda array isminde oluşturdum
// sonra bu şekilde bir satırı döndürmüş oldum ve onu da line değişkenime atadım

// daha sonra ft_create fonksiyonu ile str nin ilk new line a kadar olan kısmı
// kesip kalan kısmı tekrar str ye atadım ki her çalıstıgında aynı satırı
// okumasın diye

// proje genel olarak bu, kodlar içinde kafanıza takılan fonksiyonlar olmuşsa
// libft projemde açıklamaları mevcut bakarsınız vesselamm..

// önemli not fd deki int değerler sistem çagrılarıdır ...

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
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_and_create(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_create(str);
	return (line);
}
