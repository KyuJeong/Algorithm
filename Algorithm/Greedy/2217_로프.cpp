#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *rope = new int[N];
	int max = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> rope[i];
	}

	sort(rope, rope + N);

	for (int i = 0; i < N; i++)
	{
		if ((rope[i] * (N - i)) > max)
			max = rope[i] * (N - i);
	}

	cout << max;
	delete[] rope;
	return 0;
}