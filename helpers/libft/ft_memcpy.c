/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:39:48 by jenlee            #+#    #+#             */
/*   Updated: 2025/05/19 18:14:47 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_temp;
	const unsigned char	*src_temp;

	dst_temp = (unsigned char *) dst;
	src_temp = (unsigned char *) src;
	while (n--)
	{
		*dst_temp++ = *src_temp++;
	}
	return (dst);
}
