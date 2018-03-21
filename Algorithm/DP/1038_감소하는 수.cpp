#include <iostream>

using namespace std;

int N;
int DP[10][15]; // DP[N][M] = 앞자리가 N이면서 길이가 M인 감소하는 수의 갯수

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	if (N < 10)
	{
		cout << N;
		return 0;
	}

	if (N > 1022)
	{
		cout << "-1\n";
		return 0;
	}

	int idx = 0;
	int cnt = 1;

	DP[0][1] = 1;

	while (1)
	{
		for (int i = 1; i < 10; i++)
		{
			DP[i][cnt] = DP[i - 1][cnt] + DP[i - 1][cnt - 1];
			idx += DP[i][cnt];
			if (idx >= N)
			{
				int num = i;
				while (1)
				{
					cout << num;
					num--;
					cnt--;

					for (int j = num; j >= 0; j--)
					{
						int sub = DP[num][cnt];

						if (idx - sub < N)
						{
							break;
						}
						idx -= sub;
						num--;
					}

					if (cnt == 1)
					{
						cout << num;
						return 0;
					}
				}
			}
		}
		cnt++;
	}

	cout << DP[N];

	return 0;
}