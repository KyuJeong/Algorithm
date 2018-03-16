#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

int N;
int A[40001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	vector <int> v;
	v.push_back(-INF);

	for (int i = 0; i < N; i++)
	{
		if (A[i] > v.back())
		{
			v.push_back(A[i]);
		}
		auto it = lower_bound(v.begin(), v.end(), A[i]);
		*it = A[i];
	}

	cout << v.size() - 1;

	return 0;
}