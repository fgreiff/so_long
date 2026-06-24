/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:10:17 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/06 12:01:39 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	ft_printlowerx(unsigned int i, int *inft_counter);
void	ft_printupperx(unsigned int i, int *inft_counter);
void	ft_printp(uintptr_t j, int *inft_counter);
void	ft_printu(unsigned int i, int *inft_counter);
void	ft_printid(int i, int *inft_counter);
void	ft_putchar(char c, int *inft_counter);
void	ft_putstr(char *a, int *inft_counter);

#endif