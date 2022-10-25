#include <bits/stdc++.h>

using namespace std;

int n, r;

char arr[16];
char input[16];
char vowels[6] = { "aeiou" };

bool chk_condition() {
	int con = 0;
	int vow = 0;

	for (int i = 0; i < r; i++) {
		bool chk = false;
		for (int j = 0; j < 5; j++) {
			if (arr[i] == vowels[j]) {
				chk = true;
				break;
			}
		}
		if (chk) vow++;
		else con++;
	}

	if (vow >= 1 && con >= 2) return true;
	else return false;
}

void comb(int x, int nxt) {
	if (x == r) {
		if (chk_condition()) {
			for (int i = 0; i < r; i++)
				cout << arr[i];
			cout << "\n";
		}
		return;
	}

	for (int i = nxt; i <= n; i++) {
		arr[x] = input[i - 1];
		comb(x + 1, i + 1);
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> r >> n;

	for (int i = 0; i < n; i++) cin >> input[i];
	sort(input, input + n);

	comb(0, 1);

	return 0;
}