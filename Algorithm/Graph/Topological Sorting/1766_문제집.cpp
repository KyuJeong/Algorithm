#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define MAX 32001

using namespace std;

int N, M;
int A, B;
vector <int> v[MAX];
int inde[MAX];
vector <int> ans;
priority_queue <int, vector <int>, greater<int>> pq;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
		inde[B]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (inde[i] == 0)
			pq.push(i);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		ans.push_back(cur);
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			inde[nxt]--;
			if (inde[nxt] == 0)
				pq.push(nxt);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}