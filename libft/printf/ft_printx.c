/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupperx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:50:14 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/06 12:00:38 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printupperx(unsigned int i, int *inft_counter)
{
	char	*hex_digits;
	char	temp;

	hex_digits = "0123456789ABCDEF";
	if (i >= 16)
		ft_printupperx(i / 16, inft_counter);
	temp = hex_digits[i % 16];
	ft_putchar(temp, inft_counter);
}

void	ft_printlowerx(unsigned int i, int *inft_counter)
{
	char	*hex_digit;
	char	temp;

	hex_digit = "0123456789abcdef";
	if (i >= 16)
		ft_printlowerx(i / 16, inft_counter);
	temp = hex_digit[i % 16];
	ft_putchar(temp, inft_counter);
}
