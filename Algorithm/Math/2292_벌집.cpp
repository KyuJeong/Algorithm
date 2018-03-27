#include <iostream>

using namespace std;

int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	int cnt = 1;
	int add = 0;
	int idx = 1;

	while (1)
	{
		cnt += add;

		if (cnt >= N)
			break;
		add += 6;
		idx++;
	}

	cout << idx;

	return 0;
}