#include <bits/stdc++.h>

using namespace std;

string H, N;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> H >> N;

	int len_H = H.size();
	int len_N = N.size();
	int cnt = 0;

	for (int i = 0; i <= len_H - len_N; i++)
	{
		string tmp = H.substr(i, len_N);
		if (tmp == N)
			cnt++;
	}

	cout << cnt;

	return 0;
}