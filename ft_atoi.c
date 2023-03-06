/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:16:39 by paula             #+#    #+#             */
/*   Updated: 2023/03/06 21:52:48 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
    int     signal;
    int     result;

    signal = 1;
    result = 0;
    while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
        nptr++;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
        {
            signal = signal * -1;
        }
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9')
    {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }
    return (result * signal);
}
