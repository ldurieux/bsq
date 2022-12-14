/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:56 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:57 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CASE_OFFSET 32

int	ft_strcmp(const char *s1, const char *s2)
{
	register const unsigned char	*r1;
	register const unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	if (!r1 || !r2)
		return ((int)(r1 - r2));
	while (*r1 == *r2 && *r1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register const unsigned char	*r1;
	register const unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (!r1 || !r2)
		return ((int)(r1 - r2));
	while (*r1 == *r2 && *r1 && n-- > 1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}

static inline unsigned char	ft_chrlwr(unsigned char c)
{
	t_bool	cmp;

	cmp = (c >= 'A') * (c <= 'Z');
	return (c + CASE_OFFSET * cmp);
}

int	ft_stricmp(const char *s1, const char *s2)
{
	register const unsigned char	*r1;
	register const unsigned char	*r2;
	unsigned char					a;
	unsigned char					b;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	if (!r1 || !r2)
		return ((int)(r1 - r2));
	while (1)
	{
		a = ft_chrlwr(*r1++);
		b = ft_chrlwr(*r2++);
		if (a != b || !a)
			break ;
	}
	return (a - b);
}

int	ft_strnicmp(const char *s1, const char *s2, size_t n)
{
	register const unsigned char	*r1 = (unsigned char *)s1;
	register const unsigned char	*r2 = (unsigned char *)s2;
	unsigned char					a;
	unsigned char					b;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (!r1 || !r2)
		return ((int)(r1 - r2));
	while (1)
	{
		a = ft_chrlwr(*r1++);
		b = ft_chrlwr(*r2++);
		if (a != b || !a || n-- > 1)
			break ;
	}
	return (a - b);
}
