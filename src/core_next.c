/*
** core_next.c for core_next in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:29:47 2015 Iulian Rotaru
** Last update Sun Dec 27 20:40:32 2015 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

void	background_manager(t_wolf *data)
{
  snow_it(data->background, data->snow_move);
  add_pix(data, data->background);
}

double		make_radius(double initial)
{
  double	out;

  if (initial - 45 > 0)
    out = initial - 45;
  else
    out = 360 - (45 - initial);
  return (out);
}

int	main_condition(double x, double y, t_wolf *wolf)
{
  if ((x / 200 < wolf->map_width  - wolf->x &&
       x / 200 > - wolf->x - 1) &&
      (y / 200 < wolf->map_height - 1 - wolf->y &&
       y / 200 > - wolf->y) &&
      (wolf->tab[(int) ((wolf->y) + y / 200)]
       [(int) ((wolf->x) + x / 200)] == 0))
    return (0);
  return (1);
}

double	increm_radius(double radius, double *x, double *y)
{
  if (radius + 1.0 >= 360)
    radius = 0.0;
  else
    radius = radius + (1.0 * 90.0) / 480.0;
  *x = 0;
  *y = 0;
  return (radius);
}

int	texture_condi(t_wolf *wolf, double x, double y)
{
  if ((wolf->tab[(int) ((wolf->y) + y / 200)]
       [(int) ((wolf->x) + 1.0 / 200 + x / 200)] == 1) &&
      (wolf->tab[(int) ((wolf->y) + y / 200)]
       [(int) ((wolf->x) - 1.0 / 200 + x / 200)] == 1))
    return (0);
  return (1);
}
