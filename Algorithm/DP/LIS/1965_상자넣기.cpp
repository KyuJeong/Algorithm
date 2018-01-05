#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	int box[1000] = { 0 };
	int DP[1000] = { 0 };

	int max = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> box[i];
		DP[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (box[i] > box[j] && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		}
		if (max < DP[i])
			max = DP[i];
	}

	cout << max;

	return 0;
}