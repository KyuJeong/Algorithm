#include <iostream>

using namespace std;

int N;

char arr[3073][6145];

void Star(int y, int x, int h)
{
	int nh = h / 2;

	if (h == 3)
	{
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		for (int i = -2; i <= 2; i++)
		{
			arr[y + 2][x + i] = '*';
		}

		return;
	}

	Star(y, x, nh);
	Star(y + nh, x - nh, nh);
	Star(y + nh, x + nh, nh);
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 2 * N; j++)
		{
			arr[i][j] = ' ';
		}
	}

	Star(1, N, N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < 2 * N; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0;
}