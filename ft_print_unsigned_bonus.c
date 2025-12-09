/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:30:53 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 20:36:43 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_unsigned(unsigned int n)
{
	if (n >= 10)
		print_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
}

static int	get_unsigned_len(unsigned int n, t_flags flags)
{
	if (flags.dot && flags.precision == 0 && n == 0)
		return (0);
	if (flags.dot && flags.precision > ft_ulen(n))
		return (flags.precision);
	return (ft_ulen(n));
}

static void	print_unsigned_core(unsigned int n, t_flags fl, int *cnt)
{
	int	zp;

	if (fl.dot && fl.precision == 0 && n == 0)
		return ;
	zp = 0;
	if (fl.dot && fl.precision > ft_ulen(n))
		zp = fl.precision - ft_ulen(n);
	if (zp > 0)
	{
		ft_putchar_n('0', zp);
		*cnt += zp;
	}
	print_unsigned(n);
	*cnt += ft_ulen(n);
}

static void	print_unsigned_pad(t_flags fl, int pad, int *cnt)
{
	if (!fl.minus && !fl.zero)
		ft_putchar_n(' ', pad);
	else if (!fl.minus && fl.zero)
		ft_putchar_n('0', pad);
	else if (fl.minus)
		ft_putchar_n(' ', pad);
	*cnt += pad;
}

int	ft_print_unsigned_flags(unsigned int n, t_flags flags)
{
	int	count;
	int	padding;

	count = 0;
	if (flags.dot)
		flags.zero = 0;
	padding = flags.width - get_unsigned_len(n, flags);
	if (padding < 0)
		padding = 0;
	if (!flags.minus)
		print_unsigned_pad(flags, padding, &count);
	print_unsigned_core(n, flags, &count);
	if (flags.minus)
		print_unsigned_pad(flags, padding, &count);
	return (count);
}
