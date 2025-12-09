/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:30:36 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 20:40:41 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_abs(long long n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_abs(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_print_sign(long long n, t_flags f, int *c)
{
	if (n < 0)
		*c += ft_putchar('-');
	else if (f.plus)
		*c += ft_putchar('+');
	else if (f.space)
		*c += ft_putchar(' ');
}

int	ft_calculate_len_to_print(long long n, t_flags f, int len_raw_nb)
{
	int	len_to_print;

	len_to_print = len_raw_nb;
	if (f.dot && f.precision >= len_raw_nb)
		len_to_print = f.precision;
	if (n < 0 || f.plus || f.space)
		len_to_print++;
	return (len_to_print);
}

void	ft_left_padding(long long nb, t_flags f, int len_raw_nb, int *count)
{
	int	len_to_print;

	len_to_print = ft_calculate_len_to_print(nb, f, len_raw_nb);
	if ((!f.minus) && f.width > len_to_print && (!f.zero || f.dot))
	{
		ft_putchar_n(' ', f.width - len_to_print);
		*count += f.width - len_to_print;
	}
	ft_print_sign(nb, f, count);
	if ((!f.minus && f.zero && !f.dot) && f.width > len_to_print)
	{
		ft_putchar_n('0', f.width - len_to_print);
		*count += f.width - len_to_print;
	}
	if ((f.dot) && f.precision > len_raw_nb)
	{
		ft_putchar_n('0', f.precision - len_raw_nb);
		*count += f.precision - len_raw_nb;
	}
}

int	ft_print_nbr_flags(int n, t_flags f)
{
	long long	nb;
	int			count;
	int			len_raw_nb;
	int			len_to_print;

	nb = n;
	count = 0;
	len_raw_nb = ft_numlen(nb);
	if (f.precision == 0 && nb == 0)
		len_raw_nb = 0;
	len_to_print = ft_calculate_len_to_print(nb, f, len_raw_nb);
	ft_left_padding(nb, f, len_raw_nb, &count);
	if (f.precision != 0 || nb != 0)
	{
		ft_putnbr_abs(nb);
		count += len_raw_nb;
	}
	if (f.minus && f.width > len_to_print)
	{
		ft_putchar_n(' ', f.width - len_to_print);
		count += f.width - len_to_print;
	}
	return (count);
}
