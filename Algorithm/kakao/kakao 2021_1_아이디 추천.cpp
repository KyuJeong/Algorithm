#include <bits/stdc++.h>

using namespace std;

string s;

string solve(string ss) {
	for (auto &i : s) {
		if (i >= 'A' && i <= 'Z') {
			i += 32;
		}
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') continue;
		if (s[i] >= '0' && s[i] <= '9') continue;
		if (s[i] == '-' || s[i] == '_' || s[i] == '.') continue;
		s.erase(i, 1);
		i--;
	}

	int b, e;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			int cnt = -1;
			for (int j = i + 1; j < s.size(); j++) {
				cnt++;
				if (s[j] == '.') continue;
				else {
					break;
				}
			}
			s.erase(i, cnt);
		}
	}

	// 4´Ü°è
	if (s[0] == '.') s.erase(0, 1);
	if (s.size() != 0 && s[s.size() - 1] == '.') s.erase(s.size() - 1, 1);

	if (s.size() == 0) s = 'a';
	if (s.size() > 15) {
		s.erase(15);
		if (s.size() != 0 && s[s.size() - 1] == '.') s.erase(s.size() - 1, 1);
	}

	if (s.size() == 1) {
		s += s[0];
		s += s[0];
	}
	else if (s.size() == 2) s += s[1];

	return ss;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s;

	string ans = solve(s);

	cout << ans;

	return 0;
}