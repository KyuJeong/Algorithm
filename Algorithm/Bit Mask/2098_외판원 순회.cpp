#include <iostream>
#include <algorithm>

using namespace std;

#define INF 20000000

int N;
int G[17][17];
int DP[17][65536];

int CalCost(int cur, int check)
{
	// ��� ������ �� �鸥 ���
	if (check == ((1 << N) - 1))
	{
		if (G[cur][1] == 0) return INF;
		return G[cur][1];
	}

	// ����ߴ� ����� ���
	if (DP[cur][check])
		return DP[cur][check];

	int val = INF;

	for (int i = 0; i <= N; i++)
	{
		// �湮�ߴ� ������ ���
		if (check & (1 << (i - 1)))
			continue;

		// ��ΰ� ���� ��
		if (G[cur][i] == 0)
			continue;

		// ����� �ּҰ� ���
		int tmp = G[cur][i] + CalCost(i, check + (1 << (i - 1)));
		val = min(val, tmp);
	}

	DP[cur][check] = val;
	return val;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> G[i][j];

	cout << CalCost(1, 1);

	return 0;
}