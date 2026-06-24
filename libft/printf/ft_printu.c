/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:49:29 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/05 19:24:55 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu(unsigned int i, int *inft_counter)
{
	if (i >= 10)
		ft_printu(i / 10, inft_counter);
	ft_putchar((i % 10) + '0', inft_counter);
}
