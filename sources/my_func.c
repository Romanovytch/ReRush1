/*
** my_putstr.c for my_putstr in /home/givern_f/Modules/Prog-Elem-C/mariokart
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Sat Oct 25 19:50:37 2014 Florian Givernaud
** Last update Sun Oct 26 17:19:35 2014 Florian Givernaud
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

void	my_xputstr(char *str)
{
  my_putstr(str);
  exit(EXIT_SUCCESS);
}
