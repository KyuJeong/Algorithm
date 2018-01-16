#include <iostream>

using namespace std;

int N, num;
long long DP[101][21]; // i번째 수까지 계산해서 j를 만드는 경우의 수

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> num;
	DP[1][num] = 1;
	
	for (int i = 2; i < N; i++)
	{
		cin >> num;
		for (int j = 0; j <= 20; j++)
		{
			if (j - num >= 0)
				DP[i][j - num] += DP[i - 1][j];
			if (j + num <= 20)
				DP[i][j + num] += DP[i - 1][j];
		}
	}

	cin >> num;

	cout << DP[N - 1][num];

	return 0;
}