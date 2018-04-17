#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cur[3];
int DP_max[2][3];
int DP_min[2][3];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cur[0] >> cur[1] >> cur[2];

		DP_max[1][0] = max(DP_max[0][0], DP_max[0][1]) + cur[0];
		DP_max[1][1] = max({ DP_max[0][0],DP_max[0][1],DP_max[0][2] }) + cur[1];
		DP_max[1][2] = max(DP_max[0][1], DP_max[0][2]) + cur[2];

		DP_min[1][0] = min(DP_min[0][0], DP_min[0][1]) + cur[0];
		DP_min[1][1] = min({ DP_min[0][0],DP_min[0][1],DP_min[0][2] }) + cur[1];
		DP_min[1][2] = min(DP_min[0][1], DP_min[0][2]) + cur[2];

		for (int j = 0; j < 3; j++)
		{
			DP_max[0][j] = DP_max[1][j];
			DP_min[0][j] = DP_min[1][j];
		}
	}

	int _max = max({ DP_max[0][0],DP_max[0][1],DP_max[0][2] });
	int _min = min({ DP_min[0][0],DP_min[0][1],DP_min[0][2] });

	cout << _max << " " << _min;

	return 0;
}