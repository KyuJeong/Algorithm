#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd;
typedef vector<int> vi;

const double pi = acos(-1);

void fft(vcd &f, bool inv) {
	int n = f.size();
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j) swap(f[i], f[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * pi / len * (inv ? -1 : 1);
		cd wlen(cos(ang), sin(ang));

		for (int i = 0; i < n; i += len) {
			cd w(1);
			for (int j = 0; j < len / 2; j++) {
				cd u = f[i + j];
				cd v = f[i + j + len / 2] * w;

				f[i + j] = u + v;
				f[i + j + len / 2] = u - v;

				w *= wlen;
			}
		}
	}

	if (inv) {
		for (int i = 0; i < n; i++) f[i] /= n;
	}
}

void mul(vcd &fa, vcd &fb, vi &res) {
	int n = 1;
	while (n < max(fa.size(), fb.size()))
		n <<= 1;
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);

	for (int i = 0; i < n; i++)
		fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	for (int i = 0; i < n; i++)
		res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vcd X, Y;
	vi S;
	X.resize(2 * N);
	Y.resize(N);
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		X[i] = cd(x, 0.0);
		X[i + N] = cd(x, 0.0);
	}
	for (int i = N - 1; i >= 0; i--) {
		cin >> x;
		Y[i] = cd(x, 0.0);
	}
	mul(X, Y, S);
	int ans = -1;
	for (int i = N; i < 2 * N; i++)
		ans = max(ans, S[i]);

	cout << ans;
}