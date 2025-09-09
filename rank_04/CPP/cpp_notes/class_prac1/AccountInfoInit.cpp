#include "AccountInfo.hpp"

//Take param(null or not null) and assign it
	// AccountInfo();    == param null
	// AccountInfo("12345", "sec", "Join", 1000)    == param not null

	
// default constructor
// automatically called when obj is created
AccountInfo::AccountInfo() 
	: accountNumber(""), password(""), name(""), balance(0) {}

// parameterized construct
AccountInfo::AccountInfo(const std::string& accNum, const std::string& pass,
						const std::string& n, int bal)
	: accountNumber(accNum), password(pass), name(n), balance(bal) {}