#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int n, s, a, b;
int G[202][202];

void init(vector<vector<int>>& fares) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				G[i][j] = INF;
		}
	}

	for (auto i : fares) {
		G[i[0]][i[1]] = i[2];
		G[i[1]][i[0]] = i[2];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (G[j][i] == INF)
				continue;
			for (int k = 1; k <= n; k++) {
				if (G[j][k] > G[j][i] + G[i][k])
					G[j][k] = G[j][i] + G[i][k];
			}
		}
	}
}

int solution(int _n, int _s, int _a, int _b, vector<vector<int>> fares) {
	n = _n;
	s = _s;
	a = _a;
	b = _b;

	init(fares);

	int answer = INF;

	for (int i = 1; i <= n; i++) {
		if (G[s][i] == INF || G[i][a] == INF || G[b][i] == INF) continue;
		int cost = G[s][i] + G[i][a] + G[b][i];
		answer = min(answer, cost);
	}

	return answer;
}

vector<vector<int>> v;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	v.resize(5);
	v[0] = { 5,7,9 };
	v[1] = { 4,6,4 };
	v[2] = { 3,6,1 };
	v[3] = { 3,2,3 };
	v[4] = { 2,1,6 };

	int z, x, c, t;
	z = 7;
	x = 3;
	c = 4;
	t = 1;

	int ans = solution(z, x, c, t, v);

	cout << ans;

	return 0;
}