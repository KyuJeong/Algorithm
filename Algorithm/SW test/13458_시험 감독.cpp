#include <iostream>

using namespace std;

int N;
int A[1000001];
int B, C;
long long ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	cin >> B >> C;

	ans += N;

	for (int i = 0; i < N; i++)
	{
		A[i] -= B;
	}

	for (int i = 0; i < N; i++)
	{
		if (A[i] > 0)
			ans += (A[i] - 1) / C + 1;
	}

	cout << ans;

	return 0;
}