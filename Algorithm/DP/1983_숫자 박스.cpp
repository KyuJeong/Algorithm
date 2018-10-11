#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int n;
vi a(1);
vi b(1);
int d[401][401][401]; // ÃÑ iÄ­À» Ã¤¿ü°í, a¸¦ j°³, b¸¦ k°³ »ç¿ëÇßÀ» ¶§ÀÇ ÃÖ´ñ°ª

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp != 0) a.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp != 0) b.push_back(tmp);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < a.size(); j++)
		{
			for (int k = 1; k < b.size(); k++)
			{
				if (j > i || k > i) continue;

				int val = d[i - 1][j - 1][k - 1] + a[j] * b[k];
				if (i >= j + 1)
					val = max(val, d[i - 1][j][k - 1]);
				if (i >= k + 1)
					val = max(val, d[i - 1][j - 1][k]);
				d[i][j][k] = val;
			}
		}
	}

	cout << d[n][a.size() - 1][b.size() - 1];

	return 0;
}