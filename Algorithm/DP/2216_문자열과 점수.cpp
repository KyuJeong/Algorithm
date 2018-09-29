#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int d[3001][3001]; // X의 i번째 문자열, Y의 j번째 문자열까지의 최대 점수
string x, y;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> a >> b >> c;
	cin >> x >> y;
	x = " " + x;
	y = " " + y;
	int x_sz = x.size() - 1;
	int y_sz = y.size() - 1;

	for (int i = 1; i <= x_sz; i++)
		d[i][0] = b * i;
	for (int i = 1; i <= y_sz; i++)
		d[0][i] = b * i;

	for (int i = 1; i <= x_sz; i++)
	{
		for (int j = 1; j <= y_sz; j++)
		{
			if (x[i] == y[j]) d[i][j] = d[i - 1][j - 1] + a;
			else
			{
				d[i][j] = max(d[i - 1][j], d[i][j - 1]) + b;
				d[i][j] = max(d[i][j], d[i - 1][j - 1] + c);
			}
		}
	}

	cout << d[x_sz][y_sz];

	return 0;
}