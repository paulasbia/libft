/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:58:21 by paula             #+#    #+#             */
/*   Updated: 2023/03/23 08:29:48 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list *new;
    
    new = (t_list*)malloc(sizeof(t_list));
    if (new == 0)
    {
        return(NULL);
    }
    new->content = content;
    new->next = 0;
    return(new);
}
