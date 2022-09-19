#include "RemoveDups.h"

void RemoveDups::removeDups(char* str)
{
	if (*str == '\0')
		return;

	char* it = str;  
	while (*(it + 1) != '\0') 
	{
		if (*it == *(it + 1)) {
			char* temp = it; 
			while (*it != '\0') {
				*it = *(it + 1);
				++it;
			}
			it = temp; 
		}
		else ++it;
	}
}
