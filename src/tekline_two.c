/*
** tekline_two.c for tekline_two in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 14:16:25 2015 Iulian Rotaru
** Last update Sun Dec 27 17:20:12 2015 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

void	i_love_norm_two(int i, t_wolf *wolf, t_color *color, double len)
{
  if (i <= len / 16 && i < 100 && wolf->left_click == 0)
    color->full += 0x00020000;
  if (i < 5 && wolf->left_click == 1)
    color->full += 0x00020000;
}

void			tekline_two(t_bunny_pixelarray *pix,
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
  color.full = 0x15150000;
  while (i <= len)
    {
      i_love_norm_two(i, wolf, &color, len);
      norm_is_amazing(&pos, &x, &y);
      tekpixel(pix, &pos, &color);
      x += coef_x;
      y += coef_y;
      i++;
    }
}
