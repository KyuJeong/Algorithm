#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Pt {
	ll x, y;
};

int n;
Pt arr[100001];

ll ccw(const Pt &a, const Pt &b, const Pt &c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
}

bool cmp_y(const Pt &a, const Pt &b) {
	if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}

bool cmp_ccw(const Pt &a, const Pt &b) {
	ll cc = ccw(arr[0], a, b);
	if (cc != 0) return cc > 0;
	else return cmp_y(a, b);
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	stack <Pt> st;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr + n, cmp_y);
	sort(arr + 1, arr + n, cmp_ccw);

	st.push(arr[0]);
	st.push(arr[1]);

	Pt p1, p2, p3;

	for (int i = 2; i < n; i++) {
		p3 = arr[i];
		while (st.size() > 1) {
			p2 = st.top();
			st.pop();
			p1 = st.top();
			if (ccw(p1, p2, p3) > 0) {
				st.push(p2);
				break;
			}
		}
		st.push(p3);
	}

	cout << st.size();

	return 0;
}