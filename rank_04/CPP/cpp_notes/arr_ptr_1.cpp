#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int	main()
{

	int* p = new int(42); //create + default init with 0
	cout << " p:" << p << endl;
	cout << "*p:" << *p << endl;

	int size = 5;
	int* arr = new int[size];
	int i = -1;
	while (++i < size)
	{
		cout << "arr[" << i << "]: " << arr[i] << endl;
	}

	/*
	while (i < arr.size())
	{
			cout << " arr[" << i << "]: " << arr[i] << endl;
	}
	//arr.size() is possible with class
	*/

	std::vector<int> array(5);
	for (int i = 0; i < array.size(); i++) // .size() works here
	{
		cout << " array[" << i << "]: " << array[i] << endl;
	}

	delete p;
	delete[] arr;
	//delete array;
	// std::vector manages its own mem and doesn't need deletion

}