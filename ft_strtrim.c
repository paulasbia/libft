/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:35:56 by paula             #+#    #+#             */
/*   Updated: 2023/03/16 11:34:32 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *copy;
    size_t  s1_len;
    int     i;
    int     j;

    i = 0;
    s1_len = ft_strlen(s1);
    while (ft_strchr(set, s1[i]) != NULL)
    {
        i++;
    }
    j = s1_len;
    while (ft_strchr(set, s1[j - 1]) != NULL)
    {
        j--;
    }
    copy = ft_substr(s1, i, j - i);
    // copy = malloc(sizeof(char) * (j - i) + 1);
    // ft_memcpy(copy, &s1[i], (j - i + 1)); 
    return (copy);
}
 /** ft_strchr(set, *s1); // == null que nao tem, != null que s1[i] esta em set e.g set = " !" e s[i] = ' '
     * 
     *  dado s1 = " ! !  abc  !  " e set = " !" resultado final deve ser "abc"
     * 
     *  ft_strchr(" !", s1[0]) != null-> é algo a ser eliminado, logo posso verificar proxima posicao
     *  ft_strchr(" !", s1[1]) != null-> é algo a ser eliminado, logo posso verificar proxima posicao
     *  ...
     *  ft_strchr(" !", s1[i]) -= null -> encontrei o inicio da nova string a ser retornada, vou guardar essa posicao, int x = i
     *   
     *  
     * 
    */