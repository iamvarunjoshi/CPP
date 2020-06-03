#include <iostream>
#define MAXN 1000
using namespace std;

void insertionsort(int arr[], int ei)
{
	for (int i = 1; i <= ei; i++)
	{
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			int temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}

int main()
{
	int arr[MAXN+2];

	for (int i=MAXN;i>=0;i--)
		arr[MAXN - i] = i;
    
	insertionsort(arr,MAXN);

	for (int i = 0; i <=MAXN; i++)
		cout<<arr[i]<<" ";

return 0;
}
