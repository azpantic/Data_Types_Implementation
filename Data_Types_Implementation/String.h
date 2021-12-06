#pragma once

#include <exception>
#include "Array.h"

class String : public  Array<char> {

public:

	

	String& operator = (const char* str) {

		Size = 0;
		while (str[Size] != '\0') Size++;

		for(int i =0 ; str[i] !=)

	}

private:

	
};