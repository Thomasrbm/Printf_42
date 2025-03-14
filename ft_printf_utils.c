/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 05:50:10 by throbert          #+#    #+#             */
/*   Updated: 2024/11/06 18:05:51 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_hexa(unsigned int num, char type)
{
	char	*base;
	int		length_printed;

	base = NULL;
	length_printed = 0;
	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	if (base != NULL)
	{
		if (num >= 16)
			length_printed += ft_printf_hexa(num / 16, type);
		write(1, &base[num % 16], 1);
	}
	return (length_printed + 1);
}

int	ft_printf_ptr(unsigned long ptr)
{
	int		length_printed;
	char	*base;
	char	buffer[16];
	int		i;

	length_printed = 0;
	base = "0123456789abcdef";
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	length_printed += write(1, "0x", 2);
	i = 0;
	while (ptr > 0)
	{
		buffer[i] = base[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i > 0)
		length_printed += write(1, &buffer[--i], 1);
	return (length_printed);
}

int	ft_printf_nbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = ft_printf_str(str);
	free(str);
	return (len);
}

int	ft_printf_unbr(unsigned int nbr)
{
	int		len;
	char	*str;

	str = ft_utoa(nbr);
	len = ft_printf_str(str);
	free(str);
	return (len);
}
