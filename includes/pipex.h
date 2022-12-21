/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:44:05 by ooussaad          #+#    #+#             */
/*   Updated: 2022/12/21 22:32:02 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

void	error();
void	excute_cmd(char *argv,char **envp);
char	*find_path(char *cmd, char **envp);
void	ft_putstr(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int x, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
