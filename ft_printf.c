/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:28:33 by albelaiz          #+#    #+#             */
/*   Updated: 2024/11/25 20:34:38 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(char c, va_list ptr)
{
	int	cont;

	cont = 0;
	if (c == 'c')
		cont += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		cont += ft_putstr(va_arg(ptr, char *));
	else if (c == '%')
		cont += ft_putchar('%');
	else if (c == 'i' || c == 'd')
		cont += ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		cont += ft_unbr(va_arg(ptr, unsigned int));
	else if (c == 'X')
		cont += ft_puthex(va_arg(ptr, unsigned int), 1);
	else if (c == 'x')
		cont += ft_puthex(va_arg(ptr, unsigned int), 0);
	else if (c == 'p')
		cont += ft_putstr("0x") + ft_putaddres(va_arg(ptr, unsigned long), 0);
	else if (c == '%')
		cont += ft_putchar('%') + ft_putchar(c);
	else
		cont += ft_putchar(c);
	return (cont);
}

int	ft_printf(const char *forma, ...)
{
	int		i;
	int		cont;
	va_list	ptr;

	i = 0;
	cont = 0;
	va_start(ptr, forma);
	if (!forma || write(1, 0, 0) == -1)
		return (-1);
	while (forma[i] != '\0')
	{
		if (forma[i] == '%' && forma[i + 1] != '\0')
		{
			i++;
			cont += helper(forma[i], ptr);
		}
		else if (forma[i] != '%')
			cont += ft_putchar(forma[i]);
		i++;
	}
	va_end(ptr);
	return (cont);
}
