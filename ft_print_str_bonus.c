/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:33:23 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 20:40:54 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strnlen(char *s, int precision)
{
	int	i;

	i = 0;
	while (s[i] && (precision < 0 || i < precision))
		i++;
	return (i);
}

int	print_str_precision(char *s, int precision)
{
	int	i;

	i = 0;
	while (s[i] && i < precision)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
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

int	ft_put_with_precision(char *s, t_flags f)
{
	if (f.dot)
		return (print_str_precision(s, f.precision));
	return (ft_putstr(s));
}

int	ft_print_str_flags(char *s, t_flags f)
{
	int	len_to_print;
	int	pad;
	int	count;

	if (!s && f.dot && f.precision < 6)
		s = "";
	else if (!s)
		s = "(null)";
	len_to_print = ft_strnlen(s, f.precision);
	pad = f.width - len_to_print;
	if (pad < 0)
		pad = 0;
	count = 0;
	if (!f.minus)
		count += ft_padding(pad);
	count += ft_put_with_precision(s, f);
	if (f.minus)
		count += ft_padding(pad);
	return (count);
}
