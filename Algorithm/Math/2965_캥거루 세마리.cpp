#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int A[3];
int cnt;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> A[0] >> A[1] >> A[2];

	while (A[2] - A[0] > 2)
	{
		int sub_1 = A[1] - A[0];
		int sub_2 = A[2] - A[1];
		if (sub_1 >= sub_2)
			A[2] = A[1] - 1;
		else
			A[0] = A[2] - 1;

		cnt++;
		sort(A, A + 3);
	}

	cout << cnt;

	return 0;
}