/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:47:19 by ooussaad          #+#    #+#             */
/*   Updated: 2022/12/21 22:32:40 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	p = malloc (count * size);
	if (p == 0)
		return (p);
	ft_bzero (p, count * size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
}

void	*ft_memset(void *b, int x, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	i = 0;
	p = b;
	while (n > i)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (p);
}

