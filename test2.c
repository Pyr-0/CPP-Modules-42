#include <stdio.h>
#include <unistd.h>



int main()
{
	int tab [] ={1,2,3,4,5,6,7};
	int size = 6;
	while (size)
	{
		*(tab + size)  = *(tab + size) +48;
		write(1,&tab[size],1);
		size--;
	}
	return 0;
}