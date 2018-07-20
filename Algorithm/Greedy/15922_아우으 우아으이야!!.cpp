#include <bits/stdc++.h>

using namespace std;

#define INF 1000000001

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	int x, y;
	cin >> N;
	int y_max = -INF;
	int len = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		if (y <= y_max)
			continue;
		len += y - max(x, y_max);
		y_max = y;
	}

	cout << len;

	return 0;
}