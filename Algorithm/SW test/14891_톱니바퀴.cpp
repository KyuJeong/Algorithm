#include <bits/stdc++.h>

using namespace std;

int n;
string s[4];
int rot[4];

void rotate(int a, int b) {
	if (b == 1) {
		int e = s[a][7];
		for (int i = 7; i > 0; i--)
			s[a][i] = s[a][i - 1];
		s[a][0] = e;
	}
	else {
		int e = s[a][0];
		for (int i = 0; i < 7; i++)
			s[a][i] = s[a][i + 1];
		s[a][7] = e;
	}
}

void moveLeft(int a, int b) {
	if (a > 0) {
		if (s[a][6] != s[a - 1][2]) moveLeft(a - 1, -b);
	}
	rotate(a, b);
}

void moveRight(int a, int b) {
	if (a < 3) {
		if (s[a][2] != s[a + 1][6]) moveRight(a + 1, -b);
	}
	rotate(a, b);
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++)
		cin >> s[i];

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		moveLeft(--a, b);
		rotate(a, -b);
		moveRight(a, b);
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (s[i][0] == '1') ans += pow(2, i);
	}

	cout << ans;

	return 0;
}