#include <iostream>
using namespace std;

// Counting sort

int N;
int arr[10001];
int num;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		arr[num]++;
	}


	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << "\n";
		}
	}

	return 0;
}