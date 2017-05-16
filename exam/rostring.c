#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_len(char *str)
{
  int i;

  i = 0;
  while(str[i] != '\0')
    i++;
  return(i+1);
}

int ft_clone(char *str)
{
  while(*str != '\0')
    {
      if(*str == ' ')
	return(1);
      str++;
    }
  return(0);
}
char *ft_spaceone(char *str)
{
  char *ret;
  int i;
  int x;

  i = 0;
  x = 0;
  ret = malloc(sizeof(char) *ft_len(str));
  while(str[i] == ' ')
    i++;
  while(str[i] != '\0')
    {
      if(str[i] == ' ' && str[i+1] == ' ')
	i++;
      else
	ret[x++] = str[i++];
    }
  if(ret[x] != ' ')
    ret[x] = '\0';
  if(ret[x-1] == ' ')
    ret[x-1] = '\0';
  return(ret);
}

char *ft_reverse(char *str)
{
  char *ret;
  int i;
  int x;
  int y;

  i = 0;
  x = 0;
  y = 0;
  ret = malloc(sizeof(char) *ft_len(str));
  while(str[i] != ' ')
    i++;
  x = i;
  if(str[i] == ' ')
    {
      i++;
      while(str[i] != '\0')
	ret[y++] = str[i++];
      if(str[i] == '\0')
	ret[y++] = ' ';
    }
  i = 0;
  while(i < x)
    {
    ret[y++] = str[i++];
    if(str[i] == ' ')
      ret[y] = '\0';
    }
  return(ret);
}

int ft_rostring(char *str)
{
  int i;

  i = 0;
  if(ft_clone(str) == 0)
    {
      while(str[i] != '\0')
	{
	  ft_putchar(str[i]);
	  i++;
	}
      return(0);
    }
  str = ft_spaceone(str);
  str = ft_reverse(str);
  while(str[i] != '\0')
    {
      ft_putchar(str[i]);
      i++;
    }
  return(0);
}

int main(int argc, char **argv)
{
  if(argc >= 2)
    ft_rostring(argv[1]);
  write(1, "\n", 1);
  return(0);
}
