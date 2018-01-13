#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int T;
int a1, a2, b1, b2, r1, r2;
double d;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> a1 >> b1 >> r1 >> a2 >> b2 >> r2;
		if (r1 < r2)
		{
			swap(r1, r2);
		}

		d = sqrt(pow(a2 - a1, 2) + pow(b2 - b1, 2));

		if (d == 0)
		{
			if (r1 == r2)
				cout << "-1\n";
			else
				cout << "0\n";
		}

		else
		{
			if (d == (r1 + r2) || d == (r1 - r2))
				cout << "1\n";
			else if (d > (r1 - r2) && d < (r1 + r2))
				cout << "2\n";
			else
				cout << "0\n";
		}
	}


	return 0;
}