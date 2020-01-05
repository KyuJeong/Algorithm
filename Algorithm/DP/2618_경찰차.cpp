#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

#define fst first
#define snd second

typedef pair <int, int> pii;

int n, m, r, c;
vector <pii> v;
int d[1002][1002]; // 경찰차 1이 i를 마지막으로, 경찰차 2가 j를 마지막으로 했을 때의 최소거리
int w[1001][1001];
pii par[1002][1002];

void calcDist() {
	for (int i = 1; i <= m; i++) {
		w[i][0] = v[i].fst + v[i].snd - 2;
		w[0][i] = (n - v[i].fst) + (n - v[i].snd);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			w[i][j] = abs(v[i].fst - v[j].fst) + abs(v[i].snd - v[j].snd);
		}
	}
}

int solve(int a, int b) {
	if (d[a][b] != INF) return d[a][b];

	else if (a > b) {
		if (a - 1 != b) {
			int tmp = solve(a - 1, b) + w[a - 1][a];
			if (d[a][b] > tmp) {
				par[a][b] = { a - 1, b };
				d[a][b] = tmp;
			}
		}
		else {
			for (int i = 0; i <= a - 2; i++) {
				int tmp = solve(i, b) + w[a][i];
				if (d[a][b] > tmp) {
					par[a][b] = { i, b };
					d[a][b] = tmp;
				}
			}
		}
	}
	else {
		if (b - 1 != a) {
			int tmp = solve(a, b - 1) + w[b - 1][b];
			if (d[a][b] > tmp) {
				par[a][b] = { a, b - 1 };
				d[a][b] = tmp;
			}
		}
		else {
			for (int i = 0; i <= b - 2; i++) {
				int tmp = solve(a, i) + w[i][b];
				if (d[a][b] > tmp) {
					par[a][b] = { a,i };
					d[a][b] = tmp;
				}
			}
		}
	}

	return d[a][b];
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	v.resize(m + 1);

	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
			d[i][j] = INF;

	for (int i = 1; i <= m; i++)
		cin >> v[i].fst >> v[i].snd;

	calcDist();

	d[0][0] = 0;
	for (int i = 1; i <= m; i++) {
		d[i][0] = d[i - 1][0] + w[i][i - 1];
		par[i][0] = { i - 1, 0 };
		d[0][i] = d[0][i - 1] + w[i - 1][i];
		par[0][i] = { 0, i - 1 };
	}

	for (int i = 1; i < m; i++)
		solve(i, m);
	for (int i = 1; i < m; i++)
		solve(m, i);

	int _min = INF;
	pii path;
	for (int i = 1; i < m; i++) {
		if (_min > d[i][m]) {
			_min = d[i][m];
			path = { i,m };
		}
	}

	for (int i = 1; i < m; i++) {
		if (_min > d[m][i]) {
			_min = d[m][i];
			path = { m,i };
		}
	}

	vector <int> ans;
	cout << _min << "\n";
	for (int i = 0; i < m; i++) {
		if (path.fst == par[path.fst][path.snd].fst) ans.push_back(2);
		else ans.push_back(1);
		path = par[path.fst][path.snd];
	}

	for (int i = m - 1; i >= 0; i--)
		cout << ans[i] << "\n";

	return 0;
}