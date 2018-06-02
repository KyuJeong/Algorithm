#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int k;
map <int, pii> m;
vector <pii> v;
vector <int> sum;
vector <int> arr[200001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> k;
	v.resize(k + 1);
	sum.resize(k + 1);

	for (int i = 1; i <= k; i++)
	{
		int N;
		cin >> N;
		arr[i].resize(N + 1);
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			sum[i] += arr[i][j];
		}

		for (int j = 1; j <= N; j++)
		{
			int tmp = sum[i] - arr[i][j];
			auto it = m.find(tmp);
			if (it != m.end())
			{
				if (it->second.first == i)
					continue;
				else
				{
					cout << "YES\n";
					cout << it->second.first << " " << it->second.second << "\n";
					cout << i << " " << j;
					return 0;
				}
			}
			else
				m.insert({ tmp, { i,j } });
		}
	}

	cout << "NO";

	return 0;
}