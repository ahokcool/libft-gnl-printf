/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:39:45 by astein            #+#    #+#             */
/*   Updated: 2024/02/25 18:35:53 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_gnl_printf.h"

/**
 * @brief	This functions convert char 'c' to lowercase letters
 * 
 * @param	c
 * @return	int
 * 				The value returned is that of the converted letter;
 * 				'c' if the conversion was not possible
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
