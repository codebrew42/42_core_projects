#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::isalpha;
using	std::toupper;

// namespace	Messages
// {
// 	const char* LOUD_NOISE = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
// }

void	capitalizeAndPrint(char *input)
{
	if (!input)
		return ;
	while(*input)
	{
		if(isalpha(*input))
			cout << (char)toupper(*input);
		else
			cout << (char)*input;
		input++;
	}
}


int	main(int ac, char** av)
{
	// using	Messages::LOUD_NOISE;

	if (ac == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return 0;
	}
	int	i = 0;
	while (++i < ac)
	{
		capitalizeAndPrint(av[i]);
	}
	cout << "\n";
}
