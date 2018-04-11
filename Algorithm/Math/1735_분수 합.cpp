#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int A1, B1, A2, B2;

	cin >> A1 >> B1 >> A2 >> B2;

	int bj = A1 * B2 + A2 * B1;
	int bm = B1 * B2;

	int a = bj;
	int b = bm;

	if (a < b)
		swap(a, b);

	while (b > 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	cout << bj / a << " " << bm / a;


	return 0;
}