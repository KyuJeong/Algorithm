#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector <int> pi;
int len;

int getpi() {
	len = s.size();
	pi.clear();
	pi.resize(len);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}

	return pi[len - 1];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> s) {
		if (s == ".") break;
		int ans = 1;
		int max_pi = getpi();
		if (max_pi != 0 && len % (len - max_pi) == 0)
			ans = len / (len - max_pi);
		cout << ans << "\n";
	}

	return 0;
}