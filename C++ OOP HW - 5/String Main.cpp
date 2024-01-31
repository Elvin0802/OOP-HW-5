#include <iostream>
#include <cassert>
#include <string>

using namespace std;

char* NumToStr(int number);

#include "My String.h"
#include "Out Of String.h"


void main()
{
	String a;

	cin >> a;

	cout << a;
}

char* NumToStr(int number) {

	int num = number;
	int strLen = 1;

	bool isNegative = false;

	if (num < 0) {
		isNegative = true;
		num = -num;
	}

	int tempNum = num;

	while (tempNum /= 10) strLen++;

	if (isNegative) strLen++;

	char* str = new char[strLen + 1];

	for (int i = strLen - 1; i >= 0; i--)
	{
		if (i == 0 && isNegative) {
			str[i] = '-';
		}
		else {
			str[i] = '0' + (num % 10);
			num /= 10;
		}
	}

	str[strLen] = '\0';

	return str;
}
