# ex01: My Awesome PhoneBook

## feature

### user
- [x] get input from user: ADD, SEARCH, or EXIT
- [x] ignore other input 
	- ADD
		- [x] prompt to input info of the new contact info at a time
		- [x] once completed, add contact to the phonebook
			- [x] if number of contacts is greater than 8, the actual info replaces oldest one
	- SEARCH
		- [x] display saved contact as a list of 4 columns: index, firstname, lastname, nickname
			- [x] columns:  10 chars wide for each, with delimiter pipe(|) 
			- [x] text : right-aligned
			- [x] text : if longer than column, truncate and the last displayable char must be replaced by a dot(.)
		- [x] prompt again for the index of the entry to display
			- [x] if valid index, display the contact info, one file per line
			- [x] if invalid, define a relevant behavior
	- EXIT
		- [x] quits program
		- [ ] delete contacts
		- [x] after execution of ADD, SEARCH, program waits for another one, untill user inputs EXIT

### contact (class)
- contains contact info
	- [x] field: firstname, lastname, nickname, phone number, darkest secret
	- [x] no empty fields can be saved
	- [!] index: necessary in contact?

### phonebook (class)
- [x] store max 8 contacts
	- [x] if 9th contact is added, it replaces the oldest one

## checklist
- [ ] no dynamic allocation
	- "std::string" is allowed(slack said yes)
- [ ] diffrentiate class's elements: private, public

## last touch : error
- [ ] when ctrl+D is typed, should terminated normally&cleanly