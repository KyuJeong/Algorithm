#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
	while (b > 0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
	}

	return a;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	int gcd = GCD(N, M);

	for (int i = 1; i * i <= gcd; i++)
	{
		if (gcd % i == 0)
		{
			cout << i << " " << N / i << " " << M / i << "\n";
			int div = gcd / i;
			if(div != i)
				cout << div << " " << N / div << " " << M / div << "\n";
		}
	}

	return 0;
}