/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:50:45 by vleida            #+#    #+#             */
/*   Updated: 2021/04/23 16:40:22 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}


#include <stdio.h>
#include <string.h>

int		main(void)
{
	const char	*dst = "12";
    const char	*src = "system of a down";
	size_t	n = 6;

    printf("%d\t", strncmp(src, dst, n));
    printf("%d\n", ft_strncmp(src, dst, n));
	printf("%d\t", strncmp("system of a down", "12", 6));
    printf("%d\n", ft_strncmp("system of a down", "12", 6));
	printf("%d\t", strncmp("system of a down", "12", n));
    printf("%d\n", ft_strncmp("system of a down", "12", n));
	return (0);
}