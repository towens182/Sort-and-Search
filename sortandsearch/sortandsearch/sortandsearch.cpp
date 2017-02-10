// Sort and Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>

const int num = 1000;
void QuickSort(int values[], int first, int last);
void Split(int values[], int& splitVal, int first, int last);
void Swap(int& one, int& two);
int BinarySearch(int values[], int first, int last, int key);
void User(int values[]);

int main()
{
	using namespace std;

	int values[num];
	int mid = ((num - 1) / 2);

	for (int i = 0; i < num; i++)
	{
		values[i] = rand() % 1000;
	}
	QuickSort(values, 0, num - 1);
	cout << "Quick Sort performed" << endl << endl;
	cout << "First 20 numbers: ";
		
	for (int i = 0; i < 20; i++)
	{
		cout << values[i] << " ";
	}
	
	User(values);

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

		QuickSort(values, first, splitVal - 1);
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

int BinarySearch(int values[], int first, int last, int key)
{
	if (first <= last)
	{
		int mid = (first + last) / 2;
		if (key == values[mid])
		{
			return mid;
		}
		else if (key < values[mid])
		{
			return BinarySearch(values, first, mid - 1, key);
		}
		else
		{
			return BinarySearch(values, mid + 1, last, key);
		}
	}
	return -1;
}

void User(int values[])
{
	using namespace std;

	int input;
	string strInput;
	cout << endl << "Enter a value between 0 and " << num << ": ";
	cin >> strInput;
	try {
		input = stoi(strInput);
	}
	catch (...)
	{
		cout << "Invalid Entry" << endl;
		return;
	}
	
	if (BinarySearch(values, 0, num - 1, input) >= 0)
	{
		cout << endl << "Value " << input << " found in position " << BinarySearch(values, 0, num - 1, input) << endl;
	}
	else
	{
		cout << input << " was not one of the generated numbers" << endl;
	}
		User(values);
}

