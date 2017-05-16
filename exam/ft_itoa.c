#include <stdlib.h>

char *ft_itoa(int nbr)
{
  char *str;
  int neg;

  neg = 1;
  str = (char *)malloc(sizeof(char) * 15);
  if(nbr == -2147483648)
    {
      str = "-2147483648";
      return(str);
    }
  if(nbr < 0)
    {
      neg = -1;
      nbr = nbr * -1;
    }
  *--str = '0' + nbr % 10;
  nbr = nbr / 10;
  while(nbr != 0)
    {
      *--str = '0' + nbr % 10;
      nbr = nbr / 10;
    }
  if(neg == -1)
    *--str = '-';
  return(str);
}