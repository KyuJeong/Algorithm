#include <bits/stdc++.h>

using namespace std;

struct Pt
{
	int y, x;
	Pt() {}
	Pt(int _y, int _x) : y(_y), x(_x) {}
};

int n, m;
int G[51][51];
vector <Pt> house;
vector <Pt> chic;

int dist(Pt a, Pt b) { return abs(a.x - b.x) + abs(a.y - b.y); }

int solve()
{
	int chic_len = chic.size();
	vector <int> arr;

	for (int i = 0; i < m; i++)
		arr.push_back(0);

	for (int i = m; i < chic_len; i++)
		arr.push_back(1);

	int ret = 1e9;

	do
	{
		int sum = 0;
		for (auto i : house)
		{
			int _min = 1e9;
			for (int j = 0; j < chic_len; j++)
			{
				if (arr[j] == 0)
					_min = min(_min, dist(i, chic[j]));
			}
			sum += _min;
		}

		ret = min(ret, sum);
	} while (next_permutation(arr.begin(), arr.end()));

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == 1) house.push_back({ i,j });
			else if (G[i][j] == 2) chic.push_back({ i,j });
		}
	}

	cout << solve();

	return 0;
}