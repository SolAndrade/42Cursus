/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:49:41 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 19:35:48 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Sends the character 'c' to the file descriptor specified.
/// @param c Character to be sent.
/// @param fd File descriptor where to write.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
