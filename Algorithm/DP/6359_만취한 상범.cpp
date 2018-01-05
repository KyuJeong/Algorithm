#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		bool room[101] = { 0 };
		int open_count = 0;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k * j <= n; k++)
			{
				if (room[k*j] == 0)
					room[k*j] = 1;
				else
					room[k*j] = 0;
			}
		}
		for (int k = 1; k <= n; k++)
		{
			if (room[k] == 1)
				open_count++;
		}
		cout << open_count << "\n";
	}
	return 0;
}