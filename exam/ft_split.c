#include <unistd.h>
#include <stdlib.h>

int is_separator(char *s)
{
	if(*s == ' ' || *s == '\t' || *s == '\n')
		return(1);
	return(0);
}

char **ft_split(char *str)
{
	char **tab;
	int startword;
	int i;

	i = 0;
	startword = 0;
	tab = (char **)malloc(sizeof(char *) * 1050);
	while(*str)
	{
		if(*str && (is_separator(str) == 0))
		{
			if(startword == 0)
			{
				startword = 1;
				tab[i] = str;
				str++;
				i++;
			}
			else
				str++;
		}
		else
		{
			if(*str)
			{
				if(startword == 1)
				{
					startword = 0;
					*str =  '\0';
					str++;
					}
				else
					str++;
			}
		}
	}
	tab[i++] = NULL;
	return(tab);
}