#include <iostream>

using namespace std;

int N, A, B, C, T;
int t[1001];
int ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> A >> B >> C >> T;

	for (int i = 0; i < N; i++)
		cin >> t[i];

	if (B >= C)
	{
		ans = N * A;
	}
	else
	{
		int dif = C - B;
		for (int i = 0; i < N; i++)
		{
			ans += A + (T - t[i]) * dif;
		}
	}

	cout << ans;


	return 0;
}