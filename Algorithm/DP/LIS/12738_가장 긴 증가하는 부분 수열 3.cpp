#include <bits/stdc++.h>

using namespace std;

#define INF -1e9 - 1

int N;
vector <int> v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	v.push_back(INF);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp > v.back())
			v.push_back(tmp);
		else
		{
			auto it = lower_bound(v.begin(), v.end(), tmp);
			*it = tmp;
		}
	}

	int ans = v.size() - 1;

	cout << ans;

	return 0;
}