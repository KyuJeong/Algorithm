#include <iostream>

using namespace std;

int N;
char G[101][101];
int row, col;

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

	for (int i = 0; i < N; i++)
	{
		bool seat = false;
		for (int j = 1; j < N; j++)
		{
			if (G[i][j] == '.' && G[i][j - 1] == '.')
			{
				if (!seat)
				{
					row++;
					seat = true;
				}
			}

			if (G[i][j] == 'X')
				seat = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		bool seat = false;
		for (int j = 1; j < N; j++)
		{
			if (G[j][i] == '.' && G[j - 1][i]== '.')
			{
				if (!seat)
				{
					col++;
					seat = true;
				}
			}

			if (G[j][i] == 'X')
				seat = false;
		}
	}

	cout << row << " " << col << "\n";

	return 0;
}