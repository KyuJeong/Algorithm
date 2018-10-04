#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000

int srt[201];
int t, a, s, b;
vector <int> v;
int d[4001][4001]; // j번째 수까지 사용하고 i개를 골랐을 때의 경우의 수

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t >> a >> s >> b;
	v.resize(a + 1);

	for (int i = 1; i <= a; i++)
		cin >> v[i];

	sort(v.begin() + 1, v.end());

	for (int i = 1; i <= a; i++)
	{
		if (srt[v[i]] == 0)
			srt[v[i]] = i;
	}

	for (int j = 0; j <= a; j++)
		d[0][j] = 1;

	for (int i = 1; i <= a; i++)
	{
		for (int j = i; j <= a; j++)
		{
			int num = v[j];
			int seq = j - srt[num] + 1;
			d[i][j] = d[i][j - 1];
			if (i >= seq)
				d[i][j] = (d[i][j] + d[i - seq][srt[num] - 1]) % MOD;
		}
	}

	int ret = 0;
	for (int i = s; i <= b; i++)
		ret = (ret + d[i][a]) % MOD;

	cout << ret;

	return 0;
}