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
	while (n < fa.size() + fb.size())
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

	string A, B;
	cin >> A >> B;

	vcd X, Y;
	vi S;

	for (int i = A.size() - 1; i >= 0; i--)
		X.push_back(cd(A[i] - '0', 0.0));

	for (int i = B.size() - 1; i >= 0; i--)
		Y.push_back(cd(B[i] - '0', 0.0));

	mul(X, Y, S);
	for (int i = 0; i < S.size() - 1; i++) {
		S[i + 1] += S[i] / 10;
		S[i] %= 10;
	}

	int cnt = S.size() - 1;
	while (S[cnt] == 0) {
		cnt--;
		if (cnt == 0) break;
	}

	for (int i = cnt; i >= 0; i--) cout << S[i];

}