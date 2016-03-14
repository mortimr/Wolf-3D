/*
** core_next_next_next_next.c for core_next_next_next_next in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:42:00 2015 Iulian Rotaru
** Last update Sun Dec 27 20:59:01 2015 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

void			make_first_snow(t_bunny_pixelarray *pix)
{
  int			x;
  t_bunny_position	pos;
  t_color		white;

  white.full = WHITE;
  pos.y = 0;
  while (pos.y < pix->clipable.clip_height / 2)
    {
      x = 0;
      while (x < 2)
	{
	  pos.x = rand () % pix->clipable.clip_width;
	  tekpixel(pix, &pos, &white);
	  x++;
	}
      pos.y += 1;
    }
}

int	get_text_data(t_bunny_ini *ini,
		      int height ,
		      int width,
		      unsigned int *ptr)
{
  int	i;

  i = 0;
  while (i < height * width)
    {
      if ((bunny_ini_get_field(ini, "pic", "data", i)) == NULL)
	return (1);
      ptr[i] = my_getnbr(bunny_ini_get_field(ini, "pic", "data", i));
      i++;
    }
  return (0);
}

t_bunny_pixelarray	*get_ini_png(char *name, t_bunny_pixelarray *pix)
{
  t_bunny_ini		*ini;
  unsigned int		*ptr;
  int			height;
  int			width;

  if ((ini = bunny_load_ini(name)) == NULL)
    return (NULL);
  if ((bunny_ini_get_field(ini, "pic", "width", 0)) == NULL)
    return (NULL);
  width = my_getnbr(bunny_ini_get_field(ini, "pic", "width", 0));
  if ((bunny_ini_get_field(ini, "pic", "height", 0)) == NULL)
    return (NULL);
  height = my_getnbr(bunny_ini_get_field(ini, "pic", "height", 0));
  if ((pix = bunny_new_pixelarray(width, height)) == NULL)
    return (NULL);
  ptr = (unsigned int*) pix->pixels;
  if (get_text_data(ini, height, width, ptr) == 1)
    return (NULL);
  return (pix);
}

int		*get_keys_tab()
{
  static int	tab[7];

  tab[0] = BKS_SPACE;
  tab[1] = BKS_ESCAPE;
  tab[2] = BKS_W;
  tab[3] = BKS_A;
  tab[4] = BKS_S;
  tab[5] = BKS_D;
  return (tab);
}

void	get_op(t_wolf *wolf)
{
  wolf->op[0] = space_key;
  wolf->op[1] = escape_key;
  wolf->op[2] = w_key;
  wolf->op[3] = a_key;
  wolf->op[4] = s_key;
  wolf->op[5] = d_key;
  wolf->keys = bunny_get_keyboard();
}
