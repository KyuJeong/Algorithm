#include <bits/stdc++.h>

using namespace std;

int R, C;
int my[] = { -1,-1,-1,0,0,1,1,1 };
int mx[] = { -1,0,1,-1,1,-1,0,1 };

void Solve(char G[101][101])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (G[i][j] == '*')
				continue;
			int cnt = 0;
			for (int k = 0; k < 8; k++)
			{
				int ny = i + my[k];
				int nx = j + mx[k];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C)
					continue;
				if (G[ny][nx] == '*')
					cnt++;
			}
			G[i][j] = cnt + '0';
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (1)
	{
		cin >> R >> C;
		if (R == 0)
			break;
		char G[101][101];

		for (int i = 0; i < R; i++)
			cin >> G[i];

		Solve(G);

		for (int i = 0; i < R; i++)
			cout << G[i] << "\n";

	}

	return 0;
}