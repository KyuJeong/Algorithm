#include <bits/stdc++.h>

using namespace std;

int n, x, num;
string s;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s != "all" && s != "empty") cin >> x;
		x--;
		x = (1 << x);
		if (s == "add") num |= x;
		else if (s == "remove") num &= ~x;
		else if (s == "check") {
			if (num & x) cout << "1\n";
			else cout << "0\n";
		}
		else if (s == "toggle") num ^= x;
		else if (s == "all") num = 0xfffff;
		else num = 0;
	}

	return 0;
}