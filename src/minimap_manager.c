/*
** minimap_manager.c for minimap_manager in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed Dec 23 16:32:56 2015 Iulian Rotaru
** Last update Sun Dec 27 17:59:29 2015 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

void	initialise_start(int *start, t_wolf *wolf, int *start_increm)
{
  start_increm[1] = 0;
  start_increm[0] = 0;
  start[2] = 0;
  start[3] = 0;
  if (wolf->y_pos - 5 < 0)
    start[3] = (wolf->y_pos - 5) * - 1;
  else
    start_increm[1] = wolf->y_pos - 5;
  if (wolf->x_pos - 5 < 0)
    start[2] = (wolf->x_pos - 5) * - 1;
  else
    start_increm[0] = wolf->x_pos - 5;
}

void	map_while(t_wolf *wolf, int *inc, int *start_increm, t_color *color)
{
  if (wolf->tab[inc[1]][inc[0]] == 1)
    make_square((inc[2] + inc[0] - start_increm[0]) * 20,
		(inc[3] + inc[1] - start_increm[1]) * 20,
		color[2], wolf);
  if (wolf->tab[inc[1]][inc[0]] == 0)
    make_square((inc[2] + inc[0] - start_increm[0]) * 20,
		(inc[3] + inc[1] - start_increm[1]) * 20,
		color[0], wolf);
}

void		put_map(t_wolf *wolf)
{
  t_color	color[3];
  int		inc[4];
  int		start_increm[2];

  initialise_color(color);
  initialise_start(inc, wolf, start_increm);
  inc[1] = start_increm[1];
  while (inc[3] + inc[1] < wolf->map_height)
    {
      inc[0] = start_increm[0];
      while (inc[2] + inc[0] < wolf->map_width)
	{
	  map_while(wolf, inc, start_increm, color);
	  inc[0] += 1;
	}
      inc[1] += 1;
    }
  make_square((inc[2] + wolf->x_pos - start_increm[0]) * 20,
	      (inc[3] + wolf->y_pos - start_increm[1]) * 20,
	      color[1], wolf);
}

int	minimap_manager(t_wolf *wolf)
{
  make_bg(wolf->minimap);
  put_map(wolf);
  add_pix(wolf, wolf->minimap);
  return (0);
}
