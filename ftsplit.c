/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:18:15 by vleida            #+#    #+#             */
/*   Updated: 2021/04/20 20:48:14 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include <unistd.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

#include <stdio.h>

static size_t	ft_count_words(char const *s, char c, size_t *len)
{
	size_t	i;
	size_t	wrd;

	wrd = 0;
	*len = 0;
	i = 0;
	while (s[i])
	{
		if (((char *)s)[i] == c)
			i++;
		else
		{
			wrd++;
			while (s[i] && ((char *)s)[i] != c)
			{
				i++;
				*len = *len + 1;
			}
		}
	}
	*len = *len + wrd + 1;
	return (wrd);
}

static char	*ft_pull_str(char *arr, char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (((char *)s)[i] == c)
			i++;
		else
		{
			while (s[i] && ((char *)s)[i] != c)
			{
				arr[j] = ((char *)s)[i];
				i++;
				j++;
			}
			j++;
		}
	}
	return (arr);
}

static char	**ft_pull_rez(char **rez, char *arr, size_t len, size_t wrd)
{
	size_t	i;
	size_t	j;

	rez[0] = &arr[0];
	j = 1;
	i = 0;
	while (i < len && j < wrd)
	{
		if (arr[i] == 0)
		{
			rez[j] = &arr[i + 1];
			j++;
		}
		i++;
	}
	rez[j] = NULL;
	return (rez);
}

char	**ft_split(char const *s, char c)
{
	size_t	wrd;
	size_t	len;
	char	**rez;
	char	*arr;

	if (!s)
		return (NULL);
	wrd = ft_count_words(s, c, &len);
	rez = malloc(sizeof(char *) * wrd);
	if (!rez)
		return (NULL);
	arr = malloc(sizeof(char) * len);
	if (!arr)
	{
		free (rez);
		return (NULL);
	}
	ft_bzero(arr, len);
	ft_pull_str(arr, s, c);
	ft_pull_rez(rez, arr, len, wrd);
	return (rez);
}

int	main()
{
	char *string = "      split       this for   me  !       ";
	char **expected = ((char*[6]){"split", "this", "for", "me", "!", ((void *)0)});
	char **result = ft_split(string, ' ');
	int i = 0;

	printf("-%s- = -%s-\n", result[0], expected[0]);
	printf("-%s- = -%s-\n", result[1], expected[1]);
	printf("-%s- = -%s-\n", result[2], expected[2]);
	printf("-%s- = -%s-\n", result[3], expected[3]);
	printf("-%s- = -%s-\n", result[4], expected[4]);
	printf("-%s- = -%s-\n", result[5], expected[5]);
	while (i < 5)
	{
		printf("%d", strcmp(result[i], expected[i]));
		if (strcmp(result[i], expected[i]) == 0)
		{
			printf("i = %d ---", i);
			printf("%s-=-%s\n", result[i], expected[i]);
		}
		i++;
	}
	return (0);
}
