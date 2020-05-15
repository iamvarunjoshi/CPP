// Inplace heap sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int main()
{
	//int arr[7] = { 10,5,8,1,4,6,7 };
	//int size = 7;
	int arr[22];
	int size = 22;
	cout << "Initial Input"<<endl;
	for (int i = 0; i < size; i++)
		arr[i] = size - i, cout << arr[i] << " ";


	int pi = 0;//parent index of heap
	int ci = 0;// child index of heap

	cout << endl << "This code is for inplace sorting of Min heap" << endl << endl;
	//i.e. root data should be less than childrens data or childrens data should be less than parents data

	for (int i = 1; i < size; i++)
	{
		ci = i;
		while (ci > 0)
		{
			pi = (ci - 1) / 2;
			if (arr[ci] < arr[pi])
			{
				int temp = arr[ci];
				arr[ci] = arr[pi];
				arr[pi] = temp;
			}
			else
				break;

			ci = pi;//moving from bottom to top
		}
	}
	cout << "after heapifying" << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";


	cout << endl <<endl;

	cout << endl << "sorting the heap" << endl;
	int li = size-1;
	while (li > 0)
	{	pi = 0;
		int temp = arr[0];
		arr[0] = arr[li];
		arr[li] = temp;
		
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		int mi=0;
		
		while (rci < li)
		{
			    mi = pi;
			if (arr[mi] > arr[lci])
				mi = lci;
			if (arr[mi] > arr[rci])
				mi = rci;
			if (mi == pi)
				break;

			int temp = arr[mi];
			arr[mi] = arr[pi];
			arr[pi] = temp;
			pi = mi;
			rci = 2 * pi + 2;
			lci = 2 * pi + 1;
		}
		li--;
	}


	cout << endl << "sorted input" << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl << endl << endl << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
