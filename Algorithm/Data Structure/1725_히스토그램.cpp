#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll arr[100002];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	stack <ll> st;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	st.push(0);
	ll _max = 0;
	for (int i = 1; i <= n + 1; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			ll height = arr[st.top()];
			st.pop();
			ll width;
			if (st.empty()) width = 1;
			else width = i - st.top() - 1;
			_max = max(_max, width * height);
		}
		st.push(i);
	}

	cout << _max;

	return 0;
}