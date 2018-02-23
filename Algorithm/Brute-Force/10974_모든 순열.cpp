#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10000];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	do
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(arr, arr + N));


	return 0;
}