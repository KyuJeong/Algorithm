#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, int> pli;

int n;
vector <pli> v;
vector <ll> dif;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}

	if (n <= 3)
	{
		cout << "1";
		return 0;
	}

	sort(v.begin(), v.end());

	ll gap = v[2].first - v[1].first;
	bool flag = false;
	for (int i = 3; i < n; i++)
	{
		if (v[i].first - v[i - 1].first != gap)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << v[0].second;
		return 0;
	}

	flag = false;
	gap = v[1].first - v[0].first;
	for (int i = 2; i < n - 1; i++)
	{
		if (v[i].first - v[i - 1].first != gap)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << v[n - 1].second;
		return 0;
	}

	for (int i = 1; i < n; i++)
	{
		dif.push_back(v[i].first - v[i - 1].first);
	}

	set <ll> s;
	for (auto i : dif)
	{
		s.insert(i);
	}
	if (s.size() > 3)
	{
		cout << "-1";
		return 0;
	}
	if (s.size() == 1)
	{
		cout << "1";
		return 0;
	}

	vector <int> dif_list;
	for (auto i : s)
	{
		dif_list.push_back(i);
	}

	int dif_cnt[3] = { 0 };
	if (s.size() == 2)
	{
		for (auto i : dif)
		{
			if (i == dif_list[0])
				dif_cnt[0]++;
			else
				dif_cnt[1]++;
		}

		if ((dif_list[0] == 0 && dif_cnt[0] == 1) || dif_list[1] == 0 && dif_cnt[1] == 1)
		{
			for (int i = 0; i < n - 1; i++)
			{
				if (dif[i] == 0)
				{
					cout << v[i + 1].second;
					return 0;
				}
			}
		}
		if (dif_cnt[0] == 2 && dif_list[0] * 2 == dif_list[1])
		{
			for (int i = 0; i < n - 1; i++)
			{
				if (dif[i] == dif_list[0])
				{
					cout << v[i + 1].second;
					return 0;
				}
			}
		}
		else
		{
			cout << "-1";
			return 0;
		}


	}
	else
	{
		for (auto i : dif)
		{
			if (i == dif_list[0])
				dif_cnt[0]++;
			else if (i == dif_list[1])
				dif_cnt[1]++;
			else
				dif_cnt[2]++;
		}
		if (dif_cnt[0] != 1 || dif_cnt[1] != 1)
		{
			cout << "-1";
			return 0;
		}
		if (dif_list[0] + dif_list[1] != dif_list[2])
		{
			cout << "-1";
			return 0;
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (dif[i] == dif_list[0] || dif[i] == dif_list[1])
			{
				cout << v[i + 1].second;
				return 0;
			}
		}
	}


	return 0;
}