#include <bits/stdc++.h>

using namespace std;

string s;

int main() {

	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (1) {
		cin >> s;
		if (s == "0") break;
		int n = s.size();
		string f = s.substr(0, (n + 1) / 2);
		string e = s.substr(n / 2, n);
		reverse(f.begin(), f.end());
		if (f == e) cout << "yes\n";
		else cout << "no\n";
	}

}