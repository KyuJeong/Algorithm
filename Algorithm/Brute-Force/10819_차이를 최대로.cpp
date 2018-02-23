#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int max_value;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	vector <int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	do
	{
		int value = 0;

		for (int i = 0; i < N - 1; i++)
		{
			value += abs(v[i] - v[i + 1]);
		}

		max_value = max(max_value, value);

	} while (next_permutation(v.begin(), v.end()));

	cout << max_value;

	return 0;
}