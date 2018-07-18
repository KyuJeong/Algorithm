#include <bits/stdc++.h>

using namespace std;

int N;
string a, b;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	cin >> a >> b;

	int cnt = 0;
	int M = N - 1;

	for (int i = 0; i < N / 2; i++)
	{
		if (b[i] == b[M - i])
		{
			if (a[i] != a[M - i])
				cnt++;
			continue;
		}
		if (a[i] == b[i])
		{
			if (a[M - i] == b[M - i])
				continue;
			else
				cnt++;
		}
		else // a[i] != b[i]
		{
			if (a[i] == b[M - i])
			{
				if (a[M - i] == b[i])
					continue;
				else
					cnt++;
			}
			else
			{
				if (a[M - i] == b[i] || a[M - i] == b[M - i])
					cnt++;
				else
					cnt += 2;
			}
		}
	}
	if (N & 1)
		if (a[N / 2] != b[N / 2])
			cnt++;

	cout << cnt;


	return 0;
}