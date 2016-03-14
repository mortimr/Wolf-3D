/*
** read_map.c for read_map in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Dec 22 16:52:32 2015 Iulian Rotaru
** Last update Sun Dec 27 20:46:39 2015 Iulian Rotaru
*/

#include <lapin.h>
#include <unistd.h>
#include "wolf.h"

int	alloc_while(char **argv, t_wolf *data, t_bunny_ini *ini, int *n)
{
  n[2] = 0;
  if (small_alloc(data, n[0]) == 1)
    return (1);
  while (n[2] < data->map_width)
    {
      if (check_read(ini, argv, n[1]) == 1)
	return (1);
      data->tab[n[0]][n[2]] =
	my_getnbr(bunny_ini_get_field(ini, argv[2], "data", n[1]));
      n[1] += 1;
      n[2] += 1;
    }
  return (0);
}

int	alloc_size(char **argv, t_wolf *data, t_bunny_ini *ini)
{
  int	n[5];

  n[1] = 0;
  if (big_alloc(data) == 1)
    return (1);
  n[0] = 0;
  while (n[0] < data->map_height)
    {
      if (alloc_while(argv, data, ini, n) == 1)
	return (1);
      n[0] += 1;
    }
  if (get_tile_size(argv, data, ini) == 1)
    return (1);
  return (0);
}

int		read_file(int argc, char **argv, t_wolf *data)
{
  t_bunny_ini	*ini;

  if (argc <= 2 || argc > 3)
    return (argc_error());
  if ((ini = bunny_load_ini(argv[1])) == NULL)
    return (no_such_file(argv[1]));
  if ((bunny_ini_get_field(ini, argv[2], "height", 0)) == NULL)
    return (failed_reading(argv[1], argv[2], "height", 0));
  data->map_height = my_getnbr(bunny_ini_get_field(ini, argv[2], "height", 0));
  if ((bunny_ini_get_field(ini, argv[2], "width", 0)) == NULL)
    return (failed_reading(argv[1], argv[2], "width", 0));
  data->map_width = my_getnbr(bunny_ini_get_field(ini, argv[2], "width", 0));
  if (data->map_width < 5 || data->map_height < 5)
    return (1);
  return (alloc_size(argv, data, ini));
}
