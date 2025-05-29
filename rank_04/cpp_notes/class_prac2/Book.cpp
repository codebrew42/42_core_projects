#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

class Book
{
private:
	string	_title;
	string	_author;
	int		_ratesCounter;
	float*	_rates;

public:
    // Default constructor
    Book() : _title(""), _author(""), _ratesCounter(0), _rates(NULL)
    {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Book(string title, string author)
    {
        cout << "Parameterized constructor called for: " << title << endl;
        _title = title;
        _author = author;
        _ratesCounter = 3;
        _rates = new float[_ratesCounter];
        _rates[0] = 5;
        _rates[1] = 4.4;
        _rates[2] = 3.8;
    }

    // Copy constructor - for deep copying
    Book(const Book& other)
    {
        cout << "Copy constructor called for: " << other._title << endl;
        _title = other._title;
        _author = other._author;
        _ratesCounter = other._ratesCounter;
        
        // Create a new array and copy the values
        _rates = new float[_ratesCounter];
        for (int i = 0; i < _ratesCounter; i++)
        {
            _rates[i] = other._rates[i];
        }
    }

    // Assignment operator - for deep copying
    Book& operator=(const Book& other)
    {
        cout << "Assignment operator called" << endl;
        if (this != &other) // Prevent self-assignment
        {
            // Free existing resources
            delete[] _rates;
            
            // Copy the simple members
            _title = other._title;
            _author = other._author;
            _ratesCounter = other._ratesCounter;
            
            // Allocate new memory and copy the values
            _rates = new float[_ratesCounter];
            for (int i = 0; i < _ratesCounter; i++)
            {
                _rates[i] = other._rates[i];
            }
        }
        return *this;
    }
/*
	Book();
	Book(string title, string author)
	{
		_title = title;
		_author = author;
		_ratesCounter = 3;
		_rates = new float[_ratesCounter];
		_rates[0] = 5;
		_rates[1] = 4.4;
		_rates[2] = 3.8;
 	}*/
	~Book()
	{
		delete[] _rates;
		_rates = NULL;
//		_rates = nullptr; //c++11 and later
	}

};

int main()
{
	Book book1("title111", "author111");
	Book book2("title222", "author222");
	Book book3(book1); //purpose of coping cstrtr

}