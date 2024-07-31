#include <bits/stdc++.h>

using namespace std;

struct Student {
	int like[4];
};

int n;
int G[21][21];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int score_board[] = { 0,1,10,100,1000 };
vector <Student> v;

void setPlace(int cur) {
	int max_point = -1;
	int y = 0;
	int x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (G[i][j] != 0) continue;
			int point = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (G[ny][nx] == 0) point += 1;
				else {
					for (int l = 0; l < 4; l++) {
						if (G[ny][nx] == v[cur].like[l]) {
							point += 10;
							break;
						}
					}
				}
			}
			if (max_point < point) {
				max_point = point;
				y = i;
				x = j;
			}
		}
	}
	G[y][x] = cur;
}

int getScore() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				for (int l = 0; l < 4; l++) {
					if (G[ny][nx] == v[G[i][j]].like[l]) {
						cnt++;
						break;
					}
				}
			}
			ret += score_board[cnt];
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	v.resize(n * n + 1);

	for (int i = 0; i < n * n; i++) {
		int cur;
		cin >> cur;
		for (int j = 0; j < 4; j++)
			cin >> v[cur].like[j];
		setPlace(cur);
	}

	cout << getScore();

	return 0;
}