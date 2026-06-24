/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:48:54 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/05 22:41:39 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printpointer(uintptr_t j, int *inft_counter)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (j >= 16)
		ft_printpointer(j / 16, inft_counter);
	ft_putchar(hex_digits[j % 16], inft_counter);
}

void	ft_printp(uintptr_t j, int *inft_counter)
{
	if (j == 0)
	{
		ft_putstr("(nil)", inft_counter);
		return ;
	}
	ft_putstr("0x", inft_counter);
	ft_printpointer(j, inft_counter);
}
