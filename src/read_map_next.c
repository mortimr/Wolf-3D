/*
** read_map_next.c for read_map_next in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 27 14:21:54 2015 Iulian Rotaru
** Last update Sun Dec 27 17:34:44 2015 Iulian Rotaru
*/

#include <lapin.h>
#include <unistd.h>
#include "wolf.h"

int	argc_error()
{
  write(2, "Usage : ./wolf3d file_name scope_name\n", 39);
  return (1);
}

int	no_such_file(char *name)
{
  write(2, name, my_strlen(name));
  write(2, ": No such file !\n", 18);
  return (1);
}

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_put_nbr_error(int nb)
{
  if (nb < 0)
    {
      my_putchar_error('-');
      nb = - nb;
    }
  if (nb >= 10)
    my_put_nbr_error(nb / 10);
  my_putchar_error(nb % 10 + 48);
}

int	failed_reading(char *name, char *scope, char *field, int index)
{
  write(2, name, my_strlen(name));
  write(2, ": failed reading at scope : \"", 29);
  write(2, scope, my_strlen(scope));
  write(2, "\" || field : \"", 14);
  write(2, field, my_strlen(field));
  write(2, "\" || at index : \"", 18);
  my_put_nbr_error(index);
  write(2, "\"\n", 2);
  return (1);
}
