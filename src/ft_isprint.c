/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:48:31 by astein            #+#    #+#             */
/*   Updated: 2024/02/25 18:35:53 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_gnl_printf.h"

/**
 * @brief	This Function checks if 'c' is any printable char (including space)
 * 
 * @param	c 
 * @return	int
 * 				1 = true
 * 				0 = false
 */
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
