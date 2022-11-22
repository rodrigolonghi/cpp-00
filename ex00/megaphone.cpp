#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	char	ch;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; j < strlen(argv[i]); j++)
			{
				ch = toupper(argv[i][j]);
				std::cout << ch;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
