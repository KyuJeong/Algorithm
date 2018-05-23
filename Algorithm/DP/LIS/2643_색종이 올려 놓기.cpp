#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

vector <pii> v;
vector <pii> p;

int N;
int DP[100];
int ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	int a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (a < b)
			swap(a, b);

		v.push_back({ a,b });
		DP[i] = 1;
	}

	sort(v.begin(), v.end(), [](const pii &p1, const pii &p2)
	{
		return p1 > p2;
	}
	);

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].first > v[j].first || v[i].second > v[j].second)
				continue;
			DP[i] = max(DP[i], DP[j] + 1);
		}
		ans = max(ans, DP[i]);
	}
	
	cout << ans;

	return 0;
}