#include <stdio.h>
#include <unistd.h>


void ft_reverse(int *tab, int size)
{
	int i = 0;
	int tmp;

	while(i<(size/2))
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size-i -1] = tmp;
		i++;
	}
}
int main()
{
	int tab [] ={1,2,3,4,5,6,7};
	int size = 7;
	int i;
	i = 0;
	ft_reverse(tab,size);
	while (i < 7)
	{
		*(tab + i)  = *(tab + i) +48;
		write(1,&tab[i],size);
		i++;
	}
	return 0;
}