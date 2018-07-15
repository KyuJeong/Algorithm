#include <bits/stdc++.h>

using namespace std;

int A[1001];
int C[1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> C[i];

	for (int i = 0; i < m; i++)
		cin >> A[i];

	int l = 0;
	int ptr = 0;
	int ans = 0;

	while (l < n)
	{
		if (A[ptr] >= C[l])
		{
			ptr++;
		}
		l++;
	}

	cout << ptr;

	return 0;
}