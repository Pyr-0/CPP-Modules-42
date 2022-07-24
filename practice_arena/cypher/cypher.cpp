#include <iostream>

// The following program cyphers text into the ASCII code number value! :)
int main(int argc, char *argv[])
{
	char c1, c2, c3, c4, c5;
	(void)argv;
	if (argc >= 2)
	{
		std::cout<<"\e[3m\e[32mwrong arguments"<<std::endl;
		return 1;
	}
	std::cout<<"Enter 4 letters: ";
	std::cin >> c1 >> c2 >> c3 >> c4 >> c5;
	std::cout << "ASCII Message: " << static_cast<int>(c1) << " "<< int(c2) << " "<< int(c3) << " "
								<< int(c4) << " "<< int(c5) << " " << std::endl;

	return 0;
}

// static_cast<int>(c1);
// reinterpret_cast<int>(c1)