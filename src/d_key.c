/*
** d_key.c for d_key in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:26:05 2015 Iulian Rotaru
** Last update Sun Dec 27 20:43:49 2015 Iulian Rotaru
*/

#include <lapin.h>
#include <math.h>
#include "wolf.h"

int	d_key_x_check(t_wolf *wolf, double angle)
{
  if ((wolf->tab[(int) wolf->y]
       [(int) (wolf->x - cos(angle * M_PI / 180) / 8.0)] == 1) ||
      (wolf->x - cos(angle * M_PI / 180) / 8.0 > wolf->map_width) ||
      (wolf->x - cos(angle * M_PI / 180) / 8.0 < 0))
    {
      if ((wolf->tab[(int) (wolf->y - sin(angle * M_PI / 180) / 8.0)]
	   [(int) wolf->x] == 0) &&
	  (wolf->y - sin(angle * M_PI / 180)
	   / 8.0 < wolf->map_height - 1) &&
	  (wolf->y - sin(angle * M_PI / 180) / 8.0 > 0))
	wolf->y = wolf->y - sin(angle * M_PI / 180) / 8.0;
      return (1);
    }
  return (0);
}

int	d_key_y_check(t_wolf *wolf, double angle)
{
  if ((wolf->tab[(int) (wolf->y - sin(angle * M_PI / 180) / 8.0)]
       [(int) wolf->x] == 1) ||
      (wolf->y - sin(angle * M_PI / 180)
       / 8.0 > wolf->map_height - 1) ||
      (wolf->y - sin(angle * M_PI / 180) / 8.0 < 0))
    {
      if ((wolf->tab[(int) wolf->y]
	   [(int) (wolf->x - cos(angle * M_PI / 180) / 8.0)] == 0) &&
	  (wolf->x - cos(angle * M_PI / 180) / 8.0 < wolf->map_width) &&
	  (wolf->x - cos(angle * M_PI / 180) / 8.0 > 0))
	wolf->x = wolf->x - cos(angle * M_PI / 180) / 8.0;
      return (1);
    }
  return (0);
}

int		d_key(t_wolf *wolf)
{
  double	angle;

  if (wolf->angle - 90 < 0)
    angle = 360 - (90 - wolf->angle);
  else
    angle = wolf->angle - 90;
  if (d_key_x_check(wolf, angle) == 1)
    return (GO_ON);
  else if (d_key_y_check(wolf, angle) == 1)
    return (GO_ON);
  else
    {
      wolf->x = wolf->x - cos(angle * M_PI / 180) / 8.0;
      wolf->y = wolf->y - sin(angle * M_PI / 180) / 8.0;
    }
  wolf->x_pos = wolf->x;
  wolf->y_pos = wolf->y;
  return (GO_ON);
}
