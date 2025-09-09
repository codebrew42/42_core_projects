#include <iostream>
#include <string>
#include <istream>

using std::cout;
using std::string;
using std::cin;
using std::endl;

/* input: 38.5 195.5 */

// int	main()
// {
// 	double	ch;
// 	cin >> ch;

// 	cout << "output: " << ch << endl;
// }

// int	main()
// {
// 	char	ch[50];
// 	cin >> ch;

// 	cout << "output: " << ch << endl;
// }


int	main()
{
	char	ch[50];
	// cin.getline(ch, 50);

	cin.getline(ch, 50, '.');

	cout << "output: " << ch << endl;

}