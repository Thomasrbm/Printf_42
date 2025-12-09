/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:31:47 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 20:40:23 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_formatflags_struct(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = -1;
}

int	parse_flags_chars(const char *format, int *i, t_flags *flags)
{
	while (format[*i] == '-' || format[*i] == '0' || format[*i] == '#'
		|| format[*i] == ' ' || format[*i] == '+')
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
	return (0);
}

void	parse_width(const char *format, int *i, t_flags *flags,
		va_list args)
{
	if (format[*i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		(*i)++;
	}
	else if (ft_isdigit(format[*i]))
	{
		flags->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}

void	parse_precision(const char *format, int *i, t_flags *flags,
		va_list args)
{
	if (format[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		if (format[*i] == '*')
		{
			flags->precision = va_arg(args, int);
			if (flags->precision < 0)
			{
				flags->dot = 0;
				flags->precision = -1;
			}
			(*i)++;
		}
		else if (ft_isdigit(format[*i]))
		{
			flags->precision = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]))
				(*i)++;
		}
		else
			flags->precision = 0;
	}
}

int	ft_parse_formatflags(const char *format, int *i, t_flags *flags,
		va_list args)
{
	parse_flags_chars(format, i, flags);
	parse_width(format, i, flags, args);
	parse_precision(format, i, flags, args);
	return (0);
}
