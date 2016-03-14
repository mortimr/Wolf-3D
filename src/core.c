/*
** core.c for core in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:27:48 2015 Iulian Rotaru
** Last update Fri Jan 15 19:06:38 2016 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data)
{
  t_wolf		*wolf;

  wolf = (t_wolf*) data;
  wolf->keys = bunny_get_keyboard();
  if (sym == BKS_SPACE && state == GO_DOWN)
    space_key(wolf);
  return (GO_ON);
}

t_bunny_response	mouse_move(const t_bunny_position *relative,
				   void *data)
{
  t_wolf		*wolf;
  double		x_move;

  if (relative->x < -25)
    x_move = - 25.0 / 2.0;
  else if (relative->x > 25)
    x_move = 25.0 / 2.0;
  else
    x_move = (double) relative->x / 2.0;
  wolf = (t_wolf*) data;
  if (wolf->angle - x_move > 360.0)
    wolf->angle =  (x_move + wolf->angle);
  else if (wolf->angle - x_move < 0.0)
    wolf->angle = x_move + (360.0 + wolf->angle);
  else
    wolf->angle = wolf->angle + x_move;
  wolf->snow_move = relative->x;
  return (GO_ON);
}

void	neg_move(t_bunny_pixelarray *pix, int snow_move, unsigned int *ptr)
{
  int	i;

  i = 0;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height / 2)
    {
      if (ptr[i - snow_move * 20] == 0xFFFFFFFF)
	{
	  ptr[i - snow_move * 20] = 0x00000000;
	  ptr[i] = 0xFFFFFFFF;
	}
      i++;
    }
}

void	pos_move(t_bunny_pixelarray *pix, int snow_move, unsigned int *ptr)
{
  int	i;

  i = pix->clipable.clip_width * pix->clipable.clip_height / 2;
  while (i > 0)
    {
      if (ptr[i] == 0xFFFFFFFF && i / pix->clipable.clip_width
	  == pix->clipable.clip_height - 2)
	ptr[i] = 0x00000000;
      if (ptr[i - snow_move * 20] == 0xFFFFFFFF)
	{
	  ptr[i - snow_move * 20] = 0x00000000;
	  ptr[i] = 0xFFFFFFFF;
	}
      i--;
    }
}

void		snow_it(t_bunny_pixelarray *pix, int snow_move)
{
  unsigned int	*ptr;

  ptr = (unsigned int*) pix->pixels;
  if (snow_move < 0)
    neg_move(pix, snow_move, ptr);
  else
    pos_move(pix, snow_move, ptr);
}
