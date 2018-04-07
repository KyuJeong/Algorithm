#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int N;
		cin >> N;

		int tmp;
		vector <int> perm;
		for (int i = 0; i < 4; i++)
		{
			cin >> tmp;
			for (int j = 0; j < tmp; j++)
			{
				perm.push_back(i);
			}
		}

		vector <int> num(N);
		for (int i = 0; i < N; i++)
		{
			cin >> num[i];
		}

		int _max = -1e9;
		int _min = 1e9;

		do
		{
			int sum = num[0];
			for (int i = 0; i < N - 1; i++)
			{
				if (perm[i] == 0)
					sum += num[i + 1];
				else if (perm[i] == 1)
					sum -= num[i + 1];
				else if (perm[i] == 2)
					sum *= num[i + 1];
				else
					sum /= num[i + 1];
			}
			_max = max(_max, sum);
			_min = min(_min, sum);

		} while (next_permutation(perm.begin(), perm.end()));
		
		int ans = _max - _min;

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}