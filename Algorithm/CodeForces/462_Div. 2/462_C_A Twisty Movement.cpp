#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2001];
int sum[2002];
int ans;
bool flag2;
int a;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	flag2 = true;

	sum[2001] = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (flag2 && arr[i] == 1)
		{
			a = i;
			flag2 = false;
		}
		else if (arr[i] == 2)
			flag2 = true;
	
		sum[a]++;
		ans = max(ans, sum[a]);
	}

	int cur_idx = 2001;
	int pre_idx = 2001;
	if (arr[0] == 2)
		pre_idx = 0;

	flag2 = true;

	for (int i = 0; i < N; i++)
	{
		if (flag2 && arr[i] == 1)
		{
			cur_idx = i;
			flag2 = false;
		}
		else if (!flag2 && arr[i] == 2)
		{
			ans = max(ans, sum[pre_idx] + sum[cur_idx]);
			flag2 = true;
			pre_idx = cur_idx;
		}
		if (i == N - 1 && arr[i] == 1)
			ans = max(ans, sum[pre_idx] + sum[cur_idx]);
	}

	cout << ans;

	return 0;
}