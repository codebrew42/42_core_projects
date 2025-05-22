# ex02: The Job Of Your Dreams

## Assignment

### given info
- given files: 1992*.log, Account.hpp, tests.cpp
- deconstructor: the order of being called might differ depending on OS, so desctuctors can be called in a reverse orer
- ex02: not mandatory to pass CPP00

### todo
- [ ] write the missing file: Account.cpp
	- can get hint from compiling tests.cpp
- [ ] pass the test : Account.cpp + tests.cpp
	- [ ] output matches perfectly the with 1992*.log, except timestamps

- [ ] find what to add from output
	- main(): is already in test.cpp
	- [ ] write: `Account::displayAccountsInfos()'
	- [ ] write: `Account::displayStatus() const'
	- [ ] write: `Account::makeDeposit(int)'
	- [ ] write:  `Account::makeWithdrawal(int)'
	- [ ] include: `Account::~Account(), Account::Account(int)'
```bash
jin@jin:~/coding/42_core_projects/rank_04/CPP00/code/ex02$ make
g++ -Wall -Wextra -Werror -std=c++98 -c tests.cpp -o tests.o
g++ -Wall -Wextra -Werror -std=c++98 -c account.cpp -o account.o
g++ -Wall -Wextra -Werror -std=c++98 tests.o account.o -o Account #tests.o instead?
/usr/bin/ld: account.o: in function `main':
account.cpp:(.text+0x0): multiple definition of `main'; tests.o:tests.cpp:(.text+0x0): first defined here
/usr/bin/ld: tests.o: in function `main':
tests.cpp:(.text+0x18c): undefined reference to `Account::displayAccountsInfos()'
/usr/bin/ld: tests.cpp:(.text+0x190): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.cpp:(.text+0x194): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.cpp:(.text+0x1f4): undefined reference to `Account::makeDeposit(int)'
/usr/bin/ld: tests.cpp:(.text+0x260): undefined reference to `Account::displayAccountsInfos()'
/usr/bin/ld: tests.cpp:(.text+0x264): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.cpp:(.text+0x268): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.cpp:(.text+0x2c8): undefined reference to `Account::makeWithdrawal(int)'
/usr/bin/ld: tests.cpp:(.text+0x334): undefined reference to `Account::displayAccountsInfos()'
/usr/bin/ld: tests.cpp:(.text+0x338): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.cpp:(.text+0x33c): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.o: in function `void std::_Destroy<Account>(Account*)':
tests.cpp:(.text._ZSt8_DestroyI7AccountEvPT_[_ZSt8_DestroyI7AccountEvPT_]+0x10): undefined reference to `Account::~Account()'
/usr/bin/ld: tests.o: in function `void std::_Construct<Account, int>(Account*, int const&)':
tests.cpp:(.text._ZSt10_ConstructI7AccountiEvPT_RKT0_[_ZSt10_ConstructI7AccountiEvPT_RKT0_]+0x40): undefined reference to `Account::Account(int)'
collect2: error: ld returned 1 exit status
make: *** [Makefile:10: Account] Error 1
```


