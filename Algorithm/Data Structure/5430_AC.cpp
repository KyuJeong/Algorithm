#include <bits/stdc++.h>

using namespace std;

int tc, n;
string p;
int arr[100001];

void parse(string s) {
	if (n == 0) return;
	int num = 0;
	int idx = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == ',' || s[i] == ']') {
			arr[idx++] = num;
			num = 0;
		}
		else
			num = 10 * num + (s[i] - '0');
	}

}

void solve() {
	int s = 0;
	int e = n - 1;
	bool flag = true;
	for (auto i : p) {
		if (i == 'R') {
			if (flag) flag = false;
			else flag = true;
		}
		else {
			if (s > e) {
				cout << "error\n";
				return;
			}
			if (flag) s++;
			else e--;
		}
	}

	if (s > e) {
		cout << "[]\n";
		return;
	}
	cout << "[";
	if (flag) {
		for (int i = s; i < e; i++)
			cout << arr[i] << ",";
		cout << arr[e] << "]\n";
	}
	else {
		for (int i = e; i > s; i--)
			cout << arr[i] << ",";
		cout << arr[s] << "]\n";
	}
}


int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> tc;

	while (tc--) {
		cin >> p >> n;
		string s;
		cin >> s;
		parse(s);
		solve();
	}

	return 0;
}