#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

char G[1001][1001];

int my[8][7] = 
{
	{0,0,1,1,2,2,2},
	{0,0,1,1,2,2,2},
	{0,0,1,1,2,2,2},
	{ -1,-1,-1,0,1,1,1 },
	{ -1,-1,-1,0,1,1,1 },
	{ -2,-2,-2,-1,-1,0,0 },
	{ -2,-2,-2,-1,-1,0,0 },
	{ -2,-2,-2,-1,-1,0,0 }
};

int mx[8][7] =
{
	{1,2,0,2,0,1,2},
	{-1,1,-1,1,-1,0,1},
	{-2,-1,-2,0,-2,-1,0},
	{0,1,2,2,0,1,2},
	{-2,-1,0,-2,-2,-1,0},
	{0,1,2,0,2,1,2},
	{-1,0,1,-1,1,-1,1},
	{-2,-1,0,-2,0,-2,-1}
};

int n, m;
bool visit[1001][1001];

bool bfs()
{
	for (int cy = 0; cy < n; cy++)
	{
		for (int cx = 0; cx < m; cx++)
		{
			if (G[cy][cx] == '.') continue;

			bool flag = false;
			for (int i = 0; i < 8; i++)
			{
				bool tmp = true;
				for (int j = 0; j < 7; j++)
				{
					int ny = cy + my[i][j];
					int nx = cx + mx[i][j];
					if (ny < 0 || nx < 0 || ny >= n || nx >= m || visit[ny][nx])
					{
						tmp = false;
						break;
					}
					if (G[ny][nx] == '.')
					{
						tmp = false;
						break;
					}
				}
				if (tmp == true)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				return false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> G[i];

	bool ans = bfs();

	if (ans) cout << "YES";
	else cout << "NO";

	return 0;
}