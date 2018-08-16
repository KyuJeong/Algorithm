#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int k;
int ans;

void solveA(int exp, int y, int x);
void solveB(int exp, int y, int x);
void solveC(int exp, int y, int x);
void solveD(int exp, int y, int x);

void solveA(int exp, int y, int x)
{
	if (exp == 0)
	{
		ans++;
		if (ans == m)
		{
			cout << x << " " << y;
			exit(0);
		}
		return;
	}
	int len = (1 << (exp - 1));
	if (ans + (len << 1) * (len << 1) < m)
	{
		ans += (len << 1) * (len << 1);
		return;
	}

	solveB(exp - 1, y, x);
	solveA(exp - 1, y + len, x);
	solveA(exp - 1, y + len, x + len);
	solveC(exp - 1, y + len - 1, x + len + len - 1);
}

void solveB(int exp, int y, int x)
{
	if (exp == 0)
	{
		ans++;
		if (ans == m)
		{
			cout << x << " " << y;
			exit(0);
		}
		return;
	}
	int len = (1 << (exp - 1));
	if (ans + (len << 1) * (len << 1) < m)
	{
		ans += (len << 1) * (len << 1);
		return;
	}

	solveA(exp - 1, y, x);
	solveB(exp - 1, y, x + len);
	solveB(exp - 1, y + len, x + len);
	solveD(exp - 1, y + len + len - 1, x + len - 1);
}

void solveC(int exp, int y, int x)
{
	if (exp == 0)
	{
		ans++;
		if (ans == m)
		{
			cout << x << " " << y;
			exit(0);
		}
		return;
	}
	int len = (1 << (exp - 1));
	if (ans + (len << 1) * (len << 1) < m)
	{
		ans += (len << 1) * (len << 1);
		return;
	}

	solveD(exp - 1, y, x);
	solveC(exp - 1, y, x - len);
	solveC(exp - 1, y - len, x - len);
	solveA(exp - 1, y - len - len + 1, x - len + 1);
}

void solveD(int exp, int y, int x)
{
	if (exp == 0)
	{
		ans++;
		if (ans == m)
		{
			cout << x << " " << y;
			exit(0);
		}
		return;
	}
	int len = (1 << (exp - 1));
	if (ans + (len << 1) * (len << 1) < m)
	{
		ans += (len << 1) * (len << 1);
		return;
	}

	solveC(exp - 1, y, x);
	solveD(exp - 1, y - len, x);
	solveD(exp - 1, y - len, x - len);
	solveB(exp - 1, y - len + 1, x - len - len + 1);
}

int main()
{
	cin >> n >> m;
	int c = 1;
	while (c < n)
		c *= 2, k++;

	solveA(k, 1, 1);

	return 0;
}