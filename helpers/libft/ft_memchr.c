/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:02:41 by jenlee            #+#    #+#             */
/*   Updated: 2025/05/21 14:23:24 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		u_c;
	const unsigned char	*u_s;

	i = 0;
	u_c = (unsigned char )c;
	u_s = (const unsigned char *)s;
	while (i < n)
	{
		if (u_s[i] == u_c)
			return ((void *)(u_s + i));
		i++;
	}
	return (NULL);
}
