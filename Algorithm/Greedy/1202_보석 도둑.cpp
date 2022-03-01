#include <bits/stdc++.h>

using namespace std;

#define MAXN 300001
#define M first
#define V second

int n, m;
pair <int, int> A[MAXN];
int C[MAXN];
priority_queue<int> pq;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> A[i].M >> A[i].V;

	for (int i = 0; i < m; i++)
		cin >> C[i];

	sort(A, A + n);
	sort(C, C + m);

	int idx = 0;
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		while (idx < n && A[idx].M <= C[i]) pq.push(A[idx++].V);
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}