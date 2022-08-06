#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> v;
vector <int> chk;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		v.push_back(i);

	for (int i = 1; i <= n; i++)
		chk.push_back(1);

	for (int i = n + 1; i <= m; i++)
		chk.push_back(0);

	do {
		for (int i = 0; i < m; i++) {
			if (chk[i] == 1) {
				cout << v[i] << " ";
			}
		}
		cout << "\n";
	} while (prev_permutation(chk.begin(), chk.end()));

	return 0;
}