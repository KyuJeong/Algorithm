#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

bool cmp(const pii &p1, const pii &p2)
{
	return p1.first > p2.first;
};

int n, q;
vector <pii> b;
vector <pii> v;
vector <ll> ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> q;

	ans.resize(q);

	char c;
	int pre_time = 0;
	int pre_height = 0;

	cin >> c >> pre_time >> pre_height;
	if (c == '+')
		pre_height = -pre_height;

	for (int i = 1; i < n; i++)
	{
		char a;
		int t, k;
		cin >> a >> t >> k;
		if (a == '+')
			k = -k;
		int _time = t - pre_time;
		v.push_back({ pre_height , _time });
		pre_height += k;
		pre_time = t;
	}

	sort(v.begin(), v.end(), cmp);

	int threshold = max(0, pre_height);

	for (int i = 0; i < q; i++)
	{
		int tmp;
		cin >> tmp;
		b.push_back({ tmp, i });
	}

	sort(b.begin(), b.end(), cmp);
	int ptr = 0;
	int total_l = 0;
	ll width = 0;
	int pre_h = b[0].first;

	for (int i = 0; i < q; i++)
	{
		int start_h = b[i].first;
		int idx = b[i].second;

		if (start_h < threshold)
		{
			ans[idx] = -1;
			continue;
		}

		width += (ll)(pre_h - start_h) * total_l;
		while (ptr < n && v[ptr].first > start_h)
		{
			ll cur_h = v[ptr].first;
			ll cur_l = v[ptr].second;

			width += (ll)(cur_h - start_h) * cur_l;
			total_l += cur_l;
			ptr++;
		}

		pre_h = start_h;
		ans[idx] = width;
	}

	for (int i = 0; i < q; i++)
	{
		if (ans[i] == -1)
			cout << "INFINITY\n";
		else
			cout << ans[i] << "\n";
	}

	return 0;
}