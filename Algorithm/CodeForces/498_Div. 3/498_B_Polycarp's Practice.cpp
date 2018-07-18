#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector <pair <int, int> > v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int idx[2001];
	int cnt = 0;
	vector <int> cut;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cut.push_back(v[i].second + 1);
		sum += v[i].first;
		cnt++;
		if (cnt == K)
			break;
	}

	sort(cut.begin(), cut.end());
	int pre = 0;
	vector <int> ans;
	for (int i = 0; i < cut.size() - 1; i++)
	{
		ans.push_back(cut[i] - pre);
		pre = cut[i];
	}
	ans.push_back(N - pre);

	cout << sum << "\n";
	for (auto i : ans)
		cout << i << " ";

	return 0;
}