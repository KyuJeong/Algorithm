#include <bits/stdc++.h>

using namespace std;

int n;
int d[101]; // 체력이 n 남았을 때의 최대 기쁨
int hp[21];
int glad[21];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> hp[i];

	for (int i = 1; i <= n; i++)
		cin >> glad[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j + hp[i] <= 100; j++)
			d[j] = max(d[j], d[j + hp[i]] + glad[i]);

	cout << d[1];

	return 0;
}