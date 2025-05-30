# to check before submission
- compile : make, make re, make fclean, make clean

# compiling
-Wall -Wextra -Werror -std=c++98

# no norminette
- but clean code

# library
- allowed: almost everything from STD
- not allowed: external libraries(C++11and derived forms), Boost libraries, *printf(), *alloc(), free()
- use more: C++ style versions of C functions

## STL
- allowed only in CPP08, CPP09
- otherwise, no Containers, Algorithms. (-42)

# syntax
- UpperCamelCase for classes
- Files containing class code will be name according to the class name
e.g. ClassName.hpp, ClassName.cpp
- Header: BrickWall.hpp if it contains the class definition of 'BrickWall'
- Msg: Unless specified, ends with a new line

## CPP02 - CPP09: use orthodox canonical form
- Default constructor
- Copy constructor
- Assignment operator
- Destructor

# memory leak
- No mem leak
- when mem allocated, must be freed. By using new keyword


# header
- any funtion implementatin in header means 0 to the exercise (?), but except for function templates

- use each header independently from others, they must include all dependencies they need

# files
- can be added alongside the mandatory files


## orthodox canonial form
- default constructor
- (optional: parametarized constructor)
- copy constructor
- copy assignment operator