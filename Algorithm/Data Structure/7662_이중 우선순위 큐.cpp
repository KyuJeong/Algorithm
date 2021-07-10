#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int tc, n, x;
char c;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> tc;

	while (tc--) {
		cin >> n;
		priority_queue <pii> max_heap;
		priority_queue <pii, vector<pii>, greater<pii>> min_heap;
		bool chk[1000001];

		for (int i = 0; i < n; i++) {
			cin >> c >> x;
			if (c == 'I') {
				max_heap.push({ x, i });
				min_heap.push({ x, i });
				chk[i] = true;
			}
			else {
				if (x == 1) {
					while (!max_heap.empty() && !chk[max_heap.top().second]) max_heap.pop();
					if (!max_heap.empty()) {
						chk[max_heap.top().second] = false;
						max_heap.pop();
					}
				}
				else {
					while (!min_heap.empty() && !chk[min_heap.top().second]) min_heap.pop();
					if (!min_heap.empty()) {
						chk[min_heap.top().second] = false;
						min_heap.pop();
					}
				}
			}
		}
		while (!max_heap.empty() && !chk[max_heap.top().second]) max_heap.pop();
		while (!min_heap.empty() && !chk[min_heap.top().second]) min_heap.pop();

		if (max_heap.empty()) cout << "EMPTY\n";
		else cout << max_heap.top().first << " " << min_heap.top().first << "\n";

	}

	return 0;
}