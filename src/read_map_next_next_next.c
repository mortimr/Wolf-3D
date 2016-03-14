/*
** read_map_next_next_next.c for read_map_next_next_next in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 14:34:12 2015 Iulian Rotaru
** Last update Sun Dec 27 20:50:23 2015 Iulian Rotaru
*/

#include <lapin.h>
#include "wolf.h"

int	get_char_pos(char **argv, t_wolf *data, t_bunny_ini *ini)
{
  if (bunny_ini_get_field
      (ini, argv[2], "start_position", 0) == NULL)
    return (failed_reading(argv[1], argv[2], "start_position", 0));
  data->x_pos =
    my_getnbr(bunny_ini_get_field
	      (ini, argv[2], "start_position", 0));
  if (bunny_ini_get_field
      (ini, argv[2], "start_position", 1) == NULL)
    return (failed_reading(argv[1], argv[2], "start_position", 1));
  data->y_pos =
    my_getnbr(bunny_ini_get_field
	      (ini, argv[2], "start_position", 1));
  if (data->tab[data->y_pos][data->x_pos] == 1)
    return (failed_reading(argv[1], argv[2], "start_position", 1));
  return (get_char_angle(argv, data, ini));
}

int	get_tile_size(char **argv, t_wolf *data, t_bunny_ini *ini)
{
  if (bunny_ini_get_field
      (ini, argv[2], "tile_size", 0) == NULL)
    return (failed_reading(argv[1], argv[2], "tile_size", 0));
  data->tile_size =
    my_getnbr(bunny_ini_get_field(ini, argv[2],
				  "tile_size", 0));
  if (data->tile_size < 20 || data->tile_size > 70)
    data->tile_size = 50;
  return (get_char_pos(argv, data, ini));
}

int	big_alloc(t_wolf *data)
{
  if ((data->tab =
       bunny_malloc(sizeof(int*)
		    * (data->map_height + 1))) == NULL)
    return (alloc_fail());
  return (0);
}

int	small_alloc(t_wolf *data, int col)
{
  if ((data->tab[col] =
       bunny_malloc(sizeof(int)
		    * (data->map_width + 1))) == NULL)
    return (alloc_fail());
  return (0);
}

int	check_read(t_bunny_ini *ini, char **argv, int extractor)
{
  if ((bunny_ini_get_field
       (ini, argv[2], "data", extractor)) == NULL)
    return (failed_reading(argv[1], argv[2], "data", extractor));
  return (0);
}
