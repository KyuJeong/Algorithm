#include <bits/stdc++.h>

using namespace std;

stack <int> st;
vector <int> vt;
string ans;

int main() {

	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vt.resize(n);

	for (int i = 0; i < n; i++)
		cin >> vt[i];

	int nxt = 1;

	for (int i = 0; i < n; i++) {
		if (!st.empty() && st.top() > vt[i]) {
			cout << "NO";
			return 0;
		}
		while (st.empty() || st.top() != vt[i]) {
			st.push(nxt++);
			ans += '+';
		}
		st.pop();
		ans += '-';
	}

	for (auto i : ans)
		cout << i << "\n";

	return 0;
}