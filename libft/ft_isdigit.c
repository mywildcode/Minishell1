/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ql-eilde <ql-eilde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:25:40 by ql-eilde          #+#    #+#             */
/*   Updated: 2014/11/06 11:01:12 by ql-eilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	int		i;

	i = c;
	if (i >= '0' && i <= '9')
	{
		return (1);
	}
	else
		return (0);
}
