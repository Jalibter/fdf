/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:36:25 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/11 11:57:43 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				put_pixel(t_img *img, t_vec2 p, int color)
{
	char			*pixel;

	if ((p.x < img->width && p.x < img->height) && (p.x >= 0 && p.y >= 0))
	{
		pixel = img->data + p.y * img->size_line + (img->bpp / 8) * p.x;
		pixel[2] = (char)(color >> 16);
		pixel[1] = (char)(color >> 8);
		pixel[0] = (char)(color);
	}
}

void				draw_tall_line(t_img *img, t_vec2 a, t_vec2 b, int color)
{

}

void				draw_line(t_img *img, t_vec2 a, t_vec2 b, int color)
{
	t_vec2			d;
	int				e;

	if ((d.x = b.x - a.x) != 0)
		if (d.x > 0)
		{
			d.x *= 2;
			d.y *= 2;
			if ((d.y = b.y - a.y) != 0)
				if (d.y > 0)
					if (d.x >= d.y)
					{
						e = d.x / 2;
						while (1)
						{
							put_pixel(img, a, color);
							if ((++a.x) == b.x)
								break ;
							if ((e -= d.y) < 0)
							{
								++a.y;
								e += d.x;
							}
						}
					}
					else
					{
						e = d.y / 2;
						while (1)
						{
							put_pixel(img, a, color);
							if ((++a.y) == b.y)
								break ;
							if ((e -= d.x) < 0)
							{
								++a.x;
								e += d.y;
							}
						}
					}
				else
				{
					if (d.x >= -d.y)
					{
						e = d.x / 2;
							while (1)
							{
								put_pixel(img, a, color);
								if ((++a.x) == b.x)
									break ;
								if ((e += d.y) < 0)
								{
									--a.y;
									e += d.x;
								}
							}
					}
					else
					{
						e = d.y / 2;
						while (1)
						{
							put_pixel(img, a, color);
							if ((++a.y) == b.y)
								break ;
							if ((e += d.x) > 0)
							{
								++a.x;
								e += d.y;
							}
						}
					}
				}
			else
				while ((++a.x) != b.x)
					put_pixel(img, a, color);

		}
		else if ((d.y = b.y - a.y) != 0)
			if (d.y > 0)
			{
				d.x *= 2;
				d.y *= 2;
				if (-d.x >= d.y)
				{
					e = d.x / 2;
					while (1)
					{
						put_pixel(img, a, color);
						if ((++a.x) == b.x)
							break ;
						if ((e += d.y) >= 0)
						{
							++a.y;
							e += d.x;
						}
					}
				}
				else
				{
					e = d.y / 2;
					while (1)
					{
						put_pixel(img, a, color);
						if ((++a.y) == b.y)
							break ;
						if ((e += d.x) <= 0)
						{
							++a.x;
							e += d.y;
						}
					}
				}
			}
			else 
				if (d.x <= d.y)
				{
					d.x *= 2;
					d.y *= 2;
					e = d.x / 2;
					while (1)
					{
						put_pixel(img, a, color);
						if ((++a.x) == b.x)
							break ;
						if ((e -= d.y) >= 0)
						{
							--a.y;
							e += d.x;
						}
					}
				}
				else
				{
					d.x *= 2;
					d.y *= 2;
					e = d.y / 2;
					while (1)
					{
						put_pixel(img, a, color);
						if ((--a.y) == b.y)
							break ;
						if ((e -= d.x))
						{
							--a.x;
							e += d.y;
						}
					}
				}
		else
			while ((--a.x) != b.x)
				put_pixel(img, a, color);
	else
		if ((d.x = b.y - a.y) != 0)
		{
			if (d.y > 0)
				while ((++a.y) != b.y)
					put_pixel(img, a, color);
			else
				while ((--a.y) != b.y)
					put_pixel(img, a, color);
		}
}
