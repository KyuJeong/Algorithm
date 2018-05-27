#include <bits/stdc++.h>

using namespace std;

int N;
int G[101][101];
bool check[10001];

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
			if (check[G[i][j]])
			{
				cout << "FALSE";
				return 0;
			}
			check[G[i][j]] = true;
		}
	}

	int cmp = (N * (N * N + 1)) / 2;

	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			sum += G[i][j];
		}
		if (sum != cmp)
		{
			cout << "FALSE";
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			sum += G[j][i];
		}
		if (sum != cmp)
		{
			cout << "FALSE";
			return 0;
		}
	}

	int sum = 0;

	for (int i = 0; i < N; i++)
		sum += G[i][i];

	if (sum != cmp)
	{
		cout << "FALSE";
		return 0;
	}

	sum = 0;

	for (int i = 0; i < N; i++)
		sum += G[N - 1 - i][i];

	if (sum != cmp)
	{
		cout << "FALSE";
		return 0;
	}

	cout << "TRUE";

	return 0;
}