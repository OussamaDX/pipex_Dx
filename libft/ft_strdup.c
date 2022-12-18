/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:30:01 by ooussaad          #+#    #+#             */
/*   Updated: 2022/10/25 21:03:51 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;
	size_t	i;

	s = NULL;
	len = ft_strlen(s1) + 1;
	i = 0;
	s = (char *)malloc (len * sizeof(char ));
	if (!s || !s1)
		return (NULL);
	ft_memcpy (s, s1, len);
	return (s);
}
