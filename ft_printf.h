/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 05:50:45 by throbert          #+#    #+#             */
/*   Updated: 2024/11/06 17:55:20 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BASE_LOW "0123456789abcdef"

int		ft_printf_char(int c);
int		ft_printf_str(char *str);
int		ft_args(va_list args, const char type);
int		ft_printf(const char *str, ...);

int		ft_printf_hexa(unsigned int num, char type);
int		ft_printf_ptr(unsigned long ptr);
int		ft_printf_nbr(int nbr);
int		ft_printf_unbr(unsigned int nbr);

char	*ft_utoa(unsigned int n);
void	ft_putstr(char *s);
