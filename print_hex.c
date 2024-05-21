/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryaloo <bryaloo@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:23:07 by bryaloo           #+#    #+#             */
/*   Updated: 2024/05/17 19:24:21 by bryaloo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	put_hex(unsigned int num, const char type)
{
	if (num >= 16)
	{
		put_hex(num / 16, type);
		put_hex(num % 16, type);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (type == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (type == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	print_hex(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		put_hex(num, type);
	return (hex_len(num));
}

// (%x) & (%X) Prints a number in hexadecimal (base 16) lowercase and
//             uppercase format.
