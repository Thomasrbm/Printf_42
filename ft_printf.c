/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:30:57 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 20:41:00 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_print_with_flags(char c, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char_flags(va_arg(args, int), flags);
	else if (c == 's')
		count = ft_print_str_flags(va_arg(args, char *), flags);
	else if (c == 'p')
		count = ft_print_ptr_flags(va_arg(args, void *), flags);
	else if (c == 'd' || c == 'i')
		count = ft_print_nbr_flags(va_arg(args, int), flags);
	else if (c == 'u')
		count = ft_print_unsigned_flags(va_arg(args, unsigned int), flags);
	else if (c == 'x' || c == 'X')
		count = ft_print_hex_flags(va_arg(args, unsigned int), c, flags);
	else if (c == '%')
		count = ft_print_percent_flags(flags);
	return (count);
}

static int	handle_format(const char *fmt, int *i, t_flags *fl, va_list args)
{
	int	start;
	int	count;

	start = *i;
	(*i)++;
	ft_reset_formatflags_struct(fl);
	ft_parse_formatflags(fmt, i, fl, args);
	if (fmt[*i] == '\0')
		return (-2);
	if (is_valid_specifier(fmt[*i]))
		count = ft_print_with_flags(fmt[*i], args, *fl);
	else
	{
		count = ft_putchar('%');
		*i = start;
	}
	return (count);
}

static int	ft_printf_loop(const char *format, va_list args, t_flags *flags)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = handle_format(format, &i, flags, args);
			if (ret == -2)
				return (-1);
			count += ret;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;

	va_start(args, format);
	count = ft_printf_loop(format, args, &flags);
	va_end(args);
	return (count);
}
