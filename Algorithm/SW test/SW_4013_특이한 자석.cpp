#include <iostream>
#include <queue>

using namespace std;

typedef pair <int, int> pii;

int T;
int mgn[5][8];
int md[] = { -1,1 };
int mi[] = { 6,2,2,6 };

void Solve(int num, int dir)
{
	queue <pii> q;
	q.push({ num, dir });

	int spin[5] = { 0 };
	bool visit[5] = { false };

	while (!q.empty())
	{
		int cn = q.front().first;
		int cd = q.front().second;
		q.pop();
		if (visit[cn])
			continue;
		spin[cn] = cd;
		visit[cn] = true;
		for (int i = 0; i < 2; i ++)
		{
			int nn = cn + md[i];
			int nd = cd;
			if (nn < 1 || nn > 4 || visit[nn])
				continue;
			int ci = mi[i];
			int ni = mi[i + 2];
			if (mgn[cn][ci] != mgn[nn][ni])
				nd = -nd;
			else
				nd = 0;

			q.push({ nn,nd });
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (spin[i] == 0)
			continue;
		if (spin[i] == 1)
		{
			int tmp = mgn[i][7];
			for (int j = 7; j >= 1; j--)
			{
				mgn[i][j] = mgn[i][j - 1];
			}
			mgn[i][0] = tmp;
		}
		else
		{
			int tmp = mgn[i][0];
			for (int j = 0; j <= 6; j++)
			{
				mgn[i][j] = mgn[i][j + 1];
			}
			mgn[i][7] = tmp;
		}

	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int K;
		cin >> K;
		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> mgn[i][j];
			}
		}

		int num, dir;
		for (int i = 0; i < K; i++)
		{
			cin >> num >> dir;
			Solve(num, dir);
		}

		int ans = 0;
		int score = 1;

		for (int i = 1; i <= 4; i++)
		{
			if (mgn[i][0] == 1)
				ans += score;
			score *= 2;
		}

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}