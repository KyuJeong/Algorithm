#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> pii;

struct Pt
{
	pii yx;
	int sec;
	Pt() {};
	Pt(pii _yx, int _sec)
	{
		yx = _yx;
		sec = _sec;
	}
};

int R, C;
char G[51][51];
pii S;
pii D;
vector <pii> W;
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,1,-1 };

int BFS()
{
	bool visit[51][51] = { false };
	queue <Pt> q;
	q.push({ S, 0 });
	visit[S.first][S.second] = true;

	queue <Pt> w;
	for (int i = 0; i < W.size(); i++)
	{
		w.push({ W[i],0 });
	}

	while (!q.empty())
	{
		int sze = w.size();
		for (int i = 0; i < sze; i++)
		{
			Pt cur = w.front();
			w.pop();
			int cy = cur.yx.first;
			int cx = cur.yx.second;
			for (int j = 0; j < 4; j++)
			{
				int ny = cy + my[j];
				int nx = cx + mx[j];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C)
					continue;
				if (G[ny][nx] != '.')
					continue;
				w.push({ {ny,nx}, 0 });
				G[ny][nx] = '*';
			}
		}

		sze = q.size();
		for (int i = 0; i < sze; i++)
		{
			Pt cur = q.front();
			q.pop();
			int cy = cur.yx.first;
			int cx = cur.yx.second;
			int cs = cur.sec;

			for (int j = 0; j < 4; j++)
			{
				int ny = cy + my[j];
				int nx = cx + mx[j];
				int ns = cs + 1;
				if (ny < 0 || nx < 0 || ny >= R || nx >= C || visit[ny][nx])
					continue;
				if (G[ny][nx] == '*' || G[ny][nx] == 'X')
					continue;
				if (G[ny][nx] == 'D')
					return ns;
				q.push({ {ny,nx}, ns });
				visit[ny][nx] = true;
			}
		}
	}

	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == 'S')
				S = { i,j };
			else if (G[i][j] == 'D')
				D = { i,j };
			else if (G[i][j] == '*')
				W.push_back({ i,j });
		}
	}

	int ans = BFS();

	if (ans == -1)
		cout << "KAKTUS";
	else
		cout << ans;

	return 0;
}