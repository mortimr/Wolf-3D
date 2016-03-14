/*
** vecnorm.c for vecnorm in /home/rotaru_i/Coding/LibLap/gfx_wolf3d
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Fri Dec 25 13:11:16 2015 Iulian Rotaru
** Last update Fri Dec 25 13:35:16 2015 Iulian Rotaru
*/

#include <lapin.h>
#include <math.h>

double	vecnorm(t_bunny_position	*coord0,
		t_bunny_position	*coord1)
{
  return ((double)(sqrt((double)
			(pow((coord1->x - coord0->x), 2))
			+ (double)(pow((coord1->y - coord0->y), 2)))));
}
