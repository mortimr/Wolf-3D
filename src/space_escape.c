/*
** space_escape.c for space_escape.c in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 15:18:00 2015 Iulian Rotaru
** Last update Mon Mar 14 09:48:12 2016 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

int	escape_key(t_wolf *wolf)
{
  (void) wolf;
  return (EXIT_ON_SUCCESS);
}

int	space_key(t_wolf *wolf)
{
  if (wolf->left_click == 0)
    {
      bunny_sound_stop((t_bunny_sound *)wolf->fire);
      wolf->left_click = 1;
    }
  else if (wolf->left_click == 1)
    {
      bunny_sound_play((t_bunny_sound *)wolf->lighting);
      bunny_sound_play((t_bunny_sound *)wolf->fire);
      wolf->left_click = 0;
    }
  return (GO_ON);
}
