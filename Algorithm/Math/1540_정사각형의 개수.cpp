#include <stdio.h>
int N, a, t, c;

void solve() {
	if (N == 0) return;
	while(++t) {
		for (int j = 0; j < t; j++) {
			a += j;
			if (++c == N) return;
		}
		for (int j = 0; j < t; j++) {
			a += j;
			if (++c == N) return;
		}
	}
}
int main() {
	scanf("%d", &N);
	solve();

	printf("%d", a);
}