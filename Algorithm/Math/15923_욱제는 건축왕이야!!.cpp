#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N;
pii G[21];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> G[i].first >> G[i].second;

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans += abs(G[i % N].first - G[i - 1].first) + abs(G[i % N].second - G[i - 1].second);

	cout << ans;

	return 0;
}