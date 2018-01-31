#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int sum, _min;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = floor(sqrt(M)); i * i >= N; i--)
	{
		sum += i * i;
		_min = i * i;
	}

	if (sum == 0)
		cout << "-1";
	else
		cout << sum << "\n" << _min;

	return 0;
}