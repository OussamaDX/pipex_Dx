/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:17:12 by OUShassan         #+#    #+#             */
/*   Updated: 2022/10/30 15:45:45 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res_d;
	unsigned int	res_s;

	res_s = ft_strlen(src);
	if (!dest && !size)
		return (res_s);
	res_d = ft_strlen(dest);
	i = ft_strlen(dest);
	j = 0;
	if (!dest && !size)
		return (ft_strlen(src));
	if (size == 0)
		return (res_s);
	if (size < res_d)
		return (res_s + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res_d + res_s);
}
