#include <bits/stdc++.h>

using namespace std;

int t;
vector <pair <char, int>> va;
vector <pair <char, int>> vb;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		va.clear();
		vb.clear();
		char pre = a[0];
		int cnt = 1;
		for (int i = 1; i < a.size(); i++)
		{
			if (a[i] == pre)
				cnt++;
			else
			{
				va.push_back({ pre,cnt });
				pre = a[i];
				cnt = 1;
			}
		}
		va.push_back({ pre,cnt });
		pre = b[0];
		cnt = 1;
		for (int i = 1; i < b.size(); i++)
		{
			if (b[i] == pre)
				cnt++;
			else
			{
				vb.push_back({ pre,cnt });
				pre = b[i];
				cnt = 1;
			}
		}
		vb.push_back({ pre,cnt });
		bool flag = true;
		if (va.size() != vb.size())
		{
			cout << "NO\n";
			flag = false;
		}
		else
		{
			for (int i = 0; i < va.size(); i++)
			{
				if (va[i].first != vb[i].first)
				{
					cout << "NO\n";
					flag = false;
					break;
				}
				else
				{
					if (va[i].second == vb[i].second)
						continue;
					else
					{
						if (va[i].second <= vb[i].second)
							continue;
						else
						{
							cout << "NO\n";
							flag = false;
							break;
						}
					}
				}
			}
		}
		if (flag) cout << "YES\n";
	}

	return 0;
}