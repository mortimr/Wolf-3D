/*
** minimap_manager_next.c for minimap_manager_next.c in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 16:09:34 2015 Iulian Rotaru
** Last update Sun Dec 27 20:45:50 2015 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

void		make_bg(t_bunny_pixelarray *pix)
{
  int		i;
  unsigned int	*ptr;

  i = 0;
  ptr = (unsigned int*) pix->pixels;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      ptr[i] = 0x00000000;
      i++;
    }
}

void		*make_square(int x, int y, t_color color, t_wolf *data)
{
  unsigned int	*ptr;
  int		y_i;
  int		x_i;

  y_i = 0;
  x_i = 0;
  ptr = (unsigned int*) data->minimap->pixels;
  if ((x / 20 > 9) || (y / 20 > 9))
    return (NULL);
  while (y_i + y < y + 19)
    {
      x_i = 0;
      while (x_i + x < x + 19)
	{
	  ptr[(y_i + y) *
	      data->minimap->clipable.clip_width + 1 + x + x_i] = color.full;
	  x_i++;
	}
      y_i++;
    }
  return (NULL);
}

void		add_pix(t_wolf *wolf, t_bunny_pixelarray *pix)
{
  int		x;
  int		y;
  unsigned int	*ptr_one;
  unsigned int	*ptr_two;

  x = 0;
  y = 0;
  ptr_one = (unsigned int*) wolf->rendu->pixels;
  ptr_two = (unsigned int*) pix->pixels;
  while (y < pix->clipable.clip_height)
    {
      x = 0;
      while (x < pix->clipable.clip_width)
	{
	  if (ptr_two[y * pix->clipable.clip_width + x] != 0)
	    ptr_one[y * wolf->background->clipable.clip_width + x] =
	      ptr_two[y * pix->clipable.clip_width + x];
	  x++;
	}
      y++;
    }
}

void	initialise_color(t_color *color)
{
  color[0].full = 0x99999999;
  color[1].full = RED;
  color[2].full = 0x55555555;
}
