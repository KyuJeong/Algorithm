#include <bits/stdc++.h>

using namespace std;

int m[5];
int chk[14];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> m[i];
		chk[m[i]]++;
	}

	bool a = false;
	bool b = false;

	for (int i = 0; i < 14; i++) {
		if (chk[i] == 2) a = true;
		if (chk[i] == 3) b = true;
	}

	if (a == true && b == true) cout << "Yes";
	else cout << "No";

	return 0;
}