#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> arr;
vector <int> v(N + 1);

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	v.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++)
		arr.push_back(0);

	for (int i = 0; i < N - M; i++)
		arr.push_back(1);

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
