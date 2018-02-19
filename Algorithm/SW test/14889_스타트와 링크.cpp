#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int G[21][21];
vector <vector <int>> v;
int DP[21][21];
int sum_total;
int min_dif = 1e9;

/* 팀을 나누는 경우의 수 구하기 */
inline void Permutation(int cur, vector <int> picked)
{
	if (cur == 1)
	{
		v.push_back(picked);
		return;
	}

	int nxt = picked.back() + 1;

	for (int i = nxt; i <= N; i++)
	{
		picked.push_back(i);
		Permutation(cur - 1, picked);
		picked.pop_back();
	}
}

/* 두 사람이 팀이 됐을 때 더해지는 능력치 계산 */
inline void CalStat(int a, int b)
{
	if (DP[a][b])
		return;

	DP[a][b] += G[a][b];
	DP[a][b] += G[b][a];
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> G[i][j];
			sum_total += G[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			CalStat(i, j);
		}
	}

	vector <int> tmp;
	tmp.push_back(1);

	Permutation(N / 2, tmp);

	for (int i = 0; i < v.size(); i++)
	{
		int sum_start = 0;
		int sum_link = 0;

		bool check[21] = { false };

		for (int j = 0; j < N / 2; j++)
		{
			for (int k = j + 1; k < N / 2; k++)
			{
				int a = v[i][j];
				int b = v[i][k];
				sum_start += DP[a][b];
				check[a] = true;
				check[b] = true;
			}
		}

		for (int j = 1; j <= N; j++)
		{
			for (int k = j + 1; k <= N; k++)
			{
				if (!check[j] && !check[k])
					sum_link += DP[j][k];
			}
		}
		min_dif = min(min_dif, abs(sum_start - sum_link));
	}
	
	cout << min_dif;

	return 0;
}