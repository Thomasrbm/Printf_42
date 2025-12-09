/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:31:02 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 21:31:27 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}		t_flags;

int		ft_printf(const char *format, ...);

int		ft_putchar(char c);
int		ft_putstr(char *s);

int		ft_parse_formatflags(const char *format, int *i, t_flags *flags,
			va_list args);
int		ft_print_with_flags(char c, va_list args, t_flags flags);
int		ft_print_char_flags(char c, t_flags flags);
int		ft_print_str_flags(char *s, t_flags flags);
int		ft_print_ptr_flags(void *ptr, t_flags flags);
int		ft_print_nbr_flags(int n, t_flags flags);
int		ft_print_unsigned_flags(unsigned int n, t_flags flags);
int		ft_print_hex_flags(unsigned int n, char f, t_flags flags);
int		ft_print_percent_flags(t_flags flags);
void	parse_precision(const char *format, int *i, t_flags *flags,
			va_list args);
void	parse_width(const char *format, int *i, t_flags *flags, va_list args);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_numlen(long n);
int		ft_hexlen(unsigned long n);
void	ft_putchar_n(char c, int n);
void	ft_reset_formatflags_struct(t_flags *flags);
int		parse_flags_chars(const char *format, int *i, t_flags *flags);

void	print_hex_recursive(unsigned int n, char format);
int		ft_parse_formatflags(const char *format, int *i, t_flags *flags,
			va_list args);
int		ft_ulen(unsigned int n);

#endif