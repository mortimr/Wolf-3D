/*
** tekline_three.c for tekline_three in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 14:17:49 2015 Iulian Rotaru
** Last update Sun Dec 27 20:51:48 2015 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

void	i_love_norm_three(int i, t_wolf *wolf, t_color *color)
{
  if (i % 12 == 0 && wolf->left_click == 0)
    color->full -= 0x01010101;
  if (wolf->left_click == 1)
    color->full = 0x11111111;
}

void			tekline_three(t_bunny_pixelarray *pix,
				      t_bunny_position *coord,
				      t_wolf *wolf)
{
  t_bunny_position	pos;
  double		coef_x;
  double		coef_y;
  double		x;
  double		y;
  double		len;
  int			i;
  t_color		color;

  i = 0;
  tmpline(coord, &x, &y, &len);
  coef_x = (coord[1].x - x) / len;
  coef_y = (coord[1].y - y) / len;
  color.full = 0x33333333;
  while (i <= (int) len)
    {
      i_love_norm_three(i, wolf, &color);
      norm_is_amazing(&pos, &x, &y);
      tekpixel(pix, &pos, &color);
      x += coef_x;
      y += coef_y;
      i++;
    }
}
