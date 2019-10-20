#include <stdio.h>

#define MAXN 1000002

int tc;
int n;
int arr[MAXN], tmp[MAXN];
long long ans;

void mergeSort(int f, int e) {
	if (f >= e) return;
	int m = (f + e) / 2;
	mergeSort(f, m);
	mergeSort(m + 1, e);
	int l = f; int r = m + 1; int idx = f;
	while (l <= m || r <= e) {
		if (r > e || (l <= m && arr[l] < arr[r]))
			tmp[idx++] = arr[l++];
		else {
			tmp[idx++] = arr[r++];
			ans += m - l + 1;
		}
	}
	for (int i = f; i <= e; i++) { arr[i] = tmp[i]; }
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	mergeSort(0, n - 1);

	printf("%lld\n", ans);
	ans = 0;

	return 0;
}