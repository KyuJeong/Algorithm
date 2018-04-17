#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int arr[100001];
int _min = 1e9;
int s;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> S;

	cin >> arr[0];
	s = arr[0];

	for (int i = 1; i < N; i++)
	{
		cin >> arr[i];
		s += arr[i];
		if (arr[i] >= S)
		{
			cout << "1";
			return 0;
		}	
	}

	if (s < S)
	{
		cout << "0";
		return 0;
	}

	int l = 0;
	int r = 1;
	int sum = arr[0] + arr[1];

	while (r < N)
	{
		if (sum < S)
		{
			r++;
			sum += arr[r];
		}
		else
		{
			_min = min(_min, r - l + 1);
			if (sum - arr[l] >= S)
			{
				sum -= arr[l];
				l++;
			}
			else
			{
				r++;
				sum += arr[r];
			}
		}
	}

	cout << _min;

	return 0;
}