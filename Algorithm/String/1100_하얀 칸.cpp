#include <iostream>
#include <string>

using namespace std;

char G[8][8];
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	for (int i = 0; i < 8; i++)
	{
		cin >> G[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0 && j % 2 == 0)
			{
				if (G[i][j] == 'F')
					ans++;
			}
			else if (i % 2 == 1 && j % 2 == 1)
			{
				if (G[i][j] == 'F')
					ans++;
			}
		}
	}

	cout << ans;

	return 0;
}