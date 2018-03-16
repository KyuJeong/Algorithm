#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair <int, int> pii;

int N;
int A[1001];
bool visit[1001];

int BFS()
{
	queue <pii> q;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		int idx = cur.first;
		int cnt = cur.second;
		if (idx == N)
			return cnt;
		if (visit[idx])
			continue;
		visit[idx] = true;
		for (int i = 1; i <= A[idx]; i++)
		{
			q.push({ idx + i, cnt + 1 });
		}
	}

	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= 1000; i++)
	{
		cin >> A[i];
	}

	cout << BFS();

	return 0;
}