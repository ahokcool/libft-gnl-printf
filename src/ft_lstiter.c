/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:11:36 by astein            #+#    #+#             */
/*   Updated: 2024/02/25 18:35:53 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_gnl_printf.h"

/**
 * @brief	Iterates the list 'lst' and applies the function 'f' on the content
 * 			of each node.
 * 
 * @param	lst The address of a pointer to a node.
 * @param	f	The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
