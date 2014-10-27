/*
** main.c for main in /home/givern_f/Modules/Prog-Elem-C
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Sat Oct 25 19:44:52 2014 Florian Givernaud
** Last update Sun Oct 26 17:19:00 2014 Florian Givernaud
*/

int	main(int argc, char **argv)
{
  int	x;
  int	y;

  if (argc != 3)
    my_xputstr("Usage: ./MarioKart x y\n");
  y = my_getnbr(argv[1]);
  x = my_getnbr(argv[2]);
  if (x < 15 || x > 50 || y < 15 || y > 50)
    my_xputstr("x and y must be > 15 and < 50\n");
  the_game(x, y);
  return (0);
}
