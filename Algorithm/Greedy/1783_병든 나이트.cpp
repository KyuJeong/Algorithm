#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int can_visit;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	if (N == 1)
		can_visit = 1;
	else if (N == 2)
		can_visit = min(4, (M + 1) / 2);
	else
	{
		if (M <= 4)
			can_visit = M;
		else if (M == 5)
			can_visit = 4;
		else
			can_visit = M - 2;
	}

	cout << can_visit;
	return 0;
}