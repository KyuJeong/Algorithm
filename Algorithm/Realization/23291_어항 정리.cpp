#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[102];
int G[102][102];

void insert_fish() {
	int min_val = 1e9;
	for (int i = 0; i < n; i++) {
		if (min_val > arr[i]) min_val = arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == min_val) arr[i]++;
	}
}

void stack_bowl() {
	memset(G, 0, sizeof(G));

	for (int i = 0; i < n; i++) {
		G[100][i] = arr[i];
	}

	int left = 0;
	int width = 1, height = 1;

	int c = 4;
	while (left + width + height <= n) {
		int cube[101][101] = { 0 };
		for (int y = 0; y < width; y++) {
			for (int x = 0; x < height; x++) {
				cube[y][x] = G[100 - x][left + y];
				G[100 - x][left + y] = 0;
			}
		}

		left = left + width;
		int tmp = width;
		width = height;
		height = tmp + 1;

		for (int y = 0; y < height - 1; y++) {
			for (int x = 0; x < width; x++) {
				G[101 - height + y][left + x] = cube[y][x];
			}
		}

	}

}

void adjust_fish() {
	int dif[102][102] = { 0 };
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (G[y][x] != 0 && G[y][x + 1] != 0) {
				if (G[y][x] - G[y][x + 1] >= 5) {
					int quot = (G[y][x] - G[y][x + 1]) / 5;
					dif[y][x] += -quot;
					dif[y][x + 1] += quot;
				}
				else if (G[y][x + 1] - G[y][x] >= 5) {
					int quot = (G[y][x + 1] - G[y][x]) / 5;
					dif[y][x + 1] += -quot;
					dif[y][x] += quot;
				}
			}

			if (G[y][x] != 0 && G[y + 1][x] != 0) {
				if (G[y][x] - G[y + 1][x] >= 5) {
					int quot = (G[y][x] - G[y + 1][x]) / 5;
					dif[y][x] += -quot;
					dif[y + 1][x] += quot;
				}
				else if (G[y + 1][x] - G[y][x] >= 5) {
					int quot = (G[y + 1][x] - G[y][x]) / 5;
					dif[y + 1][x] += -quot;
					dif[y][x] += quot;
				}
			}
		}

	}

	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (dif[y][x] != 0) {
				G[y][x] += dif[y][x];
			}
		}
	}

}

void linear() {
	int cnt = 0;
	for (int x = 0; x < 101; x++) {
		for (int y = 100; y >= 0; y--) {
			if (G[y][x] == 0) break;
			arr[cnt++] = G[y][x];
		}
	}
}

void stack_bowl2() {
	memset(G, 0, sizeof(G));

	for (int i = 0; i < n; i++) {
		G[100][i] = arr[i];
	}

	for (int x = 0; x < n / 2; x++) {
		G[99][n - 1 - x] = G[100][x];
		G[100][x] = 0;
	}

	for (int x = 0; x < n / 4; x++) {
		G[98][n - 1 - x] = G[99][n / 2 + x];
		G[99][n / 2 + x] = 0;
		G[97][n - 1 - x] = G[100][n / 2 + x];
		G[100][n / 2 + x] = 0;
	}

}

int get_dif() {
	int _max = -1e9;
	int _min = 1e9;
	for (int i = 0; i < n; i++) {
		if (_max < arr[i]) _max = arr[i];
		if (_min > arr[i]) _min = arr[i];
	}
	return _max - _min;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int cnt = 0;
	while (get_dif() > k) {
		insert_fish();
		stack_bowl();
		adjust_fish();
		linear();
		stack_bowl2();
		adjust_fish();
		linear();
		cnt++;
	}
	cout << cnt;
}