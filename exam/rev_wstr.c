#include <unistd.h>
void ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_len(char *str)
{
  int y;

  y = 0;
  while(str[y] != '\0')
    y++;
  return(y+2);
}

int ft_reverse(char *str)
{
  int x;
  int y;

  x = 0;
  y = ft_len(str);
  while(y >= 0)
    {
      if(str[y] == ' ' || str[y] == '\t' || y == 0)
	{
	  x = y;
	  if(y != 0)
	    y++;
	  while(str[y] != ' ' && str[y] != '\t' && str[y] != '\0')
	    {
	    ft_putchar(str[y]);
	    if(str[y] != '\0')
	      y++;
	    else
	      break;
	    }
	  if(x != 0)
	    ft_putchar(' ');
	  y = x - 1;
	}
      if(y != 0)
	y--;
    }
  return(0);
}

int main(int argc, char **argv)
{
  if(argc == 2)
    ft_reverse(argv[1]);
  ft_putchar('\n');
  return(0);
}
