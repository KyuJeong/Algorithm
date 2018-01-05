#include <iostream>
#include <queue>

using namespace std;

int N;
int map[101][101];
long long DP[101][101];
bool load[101][101];
queue <pair <int, int>> q;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	DP[0][0] = 1;
	load[0][0] = true;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int np = map[i][j];
			if (!load[i][j])
				continue;
			if (map[i][j] == 0)
				break;
			if (j + np < N)
			{
				DP[i][j + np] += DP[i][j];
				load[i][j + np] = true;
			}
			if (i + np < N)
			{
				DP[i + np][j] += DP[i][j];
				load[i + np][j] = true;
			}
		}
	}

	cout << DP[N - 1][N - 1];

	return 0;
}