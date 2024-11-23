/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:44:32 by albelaiz          #+#    #+#             */
/*   Updated: 2024/11/22 16:16:22 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppr)
{
	int		i;
	char	*hex;

	i = 0;
	if (uppr)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_puthex(n / 16, uppr);
	i += ft_putchar(hex[n % 16]);
	return (i);
}
