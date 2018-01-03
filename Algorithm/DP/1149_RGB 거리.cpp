#include <iostream>
#include <algorithm>

using namespace std;

int N;
int R, G, B;
int DP[3];
int DP_nxt[3];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> R >> G >> B;
		DP_nxt[0] = min(DP[1], DP[2]) + R;
		DP_nxt[1] = min(DP[0], DP[2]) + G;
		DP_nxt[2] = min(DP[0], DP[1]) + B;

		for (int j = 0; j < 3; j++)
			DP[j] = DP_nxt[j];
	}

	cout << *min_element(DP, DP + 3);

	return 0;

}