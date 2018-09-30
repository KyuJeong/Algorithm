#include <bits/stdc++.h>

using namespace std;

char G[8][3];
string s = "BGORWY";

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	for (int i = 0; i < 8; i++)
		cin >> G[i][0] >> G[i][1] >> G[i][2];

	char c = G[0][0];

	vector <char> v[8];
	int v_idx = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (G[i][j] == c)
			{
				v[v_idx].push_back(G[i][(j + 1) % 3]);
				v[v_idx++].push_back(G[i][(j + 2) % 3]);
			}
		}
	}

	if (v_idx != 4)
	{
		cout << "NO";
		return 0;
	}

	bool check[6] = { false };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (v[i][0] == s[j])
				check[j] = true;
			if (v[i][1] == s[j])
				check[j] == true;
		}
	}

	int check_cnt = 0;
	int check_idx = 0;
	for (int i = 0; i < 6; i++)
	{
		if (s[i] == c)
			check[i] = true;
	}

	for (int i = 0; i < 6; i++)
	{
		if (check[i] == false)
		{
			check_idx = i;
			check_cnt++;
		}
	}

	if (check_cnt != 1)
	{
		cout << "NO";
		return 0;
	}

	c = s[check_idx];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (G[i][j] == c)
			{
				v[v_idx].push_back(G[i][(j + 1) % 3]);
				v[v_idx++].push_back(G[i][(j + 2) % 3]);
			}
		}
	}

	if (v_idx != 8)
	{
		cout << "NO";
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		char a = v[i][0];
		char b = v[i][1];
		for (int j = 4; j < 8; j++)
		{
			if (v[j][0] == b && v[j][1] == a)
				cnt++;
		}
	}

	if (cnt == 4)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}