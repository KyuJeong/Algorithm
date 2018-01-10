#include <iostream>
#include <cmath>

using namespace std;

int n, m;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	int b = pow(2, n);

	cout << m % b;

	return 0;
}