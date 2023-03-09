/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:35:56 by paula             #+#    #+#             */
/*   Updated: 2023/03/09 09:05:05 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    //char    *copy;
    //size_t  s1_len;

    //s1_len = ft_strlen(s1) + 1;
    ft_strchr(set, *s1); // == null que nao tem, != null que s1[i] esta em set e.g set = " !" e s[i] = ' '
    /**
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
    return (0);
}