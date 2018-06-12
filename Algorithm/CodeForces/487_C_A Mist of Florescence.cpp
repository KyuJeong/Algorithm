#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
char G[100][100];
int cnt[4];

void fill_a()
{
	int cnt = 0;
	for (int i = 0; i < 10; i+=2)
	{
		for (int j = 0; j < 50; j += 2)
		{
			G[i][j] = 'A';
			if (++cnt == a)
				return;
		}
	}
}

void fill_b()
{
	int cnt = 0;
	for (int i = 1; i < 11; i += 2)
	{
		for (int j = 0; j < 50; j += 2)
		{
			G[i][j] = 'B';
			if (++cnt == b)
				return;
		}
	}
}

void fill_c()
{
	int cnt = 1;
	if (cnt == c)
		return;
	for (int i = 49; i >= 39; i -= 2)
	{
		for (int j = 0; j < 50; j += 2)
		{
			G[i][j] = 'C';
			if (++cnt == c)
				return;
		}
	}
}

void fill_d()
{
	int cnt = 1;
	if (cnt == d)
		return;
	for (int i = 12; i < 22; i += 2)
	{
		for (int j = 0; j < 50; j += 2)
		{
			G[i][j] = 'D';
			if (++cnt == d)
				return;
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> a >> b >> c >> d;

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			G[i][j] = 'C';
		}
	}

	for (int i = 25; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			G[i][j] = 'D';
		}
	}

	fill_a();
	fill_b();
	fill_c();
	fill_d();

	cout << "50 50\n";

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			cout << G[i][j];
		}
		cout << "\n";
	}


	return 0;
}