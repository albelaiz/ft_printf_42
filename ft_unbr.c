/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:30:59 by albelaiz          #+#    #+#             */
/*   Updated: 2024/11/23 13:08:10 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbr(unsigned int nb)
{
	char	c;
	int		cont;

	cont = 0;
	if (nb >= 10)
	{
		cont += ft_unbr(nb / 10);
	}
	c = nb % 10 + 48;
	cont += ft_putchar(c);
	return (cont);
}
