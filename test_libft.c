/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:07:12 by vleida            #+#    #+#             */
/*   Updated: 2021/04/18 17:05:30 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "./libft/srcs/libft.h"

int		ft_cmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_test_memset(void)
{
	char	b[] = "qwerty qwerty qwerty";
	int		a;

	a = sizeof(b);
	printf("------------------------------------\n*b bef = %s\n", b);
	ft_memset(b, 'x', sizeof(b));
//	memset(b, 'x', sizeof(b));
	printf("*b aft = %s,%d\n", b, ft_cmp(b, "xxxxxxxxxxxxxxxxxxxxx"));
	if (ft_cmp(b, "xxxxxxxxxxxxxxxxxxxxx") != 127)
		return (1);
	printf("*****test_1_1(ft_memset(char*, 'x', len))---len = %d ---- OK\n", a);

	int b1[]= {1, 2, 3, 4, 5};
	a = sizeof(b1);
	printf("*b bef = %d, %d, %d, %d, %d\n", b1[0], b1[1], b1[2], b1[3], b1[4]);
	ft_memset(b1, 98, sizeof(b1));
//	memset(b1, 98, sizeof(b1));
	printf("*b aft = %d, %d, %d, %d, %d\n", b1[0], b1[1], b1[2], b1[3], b1[4]);
	if (b1[0] != 1650614882 || b1[1] != b1[0] || b1[2] != b1[0] || b1[3] != b1[0] || b1[4] != b1[0])
		return (2);
	printf("*****test_1_2(ft_memset(int *, 98, len))----len = %d ---- OK\n", a);

	char b3[] = "qwerty qwerty qwerty";
	ft_memset(b3, 'x', 1);
//	memset(b3, 'x', 1);
	if (ft_cmp(b3, "xwerty qwerty qwerty") != 0)
		return (3);
	printf("*****test_1_3(ft_memset(char*, 'x', 1)) ----------------- OK\n");

	char b4[] = "\0";
	ft_memset(b4, 'x', 8);
//	memset(b4, 'x', 1);
	if (b4[0] == '\0')
		return (4);
	printf("*****test_1_4(ft_memset( NULL, 'x', 1)) ----------------- OK\n");

	char b5[] = "A2";
	ft_memset(b5, 0, 2);
//	memset(b5, 0, 2);
	if (b5[0] != '\0')
		return (5);
	printf("*****test_1_5(ft_memset(  'A2',  0, 2)) ----------------- OK\n");

	char b6[] = "A2aaaaa8";
	ft_memset(b6, 'x', 3);
//	memset(b6, 'x', 3);
	if (ft_cmp(b6, "xxxaaaa8") != 0)
		return (6);
	printf("*****test_1_6(ft_memset('A2a.',  x, 3)) ----------------- OK\n");
	return (0);
}

int ft_test_bzero(void)
{
	char	b[] = "qwerty qwerty qwerty";
	int		b1[]= {1, 2, 3, 4, 5};

	int		a;
	a = sizeof(b);
	printf("------------------------------------\n*b bef = %s\n", b);
	ft_bzero(b, sizeof(b));
//	bzero(b, sizeof(b));
	printf("*b aft = %s\n", b);
	if (ft_cmp(b, "\0") != 0)
		return (1);
	printf("*****test_2_1(ft_bzero(char*, len))---len = %d ---------- OK\n", a);

	a = sizeof(b1);
	printf("*b bef = %d, %d, %d, %d, %d\n", b1[0], b1[1], b1[2], b1[3], b1[4]);
	ft_bzero(b1, sizeof(b1));
//	bzero(b1, sizeof(b1));
	printf("*b aft = %d, %d, %d, %d, %d\n", b1[0], b1[1], b1[2], b1[3], b1[4]);
	if (b1[0] != 0 || b1[1] != b1[0] || b1[2] != b1[0] || b1[3] != b1[0] || b1[4] != b1[0])
		return (2);
	printf("*****test_2_2(ft_bzero(int *, len))---len = %d ---------- OK\n", a);

	char b3[] = "qwerty qwerty qwerty";
	ft_bzero(b3, 20);
//	bzero(b3, 20);
	if (b3[19] != 0)
		return (3);
	printf("*****test_2_3(ft_bzero(char*, 20)) ---------------------- OK\n");

	char b4[] = "";
	ft_bzero(b4, 8);
//	bzero(b4, 1);
	if (b4[0] != '\0')
		return (4);
	printf("*****test_2_4(ft_bzero( NULL, 8)) ----------------------- OK\n");

	char b5[] = "A2";
	ft_bzero(b5, 2);
//	bzero(b5, 2);
	if (b5[0] != 0)
		return (5);
	printf("*****test_2_5(ft_bzero( 'A2', 2)) ----------------------- OK\n");
	return (0);
}

int ft_test_memcpy(void)
{
	char dest[8];
	char src[] = "1234567";
	ft_memcpy(dest, src, sizeof(src));
//	memcpy(dest, src, sizeof(src));
	if (ft_cmp(src, dest) != 0)
		return (1);
	printf("------------------------------------\n*****test_3_1(ft_memcpy(dest [8], \"1234567\", 8)) -------- OK\n");
	
	char dest1[7];
	char src1[] = "1234567";
	dest1[0] = 32;
	ft_memcpy(dest1, src1, 0);
//	memcpy(dest1, src1, 0);
	if (dest1[0] != 32)
		return (2);
	printf("*****test_3_2(ft_memcpy(dest1[7], \"1234567\", 0)) -------- OK\n");
	
	char dest2[7];
	char src2[] = "1234567";
	ft_memcpy(dest2, src2, 2);
//	memcpy(dest2, src2, 2);
	if (dest2[2] == src2[2] || dest2[1] != '2')
		return (3);
	printf("*****test_3_3(ft_memcpy(dest2[7], \"1234567\", 2)) -------- OK\n");
	
	unsigned int dest3[1];
	char src3[] = " ";
	ft_memcpy(dest3, src3, 1);
//	memcpy(dest3, src3, 1);
	if (dest3[0] != 32)
		return (4);
	printf("*****test_3_4(ft_memcpy(int[1], \" \", 2))- %d------------- OK\n", dest3[0]);
	
	char dest4[10];
	char src4[] = "0123456789asder";
	ft_memcpy(dest4, src4, 10);
//	memcpy(dest4, src4, 10);
	if (ft_cmp(dest4, "01234567891234567") != 0)
		return (5);
	printf("*****test_3_5(ft_memcpy(char[10], \" \", 10))-------------- OK\n");
	return (0);
}

int ft_test_memccpy(void)
{
	char dest[8];
	char src[] = "0123456";
	ft_memccpy(dest, src, 51, sizeof(src));
//	memccpy(dest, src, 51, sizeof(src));
	if (ft_cmp(dest, "01234") != -54)
		return (1);
	printf("------------------------------------\n*****test_4_1(ft_memccpy(dest [8], \"0123456\", '3', 8)) -- OK\n");
	printf("!--%d--!\n", ft_cmp(dest, "01234"));
	
	short int dest1[1];
	char src1[] = "012\0";
	ft_memccpy(dest1, src1, 128, 1);
//	memccpy(dest1, src1, 128, 1);
	if (dest1[0] != 13616)
		return (2);
	printf("*****test_4_2(ft_memccpy(dest1[1], \"0123456\", 128, 1)) -- OK\n");

	char dest2[8];
	char src2[] = "0123456";
	ft_memccpy(dest2, src2, '1', 6);
//	memccpy(dest2, src2, '1', 6);
	if (ft_cmp(dest2, "01") != 0)
		return (3);
	printf("*****test_4_3(ft_memccpy(dest2[8], \"0123456\", '1', 6)) -- OK\n");
	return (0);
}

int ft_test_memmove(void)
{
	char src3[] = "0123456789";
	char src4[] = "0123456789";
	ft_memmove (&src3[4], &src3[3], 3);
	memmove (&src4[4], &src4[3], 3);
	printf ("src lib: %s\n", src3);
	printf ("src min: %s\n-----------------\n", src4);

	char	src[] = "lorem ipsum dolor sit amet";
	char	src1[] = "lorem ipsum dolor sit amet";
	char	*dest, *dest1;
	dest = src + 1;
	dest1 = src1 + 1;
	ft_memmove(src, dest, 8);
	write(1, dest, 22); write(1, "\n", 1);
	memmove(src1, dest1, 8);
	write(1, dest1, 22); write(1, "\n", 1);
	return (0);
}

int ft_test_memchr(void)
{
	unsigned char src[15]="1234567890";
	unsigned char src1[15]="1234567890";
	char *sym, *sym1;
	printf ("src old: %s\n",src);
	sym = memchr (src, '4', 10);
	sym1 = ft_memchr (src1, '4', 10);
	if (sym != NULL)
		sym[0] = '!';
	if (sym1 != NULL)
		sym1[0] = '!';
	printf ("src lib: %s\n",src);
	printf ("src min: %s\n",src1);
	return 0;
}

int ft_test_strlcat(void)
{
	size_t	n = 10;
	char	dest[n], dest1[n];
	size_t	i;

	dest[10] = 'a';
	dest1[10] = 'a';
	i = ft_strlcat(dest, "lorem ipsum dolor sit amet", 1);
	printf("min-**%zu**\n", i);
	printf("min-**%s**\n", dest);
	i = strlcat(dest1, "lorem ipsum dolor sit amet", 1);
	printf("lib-**%zu**\n", i);
	printf("lib-**%s**\n", dest1);
	return (0);
}

int		main(void)
{
	int a;

	a = ft_test_memset();
	if (a == 0)
		printf("---1_MEMSET --------------------------------------------- OK(6 of 6)\n\n");
	else
		printf("---1_MEMSET --------------------------------------------- ERROR(%d of 6)--\n\n", a);
	a = ft_test_bzero();
	if (a == 0)
		printf("---2_BZERO ---------------------------------------------- OK(5 of 5)\n\n");
	else
		printf("---2_BZERO ---------------------------------------------- ERROR(%d of 5)--\n\n", a);
	a = ft_test_memcpy();
	if (a == 0)
		printf("---3_MEMCPY --------------------------------------------- OK(5 of 5)\n\n");
	else
		printf("---3_MEMCPY --------------------------------------------- ERROR(%d of 5)--\n\n", a);
	a = ft_test_memccpy();
	if (a == 0)
		printf("---4_MEMCCPY -------------------------------------------- OK(3 of 3)\n\n");
	else
		printf("---4_MEMCCPY -------------------------------------------- ERROR(%d of 3)--\n\n", a);
	ft_test_memmove();
	ft_test_memchr();
	ft_test_strlcat();
	return (0);
}
