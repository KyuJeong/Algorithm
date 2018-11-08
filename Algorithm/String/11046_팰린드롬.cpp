#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> v;
int A[2010101];

void solution()
{
	int S = v.size();

	int R = 0;
	int p = 0;
	for (int i = 0; i < S; i++)
	{
		if (i <= R)
			A[i] = min(R - i, A[2 * p - i]);

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < S && (v[i - A[i] - 1] == v[i + A[i] + 1]))
			A[i]++;

		if (i + A[i] > R)
		{
			p = i;
			R = i + A[i];
		}
	}
}

bool f(int b, int e)
{
	int len = e - b + 1;
	b = (b - 1) * 2;
	e = (e - 1) * 2;
	int m = (b + e) / 2;

	if (A[m + 1] >= len) return true;
	else return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		v.push_back(-1);
		cin >> x;
		v.push_back(x);
	}
	v.push_back(-1);
	solution();
	cin >> m;

	int b, e;
	for (int i = 0; i < m; i++)
	{
		cin >> b >> e;
		if (f(b, e)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}