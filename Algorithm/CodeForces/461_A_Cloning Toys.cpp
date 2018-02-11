#include <iostream>

using namespace std;

int x, y;
int tmp;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> x >> y;

	int tmp = y - 1;

	if (y == 1)
	{
		if (x != 0)
		{
			cout << "No";
			return 0;
		}
	}

	if (x < tmp || y == 0) 
	{
		cout << "No";
		return 0;
	}

	if ((x - tmp) % 2)
		cout << "No";
	else
		cout << "Yes";

	return 0;
}