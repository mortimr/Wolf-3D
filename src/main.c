/*
** main.c for main in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Dec 22 16:15:55 2015 Iulian Rotaru
** Last update Mon Mar 14 09:47:30 2016 Iulian Rotaru
*/

#include <lapin.h>
#include <math.h>
#include "wolf.h"

int	pixel_arrays(t_wolf *data)
{
  if ((data->minimap =
       bunny_new_pixelarray(200, 200)) == NULL)
    return (EXIT_ON_ERROR);
  if ((data->background =
       bunny_new_pixelarray(1920, 1080)) == NULL)
    return (EXIT_ON_ERROR);
  if ((data->rendu =
       bunny_new_pixelarray(1920, 1080)) == NULL)
    return (EXIT_ON_ERROR);
  return (GO_ON);
}

int	sound_effects_text(t_wolf *data)
{
  if ((data->music =
       bunny_load_music("sound/Christmas_music2004.ogg")) == NULL)
    return (EXIT_ON_ERROR);
  if ((data->fire =
       bunny_load_music("sound/Fire_sound.ogg")) == NULL)
    return (EXIT_ON_ERROR);
  if ((data->lighting =
       bunny_load_effect("sound/Fire_lighting.ogg")) == NULL)
    return (EXIT_ON_ERROR);
  if ((data->weapon =
       get_ini_png("texture/lantern.ini",
		   data->weapon)) == NULL)
    return (EXIT_ON_ERROR);
  if ((data->no_light =
       get_ini_png("texture/lantern_no_light.ini",
		   data->weapon)) == NULL)
    return (EXIT_ON_ERROR);
  return (GO_ON);
}

int	static_datas(t_wolf *data)
{
  data->x = data->x_pos;
  data->y = data->y_pos;
  data->left_click = 1;
  data->snow_move = 0;
  make_bg(data->background);
  make_bg(data->rendu);
  make_first_snow(data->background);
  data->music_volume = 0;
  bunny_sound_play((t_bunny_sound *)data->music);
  bunny_sound_volume((t_bunny_sound *)data->fire, 50);
  bunny_sound_volume((t_bunny_sound *)data->lighting, 100);
  bunny_sound_loop((t_bunny_sound *)data->fire, 1);
  return (GO_ON);
}

int	end_it(t_wolf *data)
{
  bunny_stop(data->win);
  bunny_delete_sound((t_bunny_sound *)data->music);
  bunny_delete_sound((t_bunny_sound *)data->lighting);
  bunny_delete_sound((t_bunny_sound *)data->fire);
  return (EXIT_ON_SUCCESS);
}

int		main(int argc, char **argv)
{
  t_wolf	data;

  set_max_heap_size(40);
  if ((read_file(argc, argv, &data) == 1))
    return (EXIT_ON_ERROR);
  if ((data.win = bunny_start(1920, 1080, 1, "WOLF3D")) == NULL)
    return (EXIT_ON_ERROR);
  if (pixel_arrays(&data) == EXIT_ON_ERROR)
    return (EXIT_ON_ERROR);
  if (sound_effects_text(&data) == EXIT_ON_ERROR)
    return (EXIT_ON_ERROR);
  data.the_keys = get_keys_tab();
  get_op(&data);
  if ((static_datas(&data)) == EXIT_ON_ERROR)
    return (EXIT_ON_ERROR);
  bunny_set_move_response((t_bunny_move) mouse_move);
  bunny_set_key_response((t_bunny_key) key);
  bunny_set_loop_main_function((t_bunny_loop) loop);
  bunny_loop(data.win, 60, &data);
  return (end_it(&data));
}
