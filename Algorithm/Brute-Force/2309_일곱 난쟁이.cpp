#include <iostream>
#include <algorithm>

using namespace std;

int height[9];
int arr[9];
int ans[7];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
	}

	arr[7] = 1;
	arr[8] = 1;

	do
	{
		int sum = 0;
		for (int i = 0; i < 9; i++)
		{
			if (arr[i] == 0)
				sum += height[i];
		}

		if (sum == 100)
		{
			int idx = 0;
			for (int i = 0; i < 9; i++)
			{
				if (arr[i] == 0)
					ans[idx++] = height[i];
			}
		}
	} while (next_permutation(arr, arr + 9));

	sort(ans, ans + 7);

	for (int i = 0; i < 7; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}