/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:49:09 by paula             #+#    #+#             */
/*   Updated: 2023/03/27 10:12:21 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;

    if (!lst || !new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    } 
    temp = ft_lstlast(*lst);
    temp->next = new;    
}
