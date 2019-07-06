#include <bits/stdc++.h>

using namespace std;

int n, m;
bool broken[11];

bool chk(int num)
{
	if (num == 0 && broken[0]) return false;
	while (num > 0)
	{
		int x = num % 10;
		if (broken[x]) return false;
		num /= 10;
	}
	return true;
}

int digit(int num)
{
	if (num == 0) return 1;
	int ret = 0;
	while (num > 0)
	{
		num /= 10;
		ret++;
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		broken[tmp] = true;
	}

	int ans = abs(n - 100);

	int num = n;
	while (1)
	{
		if (chk(num--))
		{
			int cnt = digit(++num) + n - num;
			ans = min(ans, cnt);
			break;
		}
		if (n - num > ans || num < 0) break;
	}

	num = n;
	while (1)
	{
		if (chk(num++))
		{
			int cnt = digit(--num) + num - n;
			ans = min(ans, cnt);
			break;
		}
		if (num - n > ans) break;
	}

	cout << ans;

	return 0;
}