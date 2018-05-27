#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	int cnt = 1;

	for (int i = 2; i * i <= N; i++)
	{
		cnt++;
	}

	cout << cnt;

	return 0;
}