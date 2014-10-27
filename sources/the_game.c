/*
** the_game.c for the_game in /home/givern_f/Modules/Prog-Elem-C/mariokart
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Sat Oct 25 20:11:43 2014 Florian Givernaud
** Last update Sun Oct 26 17:24:36 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/mariokart.h"

void	my_aff_game(int **tab, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  while (i < x)
    {
      j = 0;
      while (j < y)
	{
	  if (i == 0 || i == (x - 1) || j == 0 || j == (y - 1))
	    my_putchar('#');
	  aff_char(tab, i, j);
	  ++j;
	}
      my_putchar('\n');
      ++i;
    }
}

void	add_kart(int ***tab, int x, int size)
{
  (*tab)[x - 2][size / 2] = 3;
  (*tab)[x - 2][size / 2 - 1] = 2;
  (*tab)[x - 2][size / 2 + 1] = 2;
  (*tab)[x - 3][size / 2] = 4;
  (*tab)[x - 3][size / 2 - 1] = 2;
  (*tab)[x - 3][size / 2 + 1] = 2;
}

void	add_line(int **tab, int **pos, int x, int size)
{
  int	rd;

  srand(time(NULL));
  rd = rand() % 3;
  if (rd == 0 && (*pos)[0] > 2)
    (*pos)[0] = (*pos)[0] - 1;
  else if (rd == 1 && (*pos)[0] < (size / 2 - 3))
    (*pos)[0] = (*pos)[0] + 1;
  else
    (*pos)[0] = (*pos)[0];
  (*tab)[(*pos)[0]] = 1;
  rd = rand() % 3;
  if (rd == 0 && (*pos)[1] > (size / 2 + 3))
    (*pos)[1] = (*pos)[1] - 1;
  else if (rd == 1 && (*pos)[1] < (size - 3))
    (*pos)[1] = (*pos)[1] + 1;
  else
    (*pos)[1] = (*pos)[1];
  (*tab)[(*pos)[1]] = 1;
}

int	**roll_along(int **tab, int x, int y, int **pos)
{
  int	**new_tab;
  int	i;
  int	j;

  i = 0;
  new_tab = malloc(x * sizeof(int *));
  while (i < x)
    new_tab[i++] = malloc(y * sizeof(int));
  i = x - 2;
  while (i > 1)
    {
      j = 0;
      while (j < y)
	new_tab[i][j] = tab[i - 1][j++];
      --i;
    }
  add_line(&new_tab[1], pos, x, y);
  add_kart(&new_tab, x, y);
  return (new_tab);
}

void	the_game(int x, int y)
{
  int	**tab;
  int	i;
  int	j;
  int	*pos;

  i = 0;
  tab = my_tab_init(tab, x, y);
  while (i < x)
    {
      j = 0;
      while (j < y)
	tab[i][j++] = 0;
      ++i;
    }
  pos = malloc(sizeof(int) * 2);
  pos = init_tab(&tab, x, y, pos);
  init_line(&tab, pos, x, y);
  while (42)
    {
      my_putstr("\033[H\033[2J");
      my_aff_game(tab, x, y);
      tab = roll_along(tab, x, y, &pos);
      usleep(500000);
    }
  my_free_tab(&tab, x);
}
