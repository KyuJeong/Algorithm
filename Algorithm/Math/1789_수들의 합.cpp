#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	long long N, S;

	cin >> N >> S;

	long long val = 0;

	int idx = 0;

	while (val <= N)
	{
		idx++;
		val += idx;
	}

	cout << idx - 1;

	return 0;
}