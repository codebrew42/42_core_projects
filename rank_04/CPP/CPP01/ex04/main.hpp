#ifndef MAIN_HPP
# define MAIN_HPP

#include <fstream>
#include <iostream>
#include <sys/stat.h>	// checking file existence without opening
#include <cerrno>		// checking error codes
#include <string>
#include <stdexcept>

using					std::ifstream;
using					std::ofstream;
using					std::cerr;
using					std::string;
using					std::endl;
using 					std::invalid_argument;
using 					std::runtime_error;  
using					std::exception;

#endif