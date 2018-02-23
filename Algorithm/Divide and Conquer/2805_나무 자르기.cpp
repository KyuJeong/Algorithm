#include <iostream>
using namespace std;

int N, M;
int height[1000000];
int l, r, m;
int max_height;
long long sum_of_cutted_tree;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> height[i];
		if (max_height < height[i])
			max_height = height[i];
	}

	l = 1;
	r = max_height;

	while (l <= r)
	{
		m = l + (r - l) / 2;
		sum_of_cutted_tree = 0;

		for (int i = 0; i < N; i++)
		{
			if (height[i] > m)
				sum_of_cutted_tree += height[i] - m;
		}

		if (sum_of_cutted_tree >= M)
		{
			l = m + 1;
			if (ans < m)
				ans = m;
		}
		else
			r = m - 1;
	}

	cout << ans;


	return 0;
}