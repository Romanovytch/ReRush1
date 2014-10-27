/*
** my_get_nbr.c for my_get_nbr in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Fri Oct 17 11:43:11 2014 Florian Givernaud
** Last update Sun Oct 26 17:23:35 2014 Florian Givernaud
*/

int	str_number_pos(char *str)
{
  int	signe;
  int	pos;

  signe = 1;
  pos = 0;
  while(str[pos] == '+' || str[pos] == '-')
    {
      if (str[pos] == '-')
        {
          signe = signe * -1;
        }
      pos = pos + 1;
    }
  return (signe * pos);
}

int	my_getnbr(char *str)
{
  int	nbr;
  int	signe;
  int	first_number;

  nbr = 0;
  signe = 1;
  first_number = str_number_pos(str);
  if (first_number < 0)
    {
      first_number = first_number * -1;
      signe = -1;
    }
  str = str + first_number;
  while (*str >= '0' && *str <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (*str - '0');
      str = str + 1;
    }
  return (nbr * signe);
}
