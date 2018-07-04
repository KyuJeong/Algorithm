#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N, L;
int ans[5000001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> L;
	deque <pii> dq;

	int tmp;
	cin >> tmp;
	dq.push_front({ 0, tmp });
	ans[0] = tmp;

	for (int i = 1; i < N; i++)
	{
		cin >> tmp;
		if (i - dq.front().first >= L)
			dq.pop_front();

		while (!dq.empty() && dq.back().second >= tmp)
			dq.pop_back();

		dq.push_back({ i,tmp });
		ans[i] = dq.front().second;
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}