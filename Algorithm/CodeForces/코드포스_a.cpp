#include <iostream>

using namespace std;

long long A, B;
long long x, y, z;
long long blue, yellow;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> A >> B >> x >> y >> z;

	yellow = (x * 2) + y;
	blue = y + (z * 3);

	long long need_blue = 0;
	long long need_yellow = 0;
	if (yellow - A < 0)
		need_yellow = 0;
	else
		need_yellow = yellow - A;

	if (blue - B < 0)
		need_blue = 0;
	else
		need_blue = blue - B;

	cout << need_yellow + need_blue;
	return 0;
}