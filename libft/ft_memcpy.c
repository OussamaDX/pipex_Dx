/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:21:56 by ooussaad          #+#    #+#             */
/*   Updated: 2022/10/31 15:23:43 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*src_char;
	unsigned char	*dest_char;

	i = 0;
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dst;
	if (dest_char == src_char)
		return (dest_char);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
