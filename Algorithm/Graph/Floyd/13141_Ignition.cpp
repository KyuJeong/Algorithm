#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

struct EDGE {
	int s, e, l;
};

int n, m;

int G[201][201];
vector <EDGE> edges;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)	G[i][j] = INF;

	for (int i = 1; i <= m; i++) {
		int s, e, l;
		cin >> s >> e >> l;
		l *= 2;
		G[s][e] = G[e][s] = min(G[s][e], l);
		edges.push_back({ s,e,l });
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

	int _min = INF;
	for (int i = 1; i <= n; i++) {
		int _max = 0;
		for (auto j : edges) {
			int dif = abs(G[i][j.s] - G[i][j.e]);

			int first_v = min(G[i][j.s], G[i][j.e]);
			if (dif <= j.l) _max = max(_max, first_v + dif + (j.l - dif) / 2);
			else _max = max(_max, first_v + j.l);
		}
		_min = min(_min, _max);
	}
	float ans = (float)_min / 2;
	cout << fixed;
	cout.precision(1);
	cout << ans;
}