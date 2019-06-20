#include <iostream>

using namespace std;

int k;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> k;
	if (k >= 37)
	{
		cout << "-1";
		return 0;
	}

	while (k > 0)
	{
		if (k >= 2)
		{
			cout << "8";
			k -= 2;
		}
		else if (k >= 1)
		{
			cout << "6";
			k--;
		}
	}

	return 0;
}