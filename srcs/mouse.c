/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:51:16 by ssallami          #+#    #+#             */
/*   Updated: 2025/04/03 15:29:37 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_zoom(int button, t_fdf *env)
{
	if (button == MOUSE_WHEEL_UP)
		env->camera->zoom += 2;
	else if (button == MOUSE_WHEEL_DOWN)
		env->camera->zoom -= 2;
	if (env->camera->zoom < 1)
		env->camera->zoom = 1;
	ft_draw(env->map, env);
}

int	ft_mouse_down(int button, int x, int y, void *params)
{
	t_fdf	*env;

	(void)x;
	(void)y;
	env = (t_fdf *)params;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
		ft_zoom(button, env);
	return (0);
}
