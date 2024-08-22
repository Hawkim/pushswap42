/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nal-haki <nal-haki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:14 by nal-haki          #+#    #+#             */
/*   Updated: 2024/06/12 17:35:00 by nal-haki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (diff);
		}
		i++;
	}
	if (i < n)
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}
