#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	vector <int> arr;
	vector <int> v(N + 1);

	for (int i = 0; i < M; i++)
		arr.push_back(0);

	for (int i = 0; i < N - M; i++)
		arr.push_back(1);

	for (int i = 1; i <= N; i++)
		v[i] = i;

	do 
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i] == 0)
				cout << v[i + 1] << " ";
		}

		cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}
