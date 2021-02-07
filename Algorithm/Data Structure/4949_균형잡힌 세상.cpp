#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;

	while (getline(cin, s)) {
		if (s == ".") return 0;
		stack <char> st;
		bool flag = true;
		for (auto i : s) {
			if (i == '(' || i == '[') st.push(i);
			else if (i == ')') {
				if (!st.empty() && st.top() == '(') st.pop();
				else {
					flag = false;
					break;
				}
			}
			else if (i == ']') {
				if (!st.empty() && st.top() == '[') st.pop();
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag && st.empty()) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}