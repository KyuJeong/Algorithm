#include <bits/stdc++.h>

using namespace std;

int N, T;
int tmp, sum;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> T;

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (sum + tmp > T)
			break;
		
		sum += tmp;
		cnt++;
	}

	cout << cnt;
	

	return 0;
}