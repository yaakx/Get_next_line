/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:06:48 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/17 14:42:46 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	i;
	size_t	k;
	char	*sjoin;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1) + ft_strlen(s2);
	if (!(sjoin = (char *)malloc(len1 + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		sjoin[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != 0)
	{
		sjoin[i + k] = s2[k];
		k++;
	}
	sjoin[i + k] = 0;
	return (sjoin);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*cpy;

	len = ft_strlen(s1);
	if (!(cpy = (char *)malloc((len + 1) * sizeof(const char))))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	len = (size < len) ? size : len;
	if (!(subs = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = 0;
	return (subs);
}
