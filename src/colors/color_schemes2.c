/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 23:37:18 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	color_psychedelic(int i, int max_i)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.phase = color.t * 15.0;
	color.r = (int)(127.5 + 127.5 * sin(color.phase));
	color.g = (int)(127.5 + 127.5 * sin(color.phase + 2.094));
	color.b = (int)(127.5 + 127.5 * sin(color.phase + 4.188));
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	colors(int i, int max_i, int color_scheme)
{
	if (color_scheme == COLOR_SCHEME_BLUE)
		return (color_blue(i, max_i));
	else if (color_scheme == COLOR_SCHEME_FIRE)
		return (color_fire(i, max_i));
	else if (color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		return (color_psychedelic(i, max_i));
	else if (color_scheme == COLOR_SCHEME_GRAYSCALE)
		return (color_grayscale(i, max_i));
	else
		return (color_classic(i, max_i));
}
