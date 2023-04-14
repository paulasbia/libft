/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:15:28 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/11 14:16:49 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
	}
	while (n > 9 || n < -9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_print(char *result, int n, int n_len)
{
	int	digit;

	digit = n % 10;
	if (digit < 0)
	{
		digit = digit * -1;
	}
	if (n > 9 || n < -9)
	{
		ft_print(result, n / 10, n_len - 1);
	}
	digit = digit + 48;
	result[n_len] = digit;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n_len;

	n_len = len(n);
	result = (char *)malloc(sizeof(char) * n_len + 1);
	if (result == 0)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	result[n_len] = 0;
	n_len--;
	ft_print(result, n, n_len);
	return (result);
}
