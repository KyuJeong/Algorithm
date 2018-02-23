#include <iostream>
using namespace std;

int K, N;
int lan[10000];
int l = 1;
int max_len;
int r;
int mid;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> lan[i];
		if (max_len < lan[i])
			max_len = lan[i];
	}

	r = max_len;
	int can_make_lan_count;

	while (l <= r)
	{
		mid = l + (r - l) / 2;

		can_make_lan_count = 0;

		for (int i = 0; i < K; i++)
		{
			can_make_lan_count += lan[i] / mid;
		}

		if (can_make_lan_count >= N)
		{
			l = mid + 1;

			if (ans < mid)
				ans = mid;
		}
		else
			r = mid - 1;
	}

	cout << ans;
	return 0;
}