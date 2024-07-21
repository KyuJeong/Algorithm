#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[1500000];

void move(char pre, char nxt) {
	s[k++] = pre;
	s[k++] = ' ';
	s[k++] = nxt;
	s[k++] = '\n';
}

void hanoi(int num, char pre, char nxt) {
	if (num <= 0) return;

	char tmp = 'F' + '@' - pre + '@' - nxt;
	hanoi(num - 1, pre, tmp);
	move(pre, nxt);
	hanoi(num - 1, tmp, nxt);
}

void solve(int num, char pre, char nxt) {
	if (num <= 0) return;
	if (num == 1) {
		move(pre, 'D');
		return;
	}

	char tmp = 'F' + '@' - pre + '@' - nxt;
	hanoi(num - 2, pre, nxt);
	move(pre, tmp);
	move(pre, 'D');
	move(tmp, 'D');
	solve(num - 2, nxt, pre);
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	solve(n, 'A', 'C');

	cout << k / 4 << "\n";
	cout << s;

	return 0;
}