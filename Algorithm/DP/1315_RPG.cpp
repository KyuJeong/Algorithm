#include <bits/stdc++.h>

using namespace std;

struct Node
{
	bool flag = false;
	int rem = 0;
};

struct Quest
{
	int s;
	int i;
	int p;
};

int n;
Node d[1001][1001]; // ���� i, ������ j�� ����Ʈ�� �� �� �ִ��� + ���� �� ���� ����Ʈ
vector <Quest> t(101);

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	int a, b, c;
	for (int i = 0; i < n; i++)
		cin >> t[i].s >> t[i].i >> t[i].p;

	int ans = 0;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			int cnt = 0;
			d[i][j].rem = 2 - i - j; // ���� ����Ʈ
			for (int k = 0; k < n; k++)
			{
				if (i >= t[k].s || j >= t[k].i) // ���� �� ������ ����Ʈ�� ������
				{
					d[i][j].rem += t[k].p;
					cnt++;
				}
			}

			if (i == 1 && j == 1)
				d[i][j].flag = true;
			else if (i > 1 && d[i - 1][j].flag && d[i - 1][j].rem > 0)
				d[i][j].flag = true;
			else if (j > 1 && d[i][j - 1].flag && d[i][j - 1].rem > 0)
				d[i][j].flag = true;

			if (d[i][j].flag)
				ans = max(cnt, ans);
		}
	}

	cout << ans;

	return 0;
}