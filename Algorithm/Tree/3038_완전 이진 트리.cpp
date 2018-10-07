#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int n;
int sz;
vi t;
vi expand(vi pre, int level)
{
	if (level == n - 1)
		return pre;
	vi cur(1);
	int h = pow(2, level);
	cur.push_back(1); // 루트는 항상 1로

	int idx = 1;
	while (idx <= h)
	{
		for (int i = 0; i < idx; i++)
		{
			int num = pre[idx + i] * 2; // 전 레벨의 트리 값에 *2
			if (idx == h) cur.push_back(num); // 리프노드이면 그냥 더함
			else cur.push_back(num + 1); // 아니면 + 1
		}
		for (int i = 0; i < idx; i++)
		{
			int num = pre[idx + i] * 2;
			if (idx == h) cur.push_back(num + 1); // 리프노드이면 + 1
			else cur.push_back(num);
		}
		idx <<= 1;
	}
	return expand(cur, level + 1);
}

void print(int idx)
{
	if (idx >= sz) return;
	cout << t[idx] << " ";
	print(idx << 1);
	print(idx << 1 | 1);
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	vi tmp(1);
	tmp.push_back(1);
	t = expand(tmp, 0);

	sz = pow(2, n);
	print(1);

	return 0;
}