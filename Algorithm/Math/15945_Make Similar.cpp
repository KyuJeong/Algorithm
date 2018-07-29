#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	int _min = 2e9;
	int _max = -2e9;
	bool plus = false;
	bool minus = false;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (_min > tmp) _min = tmp;
		if (_max < tmp) _max = tmp;
		if (tmp > 0) plus = true;
		if (tmp < 0) minus = true;
	}

	if (plus && minus) cout << "0";
	else
	{
		if (plus)
			cout << min(_min, _max - _min);
		else
			cout << -max(_max, _min - _max);
	}

	return 0;
}