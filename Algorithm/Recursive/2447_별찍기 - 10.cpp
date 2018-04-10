#include <iostream>

using namespace std;

int N;
char G[2188][2188];

inline void Solve(int y, int x, int side)
{
	if (side == 1)
	{
		G[y][x] = '*';
		return;
	}
	
	int ter = side / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				continue;
			Solve(y + ter * i, x + ter * j, ter);
		}
	}

}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			G[i][j] = ' ';
		}
	}

	Solve(1, 1, N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << G[i][j];
		}
		cout << "\n";
	}

	return 0;
}