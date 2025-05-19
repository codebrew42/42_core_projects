#include <iostream>

using std::cout;
using std::endl;

void printLines(int count)
{
	int	i = 0;

	while (i < count)
	{
		cout << endl;
		i++;
	}
}

int main() {
	printLines(3);

}