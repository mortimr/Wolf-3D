/*
** core_next_next_next.c for core_next_next_next.c in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:37:31 2015 Iulian Rotaru
** Last update Mon Mar 14 09:48:52 2016 Iulian Rotaru
*/

#include <lapin.h>
#include <math.h>
#include "wolf.h"

double	right_ray(double radius)
{
  if (radius + 60 >= 360)
    radius = 60 + (radius - 360);
  else
    radius = radius + 60;
  return (radius);
}

void			angle_minimap(t_wolf *wolf)
{
  t_bunny_position	pos_one[2];
  t_bunny_position	pos_two[2];
  t_color		color;
  double		radius;

  color.full = RED;
  pos_one[0].x = 5 * 20 + 10;
  pos_one[0].y = 5 * 20 + 10;
  pos_two[0].x = 5 * 20 + 10;
  pos_two[0].y = 5 * 20 + 10;
  radius = 0;
  radius = left_ray(wolf, radius);
  pos_one[1].x = pos_one[0].x + cos(radius * M_PI / 180) * 30;
  pos_one[1].y = pos_one[0].y
    + sin(radius * M_PI / 180) * 30;
  tekline(wolf->rendu, pos_one, &color);
  radius = right_ray(radius);
  pos_two[1].x = pos_two[0].x
    + cos(radius * M_PI / 180) * 30;
  pos_two[1].y = pos_two[0].y
    + sin(radius * M_PI / 180) * 30;
  tekline(wolf->rendu, pos_two, &color);
  pos_two[0].x = pos_one[1].x;
  pos_two[0].y = pos_one[1].y;
  tekline(wolf->rendu, pos_two, &color);
}

void	music_manager(t_wolf *wolf)
{
  if (wolf->left_click == 0 && wolf->music_volume > 0)
    wolf->music_volume -= 2;
  else if (wolf->left_click == 1 && wolf->music_volume < 100)
    wolf->music_volume++;
  bunny_sound_volume((t_bunny_sound *)wolf->music, wolf->music_volume);
}

int	keys_manager(t_wolf *wolf)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (wolf->keys[wolf->the_keys[i]] == 1 && i != 0)
	{
	  if (wolf->op[i](wolf) == EXIT_ON_SUCCESS)
	    return (EXIT_ON_SUCCESS);
	}
      i++;
    }
  return (GO_ON);
}

t_bunny_response	loop(void *data)
{
  t_wolf		*wolf;
  t_bunny_position	pos;

  wolf = (t_wolf*) data;
  if (keys_manager(wolf) == EXIT_ON_SUCCESS)
    return (EXIT_ON_SUCCESS);
  pos.x = 1920 - 1470;
  pos.y = 1080 - 550;
  make_bg(wolf->rendu);
  if (wolf->left_click == 1)
    background_manager(wolf);
  music_manager(wolf);
  walls_manager(wolf);
  minimap_manager(wolf);
  angle_minimap(wolf);
  if (wolf->left_click == 0)
    add_pix_pos(wolf, wolf->weapon, &pos);
  else
    add_pix_pos(wolf, wolf->no_light, &pos);
  viseur_maker(wolf);
  wolf->snow_move = 0;
  bunny_blit(&wolf->win->buffer,
	     &wolf->rendu->clipable, NULL);
  bunny_display(wolf->win);
  return (GO_ON);
}
