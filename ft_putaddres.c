/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:24:21 by albelaiz          #+#    #+#             */
/*   Updated: 2024/11/23 13:08:21 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddres(unsigned long n, int uppr)
{
	int		i;
	char	*hex;

	i = 0;
	if (uppr)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_putaddres(n / 16, uppr);
	i += ft_putchar(hex[n % 16]);
	return (i);
}