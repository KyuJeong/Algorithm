#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k = 1;

int main()
{
	std::ios::sync_with_stdio(false);

	while (k != 0)
	{
		cin >> k;

		vector <int> arr(k);

		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}

		vector <int> v;

		for (int i = 0; i < 6; i++)
		{
			v.push_back(1);
		}

		for (int i = 0; i < k - 6; i++)
		{
			v.push_back(0);
		}

		do
		{
			for (int i = 0; i < k; i++)
			{
				if (v[i] == 1)
					cout << arr[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(v.begin(), v.end()));

		cout << "\n";
	}



	return 0;
}