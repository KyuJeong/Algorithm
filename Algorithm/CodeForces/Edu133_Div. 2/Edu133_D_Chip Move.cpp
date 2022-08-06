#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 200001
#define MOD 998244353

ll sum[MAX];
ll pre[MAX];
ll cur[MAX];
int n, k;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	int start = k;

	for (int i = k; i <= n; i += k) {
		sum[i] = 1;
		pre[i] = 1;
	}

	for (int i = k + 1; i <= n; i++) {
		start += i;
		if (start >= n) break;
		for (int j = start; j <= n; j++) {
			cur[j] = (cur[j - i] + pre[j - i]) % MOD;
			sum[j] = (sum[j] + cur[j]) % MOD;
		}
		for (int j = start; j <= n; j++) {
			pre[j] = cur[j];
			cur[j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) cout << sum[i] << " ";

	return 0;
}