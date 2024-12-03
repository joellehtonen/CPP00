#include <iostream> //for std::cout
#include <cctype> //for toupper
#include <string> //for std::str

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else if (argc > 0)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (int j = 0; j < str.length(); j++)
			{
				str[j] = toupper(str[j]);
			}
			std::cout << str << " ";
		}
		std::cout << "\n";
	}
}