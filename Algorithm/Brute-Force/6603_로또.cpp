#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, S;

int main()
{
	std::ios::sync_with_stdio(false);

	while (cin >> k)
	{
		vector <int> v(k);
		vector <int> a;
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i < 6; i++)
		{
			a.push_back(0);
		}

		for (int i = 0; i < k - 6; i++)
		{
			a.push_back(1);
		}

		do 
		{
			for (int i = 0; i < k; i++)
			{
				if (a[i] == 0)
					cout << v[i] << " ";
			}
			cout << "\n";
		} while (next_permutation(a.begin(), a.end()));

		cout << "\n";
	}

	return 0;
}