#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

int N;
int arr[201];

int main()
{
	std::ios::sync_with_stdio(false);

	vector <int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	v.push_back(-INF);

	for (int i = 0; i < N; i++)
	{
		if (v.back() < arr[i])
			v.push_back(arr[i]);
		else
		{
			auto it = lower_bound(v.begin(), v.end(), arr[i]);
			*it = arr[i];
		}
	}

	int size = v.size() - 1;

	cout << N - size;

	return 0;
}