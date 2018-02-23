#include <iostream>
#include <queue>
using namespace std;

int N;
int K;
bool visit[100001];
int mov;

bool check_find(int _nxt)
{
	int nxt = _nxt;
	if (nxt == K)
		return true;

	visit[nxt] = true;

	return false;
}


void BFS(int start)
{
	int cur = start;

	if (cur == K)
		return;

	queue <pair <int, int>> q;
	q.push(make_pair(cur, 0));

	while (!q.empty())
	{
		cur = q.front().first;
		mov = q.front().second + 1;
		visit[cur] = true;
		q.pop();

		int nxt = cur + 1;
		if (nxt <= 100000 && nxt >= 0)
		{
			if (!visit[nxt])
			{
				if (check_find(nxt))
					return;
				q.push(make_pair(nxt, mov));
			}
		}

		nxt = cur - 1;
		if (nxt <= 100000 && nxt >= 0)
		{
			if (!visit[nxt])
			{
				if (check_find(nxt))
					return;
				q.push(make_pair(nxt, mov));
			}
		}

		nxt = cur * 2;
		if (nxt <= 100000 && nxt >= 0)
		{
			if (!visit[nxt])
			{
				if (check_find(nxt))
					return;
				q.push(make_pair(nxt, mov));
			}
		}
	}

}


int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	BFS(N);

	cout << mov;


	return 0;
}