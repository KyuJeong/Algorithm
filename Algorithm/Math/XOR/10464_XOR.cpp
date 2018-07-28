#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		a--;

		int digit = 0;
		while ((1 << ++digit) <= b);
		digit--;

		int A[31] = { 0 };
		int B[31] = { 0 };

		for (int i = digit; i >= 1; i--)
		{
			int div = 1 << i;
			if ((a / div) & 1 && !((a % div) & 1))
				A[i] = 1;
			if ((b / div) & 1 && !((b % div) & 1))
				B[i] = 1;
		}

		if (a % 4 == 1 || a % 4 == 2)
			A[0] = 1;
		if (b % 4 == 1 || b % 4 == 2)
			B[0] = 1;

		int ans = 0;
		for (int i = digit; i >= 0; i--)
			if (A[i] ^ B[i] == 1)
				ans |= (1 << i);

		cout << ans << "\n";
	}
	return 0;
}