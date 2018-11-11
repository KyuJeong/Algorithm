#include <bits/stdc++.h>

using namespace std;

int n;

struct Node
{
	int val = 0;
	int cnt = 0;
	int idx = 0;
};

typedef vector <Node> vn;

vn v;

void merge(int l, int r)
{
	vn tmp;
	int m = (l + r) / 2;
	int l_ptr = l;
	int r_ptr = m + 1;

	while (l_ptr <= m && r_ptr <= r)
	{
		if (v[l_ptr].val < v[r_ptr].val)
			tmp.push_back(v[l_ptr++]);
		else
		{
			v[r_ptr].cnt += m - l_ptr + 1;
			tmp.push_back(v[r_ptr++]);
		}
	}

	if (l_ptr > m)
	{
		while (r_ptr <= r)
			tmp.push_back(v[r_ptr++]);
	}
	else
	{
		while (l_ptr <= m)
			tmp.push_back(v[l_ptr++]);
	}

	for (int i = 0; i < tmp.size(); i++)
		v[l + i] = tmp[i];
}

void mergeSort(int l, int r)
{
	if (l == r) return;

	int m = (l + r) / 2;
	mergeSort(l, m);
	mergeSort(m + 1, r);
	merge(l, r);
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].val;
		v[i].idx = i;
	}

	mergeSort(0, n - 1);

	sort(v.begin(), v.end(), [](const Node &n1, const Node &n2)
	{
		return n1.idx < n2.idx;
	});

	for (auto i : v)
		cout << i.cnt + 1 << "\n";

	return 0;
}