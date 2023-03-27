/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:54:31 by paula             #+#    #+#             */
/*   Updated: 2023/03/27 09:53:54 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new;
    t_list  *temp;

    if (!lst)
        return(NULL);  
    new = NULL;
    while (lst != 0)
    {
        temp = ft_lstnew(f(lst->content));
        if (!temp)
        {
            ft_lstclear(&new, del);
            return(NULL);
        }
        ft_lstadd_back(&new, temp);
        lst = lst->next;
    }
    return(new);
}