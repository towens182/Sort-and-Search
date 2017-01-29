// Sort and Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

const int num = 20;
int main()
{
	using namespace std;

	int values[num];
	int input = 0;
	for (int i = 0; i < num; i++)
	{
		values[i] = rand() % 10000;
	}
	cout << "First 20 numbers: ";

	for (int i = 0; i < 20; i++)
	{
		cout << values[i] << ", ";
	}

	try
	{
		cout << endl << "Please enter a number between 0 and " << num << ": ";
		cin >> input;
		if (input < 0 || input > num)
		{
			throw string("Wrong input");
		}
	}
	catch (string err)
	{
		cout << err << endl << endl;
	}


	return 0;
}