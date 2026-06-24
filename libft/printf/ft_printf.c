/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:14:50 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/26 14:28:12 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_actualprint(const char a, va_list args, int *inft_counter)
{
	if (a == 'c')
		ft_putchar(va_arg(args, int), inft_counter);
	else if (a == 's')
		ft_putstr(va_arg(args, char *), inft_counter);
	else if (a == 'p')
		ft_printp((uintptr_t)va_arg(args, void *), inft_counter);
	else if (a == 'd')
		ft_printid(va_arg(args, int), inft_counter);
	else if (a == 'i')
		ft_printid(va_arg(args, int), inft_counter);
	else if (a == 'u')
		ft_printu(va_arg(args, unsigned int), inft_counter);
	else if (a == 'x')
		ft_printlowerx(va_arg(args, unsigned int), inft_counter);
	else if (a == 'X')
		ft_printupperx(va_arg(args, unsigned int), inft_counter);
	else if (a == '%')
		ft_putchar('%', inft_counter);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		inft_counter;
	va_list	args;

	va_start(args, format);
	i = 0;
	inft_counter = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_actualprint(format[i], args, &inft_counter);
		}
		else
		{
			ft_putchar(format[i], &inft_counter);
		}
		i++;
	}
	va_end(args);
	return (inft_counter);
}
