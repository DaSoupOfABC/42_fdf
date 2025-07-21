/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:52:25 by jenlee            #+#    #+#             */
/*   Updated: 2025/05/29 10:43:24 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char		*temp_src;
	unsigned char			*temp_dst;
	size_t					i;

	if (!dst || !src)
	{
		return (NULL);
	}
	temp_src = (const unsigned char *) src;
	temp_dst = (unsigned char *) dst;
	i = 0;
	if (temp_dst > temp_src)
	{
		while (len-- > 0)
			temp_dst[len] = temp_src[len];
	}
	else
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
