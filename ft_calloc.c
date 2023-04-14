/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:08:08 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/11 14:08:35 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	totalsize;

	totalsize = (nmemb * size);
	ptr = malloc(totalsize);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, totalsize);
	return (ptr);
}
