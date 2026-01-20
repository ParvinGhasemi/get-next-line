/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamohamm <pamohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:52:49 by pamohamm          #+#    #+#             */
/*   Updated: 2026/01/20 18:14:08 by pamohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!str1)
		return (gnl_strdup(str2));
	joined = (char *)malloc((gnl_strlen(str1) + gnl_strlen(str2) + 1));
	if (!joined)
	{
		free(str1);
		return (NULL);
	}
	i = 0;
	while (str1[i] != '\0')
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	free(str1);
	return (joined);
}

char	*gnl_substr(char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!str)
		return (NULL);
	str_len = gnl_strlen(str);
	if (start >= str_len)
	{
		return (gnl_strdup(""));
	}
	if (start + len > str_len)
		len = str_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strdup(char *str)
{
	char	*dup_str;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = gnl_strlen(str);
	dup_str = (char *)malloc((len + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
