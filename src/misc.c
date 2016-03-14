/*
** misc.c for misc in /home/rotaru_i/Coding/LibLap/gfx_fdf2/tcore
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Dec 20 15:35:07 2015 Iulian Rotaru
** Last update Sun Dec 27 17:33:14 2015 Iulian Rotaru
*/

#include <lapin.h>
#include <unistd.h>
#include "wolf.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_getnbr(const char *nb)
{
  int	multi;
  int	out;
  int	i;

  i = my_strlen(nb) - 1;
  multi = 1;
  out = 0;
  while (i >= 0)
    {
      if (nb[i] >= '0' && nb[i] <= '9')
	out += (nb[i] - 48) * multi;
      if (nb[i] == '-')
	out = - out;
      multi *= 10;
      i--;
    }
  return (out);
}

int	my_strcmp(const char *one, const char *two)
{
  int	i;

  i = 0;
  while (one[i] != '\0' && two[i] != '\0')
    {
      if (one[i] != two[i])
	return (one[i] - two[i]);
      i++;
    }
  if (one[i] != '\0' || two[i] != '\0')
    return (1);
  return (0);
}
