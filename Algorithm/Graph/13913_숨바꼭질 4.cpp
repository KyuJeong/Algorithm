#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 200001

struct Sr
{
	int x;
	int prt;
	int time;
	Sr() 
	{
		x = -1;
		prt = -1;
		time = -1;
	};
	Sr(int _x, int _prt, int _time)
	{
		x = _x;
		prt = _prt;
		time = _time;
	}
};

int N, K;
int G[MAX];
int parent[MAX];

int BFS(int x)
{
	queue <Sr> q;
	q.push(Sr(x, -1, 0));

	Sr cur;
	
	while (1)
	{
		cur = q.front();
		q.pop();

		if (cur.x < 0 || cur.x >= MAX)
			continue;
		if (parent[cur.x] != -1)
			continue;

		parent[cur.x] = cur.prt;

		if (cur.x == K)
			return cur.time;

		q.push(Sr(cur.x + 1, cur.x, cur.time + 1));
		q.push(Sr(cur.x - 1, cur.x, cur.time + 1));
		q.push(Sr(cur.x * 2, cur.x, cur.time + 1));

	}

}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> N >> K;

	if (N == K)
	{
		cout << "0\n";
		cout << N;
		return 0;
	}

	memset(G, -1, sizeof(G));
	memset(parent, -1, sizeof(parent));

	G[N] = 1;

	int ans = BFS(N);

	cout << ans << "\n";

	vector <int> v;
	v.push_back(K);

	int idx = K;
	while (parent[idx] != N)
	{
		idx = parent[idx];
		v.push_back(idx);
	}
	v.push_back(N);

	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i] << " ";
	}
	
	return 0;
}