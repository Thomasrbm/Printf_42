/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 06:27:20 by throbert          #+#    #+#             */
/*   Updated: 2024/11/06 17:08:17 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i++;
	i = 0;
	while (str[i])
		ft_printf_char(str[i++]);
	return (i);
}

int	ft_args(va_list args_list, const char type)
{
	int	length_printed;

	length_printed = 0;
	if (type == 'c')
		length_printed += ft_printf_char(va_arg(args_list, int));
	else if (type == 's')
		length_printed += ft_printf_str(va_arg(args_list, char *));
	else if (type == 'p')
		length_printed += ft_printf_ptr(va_arg(args_list, unsigned long));
	else if (type == 'd' || type == 'i')
		length_printed += ft_printf_nbr(va_arg(args_list, int));
	else if (type == 'u')
		length_printed += ft_printf_unbr(va_arg(args_list, unsigned int));
	else if (type == 'x' || type == 'X')
		length_printed += ft_printf_hexa(va_arg(args_list, unsigned int), type);
	else if (type == '%')
		length_printed += ft_printf_char(37);
	return (length_printed);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args_list;
	int		length_printed;

	i = 0;
	length_printed = 0;
	va_start(args_list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length_printed += ft_args(args_list, str[i + 1]);
			i++;
		}
		else
			length_printed += ft_printf_char(str[i]);
		i++;
	}
	va_end(args_list);
	return (length_printed);
}
