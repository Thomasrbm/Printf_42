/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:30:29 by throbert          #+#    #+#             */
/*   Updated: 2025/12/09 17:53:44 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char_flags(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += ft_putchar(c);
		ft_putchar_n(' ', flags.width - 1);
		count += flags.width - 1;
	}
	else
	{
		ft_putchar_n(' ', flags.width - 1);
		count += flags.width - 1;
		count += ft_putchar(c);
	}
	if (count < 1)
		count = 1;
	return (count);
}

int	ft_print_percent_flags(t_flags flags)
{
	(void)flags;
	return (ft_putchar('%'));
}
