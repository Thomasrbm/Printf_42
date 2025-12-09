/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:30:24 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 21:29:15 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_prefix(unsigned int n, char format, t_flags f, int *count)
{
	if (f.hash && n != 0)
	{
		if (format == 'X')
			*count += ft_putstr("0X");
		else
			*count += ft_putstr("0x");
	}
}

void	print_hex(unsigned int nb, char format, t_flags f, int *count)
{
	int	zp;

	zp = 0;
	if (f.dot && f.precision > ft_hexlen(nb))
		zp = f.precision - ft_hexlen(nb);
	if (zp > 0)
	{
		ft_putchar_n('0', zp);
		*count += zp;
	}
	if (!(f.dot && f.precision == 0 && nb == 0))
	{
		print_hex_recursive(nb, format);
		*count += ft_hexlen(nb);
	}
}

void	init_hex_params(unsigned int nb, t_flags *f, int *pad, int *zp)
{
	int	num_width;

	if (f->dot)
		f->zero = 0;
	*zp = 0;
	if (f->dot && f->precision == 0 && nb == 0)
		num_width = 0;
	else
	{
		if (f->precision > ft_hexlen(nb))
			*zp = f->precision - ft_hexlen(nb);
		num_width = *zp + ft_hexlen(nb);
	}
	if (f->hash && nb != 0)
		num_width += 2;
	*pad = f->width - num_width;
	if (*pad < 0)
		*pad = 0;
}

int	ft_print_hex_flags(unsigned int nb, char format, t_flags flags)
{
	int	count;
	int	padding;
	int	zero_pad;

	count = 0;
	init_hex_params(nb, &flags, &padding, &zero_pad);
	if (!flags.minus && !flags.zero)
	{
		ft_putchar_n(' ', padding);
		count += padding;
	}
	print_hex_prefix(nb, format, flags, &count);
	if (!flags.minus && flags.zero && !flags.dot)
	{
		ft_putchar_n('0', padding);
		count += padding;
	}
	print_hex(nb, format, flags, &count);
	if (flags.minus)
	{
		ft_putchar_n(' ', padding);
		count += padding;
	}
	return (count);
}
