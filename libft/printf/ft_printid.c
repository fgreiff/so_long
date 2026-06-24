/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:54:51 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/05 20:27:32 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printid(int i, int *inft_counter)
{
	char	digit;

	if (i == -2147483648)
	{
		ft_putstr("-2147483648", inft_counter);
		return ;
	}
	if (i < 0)
	{
		ft_putchar('-', inft_counter);
		i = -i;
	}
	if (i > 9)
		ft_printid(i / 10, inft_counter);
	digit = (i % 10) + '0';
	ft_putchar (digit, inft_counter);
}
