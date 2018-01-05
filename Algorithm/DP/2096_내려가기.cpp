#include <iostream>
#include <algorithm>
using namespace std;

int num[3];
int maxDP[3];
int minDP[3];
int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> num[j];
		}
		maxDP[0] = max(maxDP[0], maxDP[1]) + num[0];
		maxDP[2] = max(maxDP[1], maxDP[2]) + num[2];
		maxDP[1] = max(maxDP[0] - num[0], maxDP[2] - num[2]) + num[1];

		minDP[0] = min(minDP[0], minDP[1]) + num[0];
		minDP[2] = min(minDP[1], minDP[2]) + num[2];
		minDP[1] = min(minDP[0] - num[0], minDP[2] - num[2]) + num[1];
	}

	cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << " " << min(min(minDP[0], minDP[1]), minDP[2]);

	return 0;
}