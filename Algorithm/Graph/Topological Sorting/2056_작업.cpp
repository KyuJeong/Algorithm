#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N;
int ind[10001];
int tim[10001];
vector <int> v[10001];
priority_queue <pii, vector <pii>, greater <pii>> q;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> tim[i] >> ind[i];
		int tmp;
		for (int j = 0; j < ind[i]; j++)
		{
			cin >> tmp;
			v[tmp].push_back(i);
		}
		if (ind[i] == 0)
			q.push({ tim[i], i });
	}

	int cnt = 0;
	while (!q.empty())
	{
		while (q.top().first == cnt)
		{
			pii cur = q.top();
			q.pop();
			int ct = cur.first;
			int ci = cur.second;
			for (auto i : v[ci])
			{
				ind[i]--;
				if (ind[i] == 0)
					q.push({ tim[i] + cnt,i });
			}
			if (q.empty())
				break;
		}
		cnt++;
	}

	cout << cnt - 1;

	return 0;
}