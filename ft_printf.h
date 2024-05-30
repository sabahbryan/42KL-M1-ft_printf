/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryaloo <bryaloo@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:33:41 by bryaloo           #+#    #+#             */
/*   Updated: 2024/04/26 19:12:39 by bryaloo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

// Mimics the behavior of the standard printf function
int		ft_printf(const char *type, ...);
int		ft_conversion(va_list args, const char type);

// Conversion functions
int		print_char(char c);
int		print_str(char *str);
int		print_ptr(unsigned long long ptr);
int		print_nbr(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int num, const char type);
int		print_percent(void);

// Helper functions
int		hex_len(unsigned int num);
void	put_hex(unsigned int num, const char type);
int		ptr_len(uintptr_t num);
void	put_ptr(uintptr_t num);
int		num_len(unsigned int num);
char	*unsigned_itoa(unsigned int n);
void	put_str(char *str);

#endif
