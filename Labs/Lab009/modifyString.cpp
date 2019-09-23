#include <iostream>
#include <string>
#include "modifyString.h"

int modifyString(std::string& referencedString, int n)
{
	referencedString = referencedString + std::to_string(n % 10);
	return referencedString.length();
}