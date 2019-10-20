#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 200002

struct Node {
	int sa;
	int r;
	int nr;
};

int n;
string str;
Node node[MAXN], tmp_node[MAXN];
int tmp[MAXN], inv[MAXN], cnt[MAXN + 1];
int lcp[MAXN];

void radixSort(int t, int m) {

	for (int i = 0; i < m + 1; i++)
		cnt[i] = 0;

	for (int i = 0; i < n; i++)
		cnt[node[i].nr + 1]++;
	for (int i = 1; i < m + 1; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
		tmp_node[--cnt[node[i].nr + 1]] = node[i];

	for (int i = 0; i < m + 1; i++)
		cnt[i] = 0;

	for (int i = 0; i < n; i++)
		cnt[tmp_node[i].r]++;
	for (int i = 1; i < m; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
		node[--cnt[tmp_node[i].r]] = tmp_node[i];
}

bool cmp(Node& a, Node& b) {
	if (a.r == b.r)	return a.nr < b.nr;
	return a.r < b.r;
}

void makeSA() {
	for (int i = 0; i < n; i++) {
		node[i].sa = i;
		node[i].r = str[i] - 'a';
		node[i].nr = (i + 1) < n ? str[i + 1] - 'a' : -1;
	}

	sort(node, node + n, cmp);
	for (int t = 2; ; t <<= 1) {
		tmp[0] = 0;
		for (int i = 1; i < n; i++) {
			if (cmp(node[i - 1], node[i]))
				tmp[i] = tmp[i - 1] + 1;
			else
				tmp[i] = tmp[i - 1];
		}

		if (tmp[n - 1] == n - 1) break;

		for (int i = 0; i < n; i++)
			inv[node[i].sa] = i;

		for (int i = 0; i < n; i++)
			node[i].r = tmp[i];

		for (int i = 0; i < n; i++) {
			int nxt = node[i].sa + t;
			node[i].nr = nxt < n ? node[inv[nxt]].r : -1;
		}

		radixSort(t, tmp[n - 1] + 1);
	}
}

void makeLCP() {
	for (int i = 0; i < n; i++)
		inv[node[i].sa] = i;
	int len = 0;
	for (int i = 0; i < n; i++) {
		int k = inv[i];
		if (k) {
			int j = node[k - 1].sa;
			while (str[j + len] == str[i + len]) len++;
			lcp[k] = len;
			if (len) len--;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> str;

	makeSA();
	makeLCP();

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = ans > lcp[i] ? ans : lcp[i];

	cout << ans;

	return 0;
}