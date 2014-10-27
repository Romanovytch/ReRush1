/*
** my_init.c for init in /home/givern_f/Modules/Prog-Elem-C/mariokart/sources
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Sun Oct 26 15:22:57 2014 Florian Givernaud
** Last update Sun Oct 26 16:46:28 2014 Florian Givernaud
*/

#include <stdlib.h>

void	aff_char(int **tab, int i, int j)
{
  if (tab[i][j] == 1)
    my_putchar('%');
  else if (tab[i][j] == 2)
    my_putchar('o');
  else if (tab[i][j] == 3)
    my_putchar('M');
  else if (tab[i][j] == 4)
    my_putchar('A');
  else
    my_putchar(' ');
}

int	*init_tab(int ***tab, int x, int size, int *pos)
{
  int	nb;

  srand(time(NULL));
  pos[0] = rand() % ((size / 2 - 3) - 2) + 2;
  (*tab)[x - 2][pos[0]] = 1;
  pos[1] = rand() % ((size - 2) - (size / 2 + 3)) + (size / 2 + 3);
  (*tab)[x - 2][pos[1]] = 1;
  add_kart(tab, x, size);
  return (pos);
}

void	init_line(int ***tab, int *pos, int x, int size)
{
  int	rd;
  int	i;

  i = x - 3;
  srand(time(NULL));
  while (i > 0)
    {
      rd = rand() % 3;
      if (rd == 0 && pos[0] > 2)
        pos[0] = pos[0] - 1;
      else if (rd == 1 && pos[0] < (size / 2 - 3))
        pos[0] = pos[0] + 1;
      else
        pos[0] = pos[0];
      (*tab)[i][pos[0]] = 1;
      rd = rand() % 3;
      if (rd == 0 && pos[1] > (size / 2 + 3))
        pos[1] = pos[1] - 1;
      else if (rd == 1 && pos[1] < (size - 3))
        pos[1] = pos[1] + 1;
      else
        pos[1] = pos[1];
      (*tab)[i][pos[1]] = 1;
      --i;
    }
}

int	**my_tab_init(int **tab, int x, int y)
{
  int	i;

  i = 0;
  tab =  malloc(x * sizeof(int *));
  while (i < x)
    tab[i++] = malloc(y * sizeof(int));
  return (tab);
}

void	my_free_tab(int ***tab, int x)
{
  int	i;

  i = 0;
  while (i < x)
    free(tab[i++]);
  free(tab);
}
