/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:20:29 by astein            #+#    #+#             */
/*   Updated: 2024/02/25 18:35:53 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_gnl_printf.h"

/**
 * @brief	This function loopes trough the string 'str' setting all values to 0
 * @param 	str		string which needs to be nulled 
 * @return void*	NULL
 */
void	*gnl_zero_str(char *str)
{
	while (*str)
	{
		*str = '\0';
		str++;
	}
	return (NULL);
}

/**
 * @brief	This Function searches for linebreaks '\n' in the string 'str'
 * 
 * @param	str		The string to search in 
 * @param	len		length of the string including '\n'
 * @param flg_nl	set to ft_true if found a '\n'
 * 
 * Examples for BUFFER_SIZE=10:
 * ==============================
 * str			len		flg_nl
 * ------------------------------
 * (null)		0		FALSE
 * a			1		FALSE
 * Hello		5		FALSE
 * Hello\n		6		TRUE
 * \n			1		TRUE
 * Hello Worl	10		FALSE
 */
void	gnl_len_nl(char *str, size_t *len, t_bool *flg_nl)
{
	if (!str)
		return ;
	*len = 0;
	while (str[*len])
	{
		if (str[*len] == '\n')
		{
			*flg_nl = ft_true;
			(*len)++;
			return ;
		}
		(*len)++;
	}
}

/**
 * @brief	This function concatenates the string 'line' and 'len_cpy'
 * 			characters of the string 'buffer'; The then NULL-terminated result
 * 			will be returned.
 * 			The old string 'line' will be freed and the space for the new
 * 			string 'new_line' will be malloced.
 * 
 * @param 	line		old string where to append the new 'buffer' part
 * 						(will be freed)	
 * @param 	len_line 	length of the old string 'line'
 * @param 	buffer 		string to append to 'line' (size: always BUFFER_SIZE+1)
 * @param 	len_cpy		amount of chars to copy from 'buffer'
 * @return 	char* 		resulting string (NULL terminated)
 * 						NULL if allocations fails
 */
char	*gnl_safe_buffer(char *line, size_t len_line, char *buffer,
		size_t len_cpy)
{
	char	*new_line;
	size_t	i_line;
	size_t	i_buffer;

	new_line = malloc(sizeof(char) * (len_line + len_cpy + 1));
	if (!new_line)
		return (NULL);
	i_line = -1;
	while (++i_line < len_line)
		new_line[i_line] = line[i_line];
	free(line);
	i_buffer = -1;
	while (++i_buffer < len_cpy)
		new_line[i_line++] = buffer[i_buffer];
	new_line[i_line] = '\0';
	return (new_line);
}

/**
 * @brief	This function shifts all elements of the char array 'arr' forwards
 * 			by 'offset' elements. Empty spaces will be filled with null chars.
 * 			EXAMPLE (offset=3)
 * 			before:	4	3	2	1	c	b	a	\0	\0	\0
 * 			after:	1	c	b	a	\0	\0	\0	\0	\0	\0
 * 
 * @param	buffer	array of chars which should be shifted
 * @param	offset 	amount of elements to shift
 */
void	gnl_shift_arr_to_front(char *arr, size_t offset)
{
	size_t	i_buffer;
	size_t	i_offset;

	i_buffer = 0;
	while (i_buffer <= BUFFER_SIZE)
	{
		i_offset = i_buffer + offset;
		if (i_offset >= BUFFER_SIZE)
			arr[i_buffer] = '\0';
		else
		{
			arr[i_buffer] = arr[i_offset];
			arr[i_offset] = '\0';
		}
		i_buffer++;
	}
}
