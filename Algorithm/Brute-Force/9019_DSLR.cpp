#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int T, A, B;
char DSLR[5] = { ' ', 'D', 'S', 'L', 'R' };
bool visit[10000];

struct regi
{
	int num;
	int order;

	regi() {}

	regi(int _num, int _order)
	{
		num = _num;
		order = _order;
	}
};

regi BFS(int A)
{
	queue <regi> que;

	regi cur(A, 0);
	regi nxt;

	visit[A] = true;

	que.push(cur);

	while (!que.empty())
	{
		cur = que.front();
		que.pop();

		for (int i = 1; i < 5; i++)
		{
			if (DSLR[i] == 'D')
				nxt.num = (cur.num * 2) % 10000;
			else if (DSLR[i] == 'S')
				nxt.num = (9999 + cur.num) % 10000;
			else if (DSLR[i] == 'L')
			{
				int fir = cur.num / 1000;
				int rest = cur.num % 1000;
				nxt.num = rest * 10 + fir;
			}
			else
			{
				int lst = cur.num % 10;
				int rest = cur.num / 10;
				nxt.num = lst * 1000 + rest;
			}

			if (!visit[nxt.num])
			{
				visit[nxt.num] = true;

				nxt.order = cur.order * 10 + i;

				if (nxt.num == B)
					return nxt;

				que.push(nxt);
			}
		}
	}

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		for (int i = 0; i < 10000; i++)
			visit[i] = false;

		int ans_num = BFS(A).order;
		vector <int> ans;

		while (ans_num != 0)
		{
			ans.push_back(ans_num % 10);
			ans_num /= 10;
		}


	}

	return 0;
}