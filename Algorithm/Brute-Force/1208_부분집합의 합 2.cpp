#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;

int N, S;
int arr[41];
ll ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int M = N / 2;
	N = N - M;
	
	vi A(1 << N);
	vi B(1 << M);

	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
				A[i] += arr[j];
		}
	}

	for (int i = 0; i < (1 << M); i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i & (1 << j))
				B[i] += arr[j + N];
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int L = 0;
	int R = B.size() - 1;

	while (L < A.size() && R >= 0)
	{
		ll cnt_a = 0; ll cnt_b = 0;

		if (A[L] + B[R] == S)
		{
			int num_a = A[L];
			int num_b = B[R];
			while (L < A.size() && num_a == A[L])
			{
				cnt_a++;
				L++;
			}
			while (R >= 0 && num_b == B[R])
			{
				cnt_b++;
				R--;
			}
			ans += cnt_a * cnt_b;
		}
		else if (A[L] + B[R] < S)
			L++;
		else
			R--;
	}

	if (S == 0) ans--;
	cout << ans;

	return 0;
}