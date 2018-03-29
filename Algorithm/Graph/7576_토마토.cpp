#include <iostream>
#include <queue>

using namespace std;

typedef pair <int, int> pii;

int M, N;
int G[1001][1001];
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };
int cnt;
int total;
bool visit[1001][1001];
queue <pii> q;

int BFS()
{
	int day = -1;
	
	while (!q.empty())
	{
		day++;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			if (visit[cy][cx])
				continue;
			visit[cy][cx] = true;

			for (int j = 0; j < 4; j++)
			{
				int ny = cy + my[j];
				int nx = cx + mx[j];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
					continue;
				if (visit[ny][nx] || G[ny][nx] != 0)
					continue;

				cnt++;
				G[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}

	if (cnt == total)
		return day;

	return -1;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == 1)
			{
				cnt++;
				q.push({ i,j });
				total++;
			}
			if (G[i][j] == 0)
				total++;
		}
	}

	if (cnt == M * N)
	{
		cout << "0";
		return 0;
	}


	int ans = BFS();

	cout << ans;

	return 0;
}