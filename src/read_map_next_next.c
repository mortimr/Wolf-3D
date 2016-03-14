/*
** read_map_next_next.c for read_map_next_next in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 14:32:42 2015 Iulian Rotaru
** Last update Sun Dec 27 20:49:36 2015 Iulian Rotaru
*/

#include <lapin.h>
#include <unistd.h>
#include "wolf.h"

int	alloc_fail()
{
  write(2, "Error: memory allocation fail !\n", 33);
  return (1);
}

int	alloc_size_next(int *n, t_wolf *data)
{
  while (n[2] < data->map_width)
    {
      if ((data->tab[n[0] * n[1]] =
	   bunny_malloc(sizeof(int) * data->map_width * 20)) == NULL)
	return (alloc_fail());
      n[3] = 0;
      while (n[3] < 20)
	{
	  data->tab[n[0] * n[1]][n[2] * n[3]] = n[4];
	  n[3] += 1;
	}
      n[2] += 1;
    }
  return (0);
}

double	my_getdouble_next(int i, const char *nb, double out, double multi)
{
  int	j;

  j = 0;
  while (j < i + 3)
    {
      if (j < i)
	{
	  out += (nb[j] - 48) * multi;
	  multi = multi / 10;
	  j++;
	}
      if (nb[j] == '.')
	j++;
      if (j > i)
	{
	  out += (nb[j] - 48) * multi;
	  multi = multi / 10;
	  j++;
	}
    }
  return (out);
}

double		my_getdouble(const char *nb)
{
  int		i;
  int		j;
  double	multi;
  double	out;

  out = 0;
  i = 0;
  while (nb[i] != '.')
    i++;
  multi = 1;
  j = 0;
  while (j < i - 1)
    {
      multi *= 10;
      j++;
    }
  return (my_getdouble_next(i, nb, out, multi));
}

int		get_char_angle(char **argv, t_wolf *data, t_bunny_ini *ini)
{
  const	char	*test;

  if (bunny_ini_get_field
      (ini, argv[2], "start_position", 2) == NULL)
    return (failed_reading(argv[1], argv[2], "start_position", 2));
  test = bunny_ini_get_field(ini, argv[2], "start_position", 2);
  if (test[0] == '-')
    return (failed_reading(argv[1], argv[2], "start_position", 2));
  data->angle =
    my_getdouble(bunny_ini_get_field(ini, argv[2],
				     "start_position", 2));
  if (data->angle > 360.0)
    data->angle = 90.0;
  return (0);
}
