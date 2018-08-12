#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;

	for (int i = L; i <= 100; i++)
	{
		if (i & 1)
		{
			if (N % i == 0)
			{
				if ((N / i) - (i / 2) < 0) continue;
				for (int j = 0; j < i; j++)
					cout << j + (N / i) - (i / 2) << " ";
				return 0;
			}
		}
		else
		{
			if ((N + i / 2) % i == 0)
			{
				if ((N / i) - (i / 2) + 1 < 0) continue;
				for (int j = 0; j < i; j++)
					cout << j + (N / i) - (i / 2) + 1 << " ";
				return 0;
			}
		}
	}

	cout << "-1";
	return 0;
}