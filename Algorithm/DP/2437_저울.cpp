#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <int> v;
bool arr[10000000];
int pre, cur;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	pre = 0;

	sort(v.begin(), v.end());

	for (auto i : v)
	{
		cur = i;
		if (cur > pre + 1)
		{
			cout << pre + 1;
			return 0;
		}
		pre += cur;
	}

	cout << pre + 1;

	return 0;
}