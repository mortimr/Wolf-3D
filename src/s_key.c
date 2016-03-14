/*
** s_key.c for s_key in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:24:48 2015 Iulian Rotaru
** Last update Sun Dec 27 21:01:12 2015 Iulian Rotaru
*/

#include <lapin.h>
#include <math.h>
#include "wolf.h"

int	s_key_x_check(t_wolf *wolf)
{
  if ((wolf->tab[(int) wolf->y]
       [(int) (wolf->x - cos(wolf->angle * M_PI / 180) / 8.0)] == 1) ||
      (wolf->x - cos(wolf->angle * M_PI / 180) / 8.0 > wolf->map_width) ||
      (wolf->x - cos(wolf->angle * M_PI / 180) / 8.0 < 0))
    {
      if ((wolf->tab[(int) (wolf->y - sin(wolf->angle * M_PI / 180) / 8.0)]
	   [(int) (wolf->x)] == 0) &&
	  (wolf->y - sin(wolf->angle
			 * M_PI / 180) / 8.0 < wolf->map_height - 1) &&
	  (wolf->y - sin(wolf->angle * M_PI / 180) / 8.0 > 0))
	wolf->y = wolf->y - sin(wolf->angle * M_PI / 180) / 8.0;
      return (1);
    }
  return (0);
}

int	s_key_y_check(t_wolf *wolf)
{
  if ((wolf->tab[(int) (wolf->y - sin(wolf->angle * M_PI / 180) / 8.0)]
       [(int) (wolf->x)] == 1) ||
      (wolf->y - sin(wolf->angle * M_PI / 180) / 8.0 > wolf->map_height - 1) ||
      (wolf->y - sin(wolf->angle * M_PI / 180) / 8.0 < 0))
    {
      if ((wolf->tab[(int) wolf->y]
	   [(int) (wolf->x - cos(wolf->angle * M_PI / 180) / 8.0)] == 0) &&
	  (wolf->x - cos(wolf->angle * M_PI / 180) / 8.0 < wolf->map_width) &&
	  (wolf->x - cos(wolf->angle * M_PI / 180) / 8.0 > 0))
	wolf->x = wolf->x - cos(wolf->angle * M_PI / 180) / 8.0;
      return (1);
    }
  return (0);
}

int	s_key(t_wolf *wolf)
{
  if (s_key_x_check(wolf) == 1)
    return (GO_ON);
  else if (s_key_y_check(wolf) == 1)
    return (GO_ON);
  else
    {
      wolf->y = wolf->y - sin(wolf->angle * M_PI / 180) / 8.0;
      wolf->x = wolf->x - cos(wolf->angle * M_PI / 180) / 8.0;
    }
  wolf->x_pos = wolf->x;
  wolf->y_pos = wolf->y;
  return (GO_ON);
}
