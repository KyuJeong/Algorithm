#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll, int> pii;

int n, k;
vi v;
vector <pii> dif;
vi idx;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;
	v.resize(n + 1);
	dif.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	if (n == k)
	{
		cout << "0";
		return 0;
	}
	if (k == 1)
	{
		cout << v[n] - v[1];
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		dif[i].first = v[i] - v[i - 1];
		dif[i].second = i;
	}

	sort(dif.begin(), dif.end());

	for (int i = 0; i < k - 1; i++)
	{
		idx.push_back(dif[n - i].second);
	}

	ll sum = 0;
	int pre = 1;
	int cnt = 0;

	sort(idx.begin(), idx.end());

	for (int i = 1; i <= n; i++)
	{
		if (i == idx[cnt])
		{
			sum += v[i - 1] - v[pre];
			pre = i;
			cnt++;
		}
		if (cnt == k - 1)
		{
			sum += v[n] - v[pre];
			break;
		}
	}

	cout << sum;

	return 0;
}