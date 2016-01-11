/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:06:42 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/11 09:29:20 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SQRT_MAGIC_F 0x5f3759df 

float				ft_sqrt(const float x)
{
	const float 	xhalf = 0.5f*x;

	union
	{
		float		x;
		int			i;
	}				u;

	u.x = x;
	u.i = SQRT_MAGIC_F - (u.i >> 1);
	return (x * u.x * (1.5f - xhalf * u.x * u.x)); 
}
