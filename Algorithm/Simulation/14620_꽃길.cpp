#include <bits/stdc++.h>

using namespace std;

int N;
int G[11][11];
bool check[11][11];
int my[] = { -1,0,0,1,0 };
int mx[] = { 0,-1,0,0,1 };
int _min = 1e9;

int Visit(int y, int x, bool state)
{
	for (int i = 0; i < 5; i++)
	{
		check[y + my[i]][x + mx[i]] = state;
	}

	int ret = 0;
	for (int i = 0; i < 5; i++)
	{
		ret += G[y + my[i]][x + mx[i]];
	}

	return ret;
}

void Solve(int y, int x, int cnt, int price)
{
	if (cnt == 3)
	{
		_min = min(_min, price);
		return;
	}

	for (int i = y; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if (check[i - 1][j] || check[i][j - 1] || check[i][j] || check[i + 1][j] || check[i][j + 1])
				continue;
			int add = Visit(i, j, true);

			Solve(i, j, cnt + 1, price + add);

			Visit(i, j, false);
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> G[i][j];
		}
	}

	Solve(1, 1, 0, 0);

	cout << _min;

	return 0;
}