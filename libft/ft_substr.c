/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:48:50 by ooussaad          #+#    #+#             */
/*   Updated: 2022/10/30 15:38:23 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*p;
	size_t	k;

	k = 0;
	if (!str)
	{
		return (NULL);
	}
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*str && k < len && start < ft_strlen(str))
	{
		p[k] = str[start];
		k++;
		start++;
	}
	p[k] = '\0';
	return (p);
}
