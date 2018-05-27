#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int N, M;
int train[MAX];
bool check[1500000];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	int order;

	for (int i = 0; i < M; i++)
	{
		int idx, x;
		cin >> order;
		if (order == 1)
		{
			cin >> idx >> x;
			x = 20 - x;
			train[idx] |= (1 << x);
		}
		else if (order == 2)
		{
			cin >> idx >> x;
			x = 20 - x;
			int tmp = (1 << 20) - 1;
			tmp -= (1 << x);
			train[idx] &= tmp;
		}
		else if (order == 3)
		{
			cin >> idx;
			train[idx] >>= 1;
		}
		else
		{
			cin >> idx;
			train[idx] <<= 1;
			int tmp = (1 << 20) - 1;
			train[idx] &= tmp;
		}
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!check[train[i]])
		{
			check[train[i]] = true;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}