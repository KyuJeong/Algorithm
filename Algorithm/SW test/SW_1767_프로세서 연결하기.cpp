#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <bool> vb;
typedef pair <int, int> pii;

struct Pt
{
	vector <vi> vec;
	int core;
	int length;
	Pt() {};
	Pt(vector <vi> _vec, int _core, int _length)
	{
		vec = _vec;
		core = _core;
		length = _length;
	}
};

int T, N;
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };
int max_core;
int min_length;

void BFS(Pt pt, vector <pii> yx)
{
	queue <Pt> q;
	q.push(pt);
	int core = yx.size();

	while(!q.empty())
	{
		Pt cur = q.front();
		q.pop();
		int cc = cur.core;
		if (cc == core)
			break;
		int cy = yx[cc].first;
		int cx = yx[cc].second;
		vector <vi> cv = cur.vec;
		int cl = cur.length;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			vector <vi> nv = cv;
			int nc = cc;
			int nl = cl;

			int cnt = 0;
			bool connect = true;
			vector <vi> tv = cv;

			while (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (cv[ny][nx] != 0)
				{
					connect = false;
					break;
				}
				tv[ny][nx] = 2;
				cnt++;
				ny += my[i];
				nx += mx[i];
			}
			if (!connect)
				continue;

			nc++;
			nl += cnt;
			nv = tv;
			if(nc < core)
				q.push({ nv, nc, nl });

			if (nc > max_core)
			{
				max_core = nc;
				min_length = nl;
			}
			else if (nc == max_core)
				min_length = min(min_length, nl);
		}
	}
}

int main()
{
	scanf("%d", &T);

	for (int test = 1; test <= T; test++)
	{
		scanf("%d", &N);

		max_core = 0;
		min_length = 1e9;

		vector <vi> G;
		G.resize(N);
		vector <pii> p;

		for (int i = 0; i < N; i++)
		{
			G[i].resize(N);
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &G[i][j]);
			}
		}
		
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < N - 1; j++)
			{
				if (G[i][j] == 1) // 네 방향이 모두 1에 둘러싸여 있는지 검사
				{
					for (int k = 0; k < 4; k++)
					{
						int ny = i + my[k];
						int nx = j + mx[k];
						bool flag = true;
						while (ny >= 0 && ny < N && nx >= 0 && nx < N)
						{
							if (G[ny][nx] == 1)
							{
								flag = false;
								break;
							}
							ny += my[k];
							nx += mx[k];
						}
						if (flag == true) 
						{
							p.push_back({ i,j });
							break;
						}
					}
				}
			}
		}

		BFS(Pt({ G,0,0 }), p);

		if (min_length == 1e9)
			printf("#%d 0\n", test);
		else
			printf("#%d %d\n", test, min_length);
	}

	return 0;
}