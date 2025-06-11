#!/bin/bash

# Concatenate all .c files from the src directory into final_mycode.txt
cat src/*.c > "final_mycode.txt"

# Append the contents of the philo.h header file to final_mycode.txt
cat includes/philo.h >> "final_mycode.txt"

# Append the contents of the Makefile to final_mycode.txt
cat Makefile >> "final_mycode.txt"

echo "Files have been concatenated into final_mycode.txt"