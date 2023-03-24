/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:54:31 by paula             #+#    #+#             */
/*   Updated: 2023/03/24 13:38:52 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new;
    t_list  *temp;

    if (!lst)
        return(NULL);  
    temp = lst;
    while (lst != 0)
    {
        ft_lstiter(temp->content, f);
        new = temp;
        if (!new)
        {
            ft_lstclear(&new, del);
        }
        lst = lst->next;
        temp = lst;
    }
    return(new);
}