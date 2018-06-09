#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N;
int t[501];
int ind[501];
vector <int> v[501];
int fin[501];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> t[i];
		int tmp;
		while (cin >> tmp)
		{
			if (tmp == -1)
				break;
			v[tmp].push_back(i);
			ind[i]++;
		}
	}

	priority_queue < pii, vector <pii>, greater<pii> > pq;

	for (int i = 1; i <= N; i++)
	{
		if (ind[i] == 0)
		{
			pq.push({ t[i],i });
			fin[i] = t[i];
		}
	}

	int cnt = 0;

	while (!pq.empty())
	{
		while (pq.top().first == cnt)
		{
			pii cur = pq.top();
			pq.pop();
			int ct = cur.first;
			int ci = cur.second;

			for (auto i : v[ci])
			{
				if (--ind[i] == 0)
				{
					pq.push({ t[i] + cnt, i });
					fin[i] = t[i] + cnt;
				}
			}
			if (pq.empty())
				break;
		}

		cnt++;
	}

	for (int i = 1; i <= N; i++)
	{
		cout << fin[i] << "\n";
	}

	return 0;
}