#include <bits/stdc++.h>

using namespace std;

int d[21][21][21];

int f(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return f(20, 20, 20);

	int &ret = d[a][b][c];
	if (ret != -1) return ret;

	if (a < b && b < c)
		ret = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
	else
		ret = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);

	return ret;
}

int main()
{
	memset(d, -1, sizeof(d));
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c))
	{
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));
	}

	return 0;
}