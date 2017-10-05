/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changecolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 20:05:16 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/18 16:54:38 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(t_data *data, int keycode)
{
	if (keycode == 18)
	{
		data->ic1 = 85 + 35;
		data->ic2 = 105 + 240;
		data->ic3 = 205 + 105;
	}
	if (keycode == 19)
	{
		data->ic1 = 25 + 15;
		data->ic2 = 25 + 20;
		data->ic3 = 205 + 146;
	}
	if (keycode == 20)
	{
		data->ic1 = 25 + 15;
		data->ic2 = 254 + 20;
		data->ic3 = 205 + 146;
	}
	if (keycode == 21)
	{
		data->ic1 = 254 + 15;
		data->ic2 = 24 + 20;
		data->ic3 = 125 + 146;
	}
}
