#include <iostream>
#define MAXN 1000
using namespace std;

void bubblesort(int arr[],int ei)
{
	for (int i = 0; i <= ei; i++)
	{
		for (int j = i + 1; j <= ei; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int arr[MAXN+2];

	for (int i=MAXN;i>=0;i--)
		arr[MAXN - i] = i;
    
	bubblesort(arr,MAXN);

	for (int i = 0; i <=MAXN; i++)
		cout<<arr[i]<<" ";
	
	return 0;
}
