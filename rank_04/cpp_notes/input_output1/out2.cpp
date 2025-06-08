//out2.cpp -- writes to a file

#include <fstream>
#include <iostream>

void	displayBookInfo(char str[], int year, double priceA, double priceB)
{
	using	namespace std;

    cout.precision(2);       // Set precision to 2 decimal places
    cout << fixed;           // Use fixed-point notation instead of scientific
    cout << showpoint;       // Always show decimal point

	cout << " * * * * Printing Result Starts... * * * * " << endl;
	cout << "Book and title: " << str << endl;
	cout << "Published year: " << year << endl;
	cout << "Original price: " << priceA << " KRW" << endl;
	cout << "Actual price: " << priceB << " KRW" << endl;
	cout << " * * * * Printing Result Ends... * * * * " << endl;

}


//using pointer for int/double : to save after terminating this func
void	getInfoFromConsole(char book[], int* year, double* priceA, double* priceB)
{
	using	namespace std;

	cout << "Enter the title and author of the book: ";
	cin.getline(book, 50);
	cout << "Enter the published year: ";
	cin >> *year;
	cout << "Enter the original price: ";
	cin >> *priceA;
	*priceB = 0.9 * *priceA;
}

// no need to use pointer as param, since it will be saved to outFile
void	saveToOutfile(char book[], int year, double priceA, std::ofstream& outFile)
{
	using	namespace std;

    outFile.precision(2);       // Set precision to 2 decimal places
    outFile << fixed;           // Use fixed-point notation instead of scientific
    outFile << showpoint;       // Always show decimal point

	cout << " * * * * Saving Result To Outfile Starts... * * * * " << endl;
	outFile << "Book and title: " << book << endl;
	outFile << "Published year: " << year << endl;
	outFile << "Original price: " << priceA << " KRW" << endl;
	outFile << "Actual price: " << priceA * 0.9 << " KRW" << endl;
	cout << " * * * * Saving Result To Outfile Ends... * * * * " << endl;
}


int main()
{
	using	namespace std;

	char	book[50];
	int		year = 0;
	double	originalPrice = 0.0;
	double	actualPrice = 0.0;

	ofstream out;
	out.open("bookinfo.txt");
	if (!out)
	{
		cerr << "Error: opening file!" << endl;
		out.close();
		return 1;
	}

	getInfoFromConsole(book, &year, &originalPrice, &actualPrice);
//	saveToOutfile(book, year, originalPrice, out); //no need to : &out, *out

	displayBookInfo(book, year, originalPrice, actualPrice);
	out.close();

}
