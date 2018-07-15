#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N;
pii v[100001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	if (v[0].first > v[0].second)
		swap(v[0].first, v[0].second);

	int pre = v[0].second;

	for (int i = 1; i < N; i++)
	{
		if (v[i].first > pre)
		{
			if (v[i].second > pre)
			{
				cout << "NO";
				return 0;
			}
			else
				pre = v[i].second;
		}
		else
		{
			if (v[i].second <= pre)
			{
				pre = max(v[i].first, v[i].second);
			}
			else
				pre = v[i].first;
		}
	}

	cout << "YES";

	return 0;
}