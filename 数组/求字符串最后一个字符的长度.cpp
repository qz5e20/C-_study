#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int engthOfLastWord(string(s)) {
	std::size_t foundLast = s.rfind(' ');  //find last occurrence of the sequence
	int result = 0;
	if (foundLast != string::npos) //until the end of the string
	{
		if (foundLast == s.size() - 1) {
			while (s[foundLast - 1] = '')
			{
				//Searches the string for the last character that does not match any of the characters specified in its arguments.
				foundLast = s.find_last_not_of(' ',foundLast-1) 
			}
			size_t foundBeforeLast = s.find_last_of(' ', foundLast - 1);
			result = foundLast - (foundBeforeLast + 1);
		}
		else {
			result = s.size() - (foundLast + 1);
			cout << result << endl;
		}
	}
	else
	{
		result = s.length();
	}
}


}