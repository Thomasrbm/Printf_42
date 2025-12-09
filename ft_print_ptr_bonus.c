/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:30:42 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 20:41:23 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_ptr_hex(unsigned long addr)
{
	char	*base;

	base = "0123456789abcdef";
	if (addr >= 16)
		print_ptr_hex(addr / 16);
	ft_putchar(base[addr % 16]);
}

static int	ft_padding(int pad)
{
	int	count;

	count = 0;
	while (pad-- > 0)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

static int	ft_put_ptr(unsigned long addr)
{
	int	count;

	count = 0;
	ft_putstr("0x");
	print_ptr_hex(addr);
	count += ft_hexlen(addr) + 2;
	return (count);
}

int	ft_print_ptr_flags(void *ptr, t_flags f)
{
	unsigned long	addr;
	int				count;
	int				len;
	int				pad;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	len = ft_hexlen(addr) + 2;
	pad = f.width - len;
	if (pad < 0)
		pad = 0;
	count = 0;
	if (!f.minus)
		count += ft_padding(pad);
	count += ft_put_ptr(addr);
	if (f.minus)
		count += ft_padding(pad);
	return (count);
}
