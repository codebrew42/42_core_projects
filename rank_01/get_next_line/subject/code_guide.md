# subject_summary
## 1.turn in files
get_next_line.c
get_next_line_utils.c
get_next_line.h

## 2.allowed to use <=> not allowed to use
your libft, read, malloc, free <=>lseek(), Global var

### lseek()
: what is lseek()? 

## 3. how to compile
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c //42: example

## 4. mandatory
### function
- @return (1)the current line that was read (2)NULL, if an error occured
- @behavior
	- read a file from a file descriptor, or read from standard input: behaves the same way
	- read till \n or eof
- @what to use : loop, fd ...
	- using loop, get_next_line() reads text file pointed by fd, one line at a time
- @forbidden : to read the whole file and then process each line

## 5.bonus
- 1. try to use only one static var
- 2. get_next_line(): manage multiple fd at the same time
	- read from a diff fd per call without losing the reading thread of each fd or returning a line from another fd
- 3. append '_bonus.[c/h]' : 
	turn in : get_next_line_bonus.c, get_next_line_bonus.h, get_next_line_utils_bonus.c

## 5.things to condiser
- BUFFER_SIZE = 9999, 1, 1000000: what happens?
- static variable: def?

# 6.how to test
- prepare : valid and invalid files
