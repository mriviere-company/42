/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 16:01:22 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/02 16:01:24 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_map(t_env *e)
{
	e->map = (char **)malloc(sizeof(char*) * 18 + 1);
	e->map[0] = ft_strdup("111111111111111111111111");
	e->map[1] = ft_strdup("101000000000000000000001");
	e->map[2] = ft_strdup("10P000000000000222000001");
	e->map[3] = ft_strdup("1010000000000002T2000001");
	e->map[4] = ft_strdup("101000000000000202000001");
	e->map[5] = ft_strdup("1010000000000002P2000001");
	e->map[6] = ft_strdup("101000000000000000000001");
	e->map[7] = ft_strdup("101111111111110000000001");
	e->map[8] = ft_strdup("2P2222211111110000000001");
	e->map[9] = ft_strdup("200000100000010000000001");
	e->map[10] = ft_strdup("200000P00000010000000001");
	e->map[11] = ft_strdup("222222100000011111P11111");
	e->map[12] = ft_strdup("200002111111112222022222");
	e->map[13] = ft_strdup("200002222222200000000002");
	e->map[14] = ft_strdup("200000000000P00000000002");
	e->map[15] = ft_strdup("200000000000200000000002");
	e->map[16] = ft_strdup("D00000000000200000000002");
	e->map[17] = ft_strdup("222222222222222222222222");
	e->map[18] = NULL;
}

int		expose_hook(t_env *e)
{
	ft_init_raycasting(e);
	ft_draw_stamina(e);
	mlx_put_image_to_window(e->mlx, e->win, e->ptri, 0, 0);
	return (0);
}

int		uptade(t_env *e)
{
	expose_hook(e);
	return (e->posx);
}

int		main(void)
{
	t_env e;

	e.text = 0;
	e.staminamax = 100;
	e.stamina = e.staminamax;
	ft_init_env(&e);
	ft_init_map(&e);
	ft_init_mlx(&e);
	ft_init_render(&e);
	return (0);
}
