#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int tmp;
	vector <int> v;
	vector <pair <int, int>> vp;

	while (cin >> tmp)
	{
		v.push_back(tmp);
	}

	int sum = v.back();
	v.pop_back();

	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] + v[j] == sum)
			{
				if (v[i] <= v[j])
					vp.push_back({ v[i],v[j] });
				else
					vp.push_back({ v[j],v[i] });
			}
		}
	}

	sort(vp.begin(), vp.end());

	int cnt = 0;

	if (vp.size() != 0)
	{
		cout << vp[0].first << " " << vp[0].second << "\n";
		cnt++;

	}
	for (int i = 1; i < vp.size(); i++)
	{
		if (vp[i] != vp[i - 1])
		{
			cout << vp[i].first << " " << vp[i].second << "\n";
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}