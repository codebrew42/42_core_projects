#include "AccountInfo.hpp"
using std::cout;

void	printLine()
{
	cout << "\n";
}

int	main()
{
	AccountInfo	account; //calls default const-r == AccountInfo::AccountInfo()
	account = insertAccountInfo();
	printLine();

	printAccoutInfo(account);
	printLine();

	AccountInfo secAccount("1002-145", "4467", "Jieun Park", 9999999);
	printAccoutInfo(secAccount);


}