#include <iostream>
using namespace std;

int N;
int map[20][20];
bool check[20][20];
int sum;

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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (map[i][j] != 0 && map[j][k] != 0 && map[i][j] + map[j][k] == map[i][k])
					check[i][k] = true;
				if (map[i][j] != 0 && map[j][k] != 0 && map[i][j] + map[j][k] < map[i][k])
				{
					cout << "-1";
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (!check[i][j])
				sum += map[i][j];
		}
	}

	cout << sum;

	return 0;
}