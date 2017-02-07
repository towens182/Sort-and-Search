// Sort and Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

const int num = 20;
void Split(int values[], int& splitVal, int first, int last);
void QuickSort(int values[], int first, int last);
void Swap(int& one, int& two);
int main()
{
	using namespace std;

	int values[num];
	int input = 0;
	int mid = 500;
	int first = 0;
	int last = (num - 1);
	for (int i = 0; i < num; i++)
	{
		values[i] = rand() % 10000;
	}
	cout << "First 20 numbers: ";

	
	for (int i = 0; i < 20; i++)
	{
		cout << values[i] << ", ";
	}
	cout << endl << "last " << values[num - 1];
Split(values, mid, first, last);
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

void Split(int values[], int& splitVal, int first, int last)
{
	int split = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do
	{
		onCorrectSide = true;
		while (onCorrectSide)
			if (values[first] > split)
			{
				onCorrectSide = false;
			}
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}
		onCorrectSide = (first <= last);
		while (onCorrectSide)
			if (values[last] <= split)
			{
				onCorrectSide = false;
			}
			else
			{
				last--;
				onCorrectSide = (first <= last);
			}

		if (first < last)
		{
			Swap(values[first], values[last]);
			first++;
			last--;
		}

	} while (first <= last);

	splitVal = last;
	Swap(values[saveFirst], values[splitVal]);
}

void QuickSort(int values[], int first, int last)
{
	if (first < last)
	{
		int splitVal;

		Split(values, splitVal, first, last);

		QuickSort(values, splitVal - 1, first);
		QuickSort(values, splitVal + 1, last);
	}
}

void Swap(int & one, int & two)
{
	int temp;
	temp = one;
	one = two;
	two = temp;
}
