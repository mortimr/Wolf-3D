/*
** core_next_next.c for core_next_next in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:33:36 2015 Iulian Rotaru
** Last update Fri Jan 15 19:10:01 2016 Iulian Rotaru
*/

#include <lapin.h>
#include <math.h>
#include "wolf.h"

void			walls_textures(t_wolf *wolf, double x, double y, int i)
{
  int			j;
  t_bunny_position	pos[2];
  double		dist;

  j = 0;
  dist = sqrt(pow(wolf->x_pos - x, 2) + pow(wolf->y_pos - y, 2));
  while (j < 4)
    {
      pos[0].x = i + j;
      pos[0].y =
	wolf->background->clipable.clip_height / 2.0
	- (500.0 * wolf->tile_size * 10.0 / dist) / 2.0;
      if (pos[0].y <= 0)
	pos[0].y = 0;
      pos[1].x = i + j;
      pos[1].y = wolf->background->clipable.clip_height / 2.0
	+ (500.0 * wolf->tile_size * 10.0 / dist) / 2.0;
      if (pos[1].y >= 1080)
	pos[1].y = 1080;
      if (texture_condi(wolf, x, y) == 0)
	tekline_one(wolf->rendu, pos, wolf);
      else if (wolf->tab[(int) ((wolf->y) + y / 200)]
	       [(int) ((wolf->x) + x / 200)] == 1)
	tekline_two(wolf->rendu, pos, wolf);
      pos[0].x = i + j - 1;
      pos[0].y = 1080;
      tekline_three(wolf->rendu, pos, wolf);
      j++;
    }
}

void		walls_manager(t_wolf *wolf)
{
  double	radius;
  double	x;
  double	y;
  int		i;

  radius = make_radius(wolf->angle);
  i = 0;
  while (i < 1920)
    {
      radius = increm_radius(radius, &x, &y);
      while (main_condition(x, y, wolf) == 0)
	{
	  x = x + cos(radius * M_PI / 180);
	  y = y + sin(radius * M_PI / 180);
	}
      walls_textures(wolf, x, y, i);
      i += 4;
    }
}

void			viseur_maker(t_wolf *wolf)
{
  t_bunny_position	pos[2];
  t_color		red;

  red.full = RED;
  pos[0].x = 950;
  pos[0].y = 540;
  pos[1].x = 970;
  pos[1].y = 540;
  tekline(wolf->rendu, pos, &red);
  pos[0].x = 960;
  pos[0].y = 530;
  pos[1].x = 960;
  pos[1].y = 550;
  tekline(wolf->rendu, pos, &red);
}

void		add_pix_pos(t_wolf *wolf,
			    t_bunny_pixelarray *pix,
			    t_bunny_position *blit)
{
  unsigned int	*ptr;
  unsigned int	*ptrr;
  int		x;
  int		y;
  int		i;

  ptr = (unsigned int*) pix->pixels;
  ptrr = (unsigned int*) wolf->rendu->pixels;
  y = blit->y;
  i = 0;
  while (y < wolf->rendu->clipable.clip_height)
    {
      x = 0;
      while (x < pix->clipable.clip_width)
	{
	  if (ptr[i] != 0)
	    ptrr[y * wolf->rendu->clipable.clip_width
		 + x + 1920 - blit->x] = ptr[i];
	  i++;
	  x++;
	}
      y++;
    }
}

double	left_ray(t_wolf *wolf, double radius)
{
  if (wolf->angle - 30 > 0)
    radius = wolf->angle - 30;
  else
    radius = 360 - (30 - wolf->angle);
  return (radius);
}
