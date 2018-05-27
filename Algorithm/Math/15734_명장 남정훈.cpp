#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int L, R, A;

	cin >> L >> R >> A;

	for (int i = 0; i < A; i++)
	{
		if (L <= R)
			L++;
		else
			R++;
	}

	cout << min(L, R) * 2;

	return 0;
}