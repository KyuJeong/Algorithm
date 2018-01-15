#include <iostream>

using namespace std;

int N, S, M;
int V;
bool P[101][1001];	// N번째 곡을 볼륨 M으로 연주하는게 가능한지
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> S >> M;

	P[0][S] = true;

	for (int i = 1; i <= N; i++)
	{
		cin >> V;
		int v_flag = false;
		for (int j = 0; j <= M; j++)
		{
			if (P[i - 1][j])
			{
				if ((j - V) >= 0)
				{
					P[i][j - V] = true;
					v_flag = true;
				}
				if ((j + V) <= M)
				{
					P[i][j + V] = true;
					v_flag = true;
				}
			}
		}
		if (!v_flag)
		{
			cout << "-1";
			return 0;
		}
	}

	for (int i = 0; i <= M; i++)
	{
		if (P[N][i])
			ans = i;
	}

	cout << ans;

	return 0;
}