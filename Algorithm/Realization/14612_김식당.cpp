#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	vector <pii> v;

	for (int i = 0; i < N; i++)
	{
		string s;
		int t, n;
		cin >> s;
		if (s == "order")
		{
			cin >> n >> t;
			v.push_back({ t,n });
		}
		else if (s == "sort")
		{
			sort(v.begin(), v.end());
		}
		else
		{
			cin >> n;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].second == n)
				{
					v.erase(v.begin() + i);
				}
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].second << " ";
		}
		if (v.size() == 0)
			cout << "sleep";
		cout << "\n";
	}



	return 0;
}