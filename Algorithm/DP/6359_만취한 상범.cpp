#include <iostream>
using namespace std;

int T, N;

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		bool room[101] = { 0 };
		int open_count = 0;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k * j <= N; k++)
			{
				if (room[k*j] == 0)
					room[k*j] = 1;
				else
					room[k*j] = 0;
			}
		}
		for (int k = 1; k <= N; k++)
		{
			if (room[k] == 1)
				open_count++;
		}
		cout << open_count << "\n";
	}
	return 0;
}