#include <iostream>
#include <cstring>

using namespace std;

int T;
int N, X;
int G[22][22];

int Solve()
{
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int pre = G[i][0];
		int cnt = 0;
		cnt++;
		bool flag = true;

		for (int j = 1; j < N; j++)
		{
			if (G[i][j] == pre)
				cnt++;
			else if (G[i][j] == pre + 1)
			{
				if (cnt < X)
				{
					flag = false;
					break;
				}
				pre = G[i][j];
				cnt = 1;
			}
			else if (G[i][j] == pre - 1)
			{
				int cur = G[i][j];
				cnt = 0;
				for (int k = j; k < N; k++)
				{
					if (G[i][k] == cur)
						cnt++;
					else
					{
						flag = false;
						break;
					}
					if (cnt == X)
					{
						j = k;
						pre = G[i][j];
						break;
					}
				}
				if (cnt < X)
					flag = false;
				if (!flag)
					break;
				cnt = 0;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
	}

	for (int i = 0; i < N; i++)
	{
		int pre = G[0][i];
		int cnt = 0;
		cnt++;
		bool flag = true;

		for (int j = 1; j < N; j++)
		{
			if (G[j][i] == pre)
				cnt++;
			else if (G[j][i] == pre + 1)
			{
				if (cnt < X)
				{
					flag = false;
					break;
				}
				pre = G[j][i];
				cnt = 1;
			}
			else if (G[j][i] == pre - 1)
			{
				int cur = G[j][i];
				cnt = 0;
				for (int k = j; k < N; k++)
				{
					if (G[k][i] == cur)
						cnt++;
					else
					{
						flag = false;
						break;
					}
					if (cnt == X)
					{
						j = k;
						pre = G[j][i];
						break;
					}
				}

				if (cnt < X)
					flag = false;
				if (!flag)
					break;
				cnt = 0;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
	}

	return ans;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N >> X;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> G[i][j];
			}
		}

		int ans = Solve();

		cout << "#" << test << " " << ans << "\n";
		
		memset(G, 0, sizeof(G));
	}

	return 0;
}