# ex01: My Awesome PhoneBook

## feature

### user
- [x] get input from user: ADD, SEARCH, or EXIT
- [x] ignore other input 
	- ADD
		- [ ] prompt to input info of the new contact info at a time
		- [ ] once completed, add contact to the phonebook
	- SEARCH
		- [ ] display saved contact as a list of 4 columns: index, firstname, lastname, nickname
		- [ ] columns:  10 chars wide for each, with delimiter pipe(|) 
		- [ ] text : right-aligned
		- [ ] text : if longer than column, truncated and the last displayable char must be replaced by a dot(.)
	- EXIT
		- [ ] quits program
		- [ ] delete contacts
		- [ ] after execution of ADD, SEARCH, program waits for another one, untill user inputs EXIT

### contact (class)
- contains contact info
	- [ ] field: firstname, lastname, nickname, phone number, darkest secret
	- [ ] no empty fields can be saved
	- [!] index: necessary in contact?

### phonebook (class)
- [ ] store max 8 contacts
	- [ ] if 9th contact is added, it replaces the oldest one

## checklist
- [ ] no dynamic allocation
	- "std::string" is allowed(slack said yes)
- [ ] diffrentiate class's elements: private, public
