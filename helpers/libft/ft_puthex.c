/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:41:34 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/24 14:43:06 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/libft.h"

void	ft_puthex(unsigned int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthex(n / 16);
	ft_putchar(base[n % 16]);
}
