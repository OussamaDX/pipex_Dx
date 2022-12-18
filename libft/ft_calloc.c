/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:47:19 by ooussaad          #+#    #+#             */
/*   Updated: 2022/10/31 15:50:49 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
