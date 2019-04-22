#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int n;
vi in;
vi post;

void solve(int in_idx, int post_idx, int cnt)
{
	if (cnt == 0) return;
	if (cnt == 1)
	{
		cout << post[post_idx] << " ";
		return;
	}
	int root_idx = post_idx + cnt - 1;
	int root_val = post[root_idx];

	cout << root_val << " ";

	// ¿ÞÂÊ subtree Å½»ö
	int left_cnt = in[root_val] - in_idx;
	solve(in_idx, post_idx, left_cnt);

	// ¿À¸¥ÂÊ subtree Å½»ö
	int right_cnt = cnt - left_cnt - 1;
	solve(in[root_val] + 1, post_idx + left_cnt, right_cnt);
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	in.resize(n + 1);
	post.resize(n + 1);

	int tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		in[tmp] = i;
	}

	for (int i = 1; i <= n; i++)
		cin >> post[i];

	solve(1, 1, n);

	return 0;
}