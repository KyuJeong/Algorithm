#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vii;

int A[4001]; int B[4001];
int C[4001]; int D[4001];
int n;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	vii a(n * n);
	vii b(n * n);

	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a[idx++] = A[i] + B[j];
	}

	idx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			b[idx++] = C[i] + D[j];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	n *= n;

	int L = 0;
	int R = n - 1;
	ll ans = 0;
	while (L < n && R >= 0)
	{
		ll cnt_a = 0; ll cnt_b = 0;
		if (a[L] + b[R] == 0)
		{
			ll num_a = a[L]; ll num_b = b[R];
			while (L < n && a[L] == num_a)
			{
				cnt_a++;
				L++;
			}
			while (R >= 0 && b[R] == num_b)
			{
				cnt_b++;
				R--;
			}
			ans += cnt_a * cnt_b;
		}
		else if (a[L] + b[R] < 0)
			L++;
		else
			R--;
	}

	cout << ans;

	return 0;
}