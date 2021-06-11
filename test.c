/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:35:39 by vleida            #+#    #+#             */
/*   Updated: 2021/04/17 15:12:38 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	if (n == 0 || !dst || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)dst)[i] == (unsigned char)c)
			return (&((void*)dst)[i + 1]);
		i++;
	}
	return (NULL);
}

int main(void)
{
	char dest[8];
//	memset(dest, 0, sizeof(dest));
	char dest1[8];
//	memset(dest1, 0, sizeof(dest1));
	char src[] = "0123456";
	ft_memccpy(dest1, src, '3', sizeof(src));
	memccpy(dest, src, '3', sizeof(src));
	printf("!--%s--!\n", dest1);
	printf("!--%s--!\n", dest);
	printf("!-*%d*-!\n", dest[4]);
	return (0);
}