#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
int arr[100000];
int ans;
int s[2];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int* begin = arr;
	int* end = arr + N - 1;

	ans = 1e9;

	while (begin < end)
	{
		int sum = *begin + *end;
		if (ans > abs(sum))
		{
			ans = abs(sum);
			s[0] = *begin;
			s[1] = *end;
		}

		if (sum == 0)
		{
			cout << *begin << " " << *end;
			return 0;
		}
		else if (sum < 0)
			begin++;
		else
			end--;
	}

	cout << s[0] << " " << s[1];

	return 0;
}