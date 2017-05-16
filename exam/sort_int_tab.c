void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int y;
	int tmp;

	y = 0;
	tmp = 0;
	while(y != size-1)
	{
		if(tab[y] > tab[y+1])
		{
			tmp = tab[y];
			tab[y] = tab[y+1];
			tab[y+1] = tmp;
			y = 0;
		}
		else
			y++;
	}
}
